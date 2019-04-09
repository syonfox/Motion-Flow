//
// Created by syonfox on 07/03/19.
//

#include <Thor/Vectors.hpp>
#include "engine.hpp"
#include "motion.hpp"
#include <iostream>

bool Engine::showDebugWindow = false;
std::vector<Font> Engine::Fonts;

Font& Engine::findFont(const std::string &name) {
    for(int i=0; i< Engine::Fonts.size(); i++) {
        //std::cout << Engine::Fonts[i].name << std::endl;
        if(name == Engine::Fonts[i].name)
            return Engine::Fonts[i];
    }
    std::cerr << "ERROR: Invalid name Font not loaded: '" << name<< "'"<< std::endl;
    exit(-1);
}

Engine::Engine(sf::Vector2u ws):
    slope(10,4000,3000)
{
    windowSize = ws;

    camera = sf::View( sf::FloatRect( sf::Vector2f(0,0), sf::Vector2f((float) ws.x, (float) ws.y) ) );

    skyColorDay = sf::Color(135, 206, 235, 256);
    skyColorDusk = sf::Color(200, 50, 50);
    skyColorNight = sf::Color(0, 0, 0);
    skyInc = 1;
    skyDelay = 1;
    highscore = 0;

    barWidth = 20;
    barPadding = 50;
    sunBar = sf::VertexArray(sf::TrianglesStrip, 6);
    sunBar[0] = sf::Vertex(sf::Vector2f(barPadding,barPadding), skyColorDay);
    sunBar[1] = sf::Vertex(sf::Vector2f(barPadding+barWidth,barPadding), skyColorDay);
    sunBar[2] = sf::Vertex(sf::Vector2f(barPadding,windowSize.y/2), skyColorDusk);
    sunBar[3] = sf::Vertex(sf::Vector2f(barPadding+barWidth,windowSize.y/2), skyColorDusk);
    sunBar[4] = sf::Vertex(sf::Vector2f(barPadding,windowSize.y-barPadding), skyColorNight);
    sunBar[5] = sf::Vertex(sf::Vector2f(barPadding+barWidth,windowSize.y-barPadding), skyColorNight);

    //sunTexture.loadFromFile("../res/sun_shiny.png");
    sunTexture.loadFromFile("../res/toon_sun.png");

    sunSprite.setTexture(sunTexture);
    //sunSprite.setScale(0.25,0.25);

    sunSprite.setTextureRect(sf::IntRect(0, 0, sunTexture.getSize().x, sunTexture.getSize().y));
    //sunSprite.setPosition(barPadding+(barWidth/2)-sunTexture.getSize().x/2, 500-sunTexture.getSize().y/2);

    restart();
}

void Engine::restart() {
    state = State::PLAY;
    isPaused = false;
    player.restart();
    skySetting = 10;
    skyThreshold = 400;
    skyTimer = skyDelay;
    camera.setSize(  sf::Vector2f(windowSize.x, windowSize.y) );
    slope.restart();

}
void Engine::pause() {
    isPaused = true;
    state = State::PAUSE;
    player.pause();
}

void Engine::play() {
    isPaused = false;
    state = State::PLAY;
    player.play();
}

void Engine::updateSun() {
    float y = windowSize.y - barPadding- (sunTexture.getSize().y/2);
    y -= skySetting * (windowSize.y-(2*barPadding))/10;
    float x = barPadding+(barWidth/2)-sunTexture.getSize().x/2;
    sunSprite.setPosition(x,y);
}

void Engine::updateSkyColor(){

    if(skySetting<0 || skySetting >10) {
        //std::cerr << "Warrning: Invaled Sky Setting setting it to within bounds";
        if (skySetting < 0) {
            skySetting = 0;
            pause();
            state = State::GAMEOVER;
            //state = State::GAMEOVER;
        } else {
            skySetting = 10;
        }
    }
    if(skySetting <= 5){
        skyColor = blendColor(skyColorDusk, skyColorNight, (skySetting/5));
    }else{
        skyColor = blendColor(skyColorDay, skyColorDusk, ((skySetting-5)/5));
    }



}
sf::Color Engine::blendColor(sf::Color c1, sf::Color c2, float blend ){

    return sf::Color(
            c1.r*blend + c2.r*(1-blend),
            c1.g*blend + c2.b*(1-blend),
            c1.b*blend + c2.g*(1-blend),
            c1.a*blend + c2.a*(1-blend)
        );

}

void Engine::update(sf::Time dt) {
    if(state == State::PLAY) {
        slope.update(dt, player.getPos());
        player.update(dt, slope);

        updateSkyColor(); // if thisd is dont before sounds are unpaused when player update is called
        updateSun();
        if(!lockSky) {
        if(player.getVel().x < skyThreshold) {
            skySetting-=dt.asSeconds()*(1-(player.getVel().x/skyThreshold));
        }
        else {
            skySetting+=dt.asSeconds() * ((player.getVel().x- skyThreshold)/skyThreshold);
        }

            skyTimer -= dt.asSeconds();
            if (skyTimer < 0) {
                skyTimer = skyDelay - skyTimer;
                skyThreshold += skyInc;
            }
        }
    }

}

void Engine::handleEvent(sf::Event &e) {
    if (e.type == sf::Event::KeyPressed)
    {
        if(e.key.code == sf::Keyboard::P) {
            isPaused = !isPaused;
            if(isPaused)
                 pause();
            else if(state == State::PAUSE){
                play();
            }
        }
        if(e.key.code == sf::Keyboard::Escape) {
            state = State::GAMEOVER;

        }
        else if(e.key.code == sf::Keyboard::A) {

        }
        else if(e.key.code == sf::Keyboard::D) {

        }

    }
    if (e.type == sf::Event::KeyReleased)
    {
        if(e.key.code == sf::Keyboard::W) {

        }
        else if(e.key.code == sf::Keyboard::A) {

        }
        else if(e.key.code == sf::Keyboard::D) {

        }

    }
    if (e.type == sf::Event::Resized) {
        windowSize.x  = e.size.width;
        windowSize.y = e.size.height;
    };
}

void Engine::render(sf::RenderWindow &window) {
    window.clear(skyColor);
    gui();

    if(state == State::PLAY || state == State::PAUSE) {
        float lenth = thor::length(player.getVel());
        camera.setCenter(player.getPos());
        //lenth = 400;
        sf::Vector2f targetSize = sf::Vector2f(windowSize.x + (windowSize.x * lenth) / 400,
                                               windowSize.y + (windowSize.y * lenth) / 400);
        sf::Vector2f size = camera.getSize();
        if (size.x < targetSize.x) {
            size.x += windowSize.x / 1000.f;
        } else {
            size.x -= windowSize.x / 1000.f;
        }
        if (size.y < targetSize.y) {
            size.y += windowSize.y / 1000.f;
        } else {
            size.y -= windowSize.y / 1000.f;
        }
        camera.setSize(size);



        window.setView(camera);
        draw(window);
        window.setView(window.getDefaultView());

        window.draw(sunBar);
        window.draw(sunSprite);

        ImGui::Begin("Score", NULL, 0 | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground |
                                    ImGuiWindowFlags_NoBringToFrontOnFocus);

        ImGui::PushFont(Engine::findFont("tusj_big").imfont);
        //ImGui::SetWindowFontScale(2);
        ImGui::SetWindowPos(ImVec2(150, windowSize.y-150));
        ImGui::SetWindowSize(ImVec2(500, 200));
        ImGui::TextColored(sf::Color::Black, "Score:    %d", player.getScore());
        ImGui::TextColored(sf::Color::Black,"Air Time: %.2f", player.getAirTime());
        ImGui::TextColored(sf::Color::Black, "Combo:   x%d", player.getCombo());

        ImGui::PopFont();
        ImGui::End();

    }
    if(state == State::PAUSE) {
        pasueDraw(window);
    }

    if(state == State::MAINMENU) {
        mainMenuDraw(window);
    }

    if(state == State::GAMEOVER) {
        gameoverDraw(window);
    }


}

void Engine::draw(sf::RenderWindow &window) {
    slope.render(window);
    player.render(window);
}

void Engine::gui() {
    if(showDebugWindow) {
        ImGui::Begin("Debug");

        if (ImGui::CollapsingHeader("Engine")) {
            if(ImGui::Button("Restart player")) {
                player.restart();
            }
            ImGui::SliderFloat("Sky Color", &skySetting, 0, 10,"%.5f", 1.f);
            ImGui::SliderFloat("Sky Threshold",&skyThreshold, 0, 1000,"%.5f", 1.f );
            ImGui::Checkbox("Lock Sun", &lockSky);
            ImGui::Text("Engine Info");
            ImGui::Text("Game State: %d", state);
            if (ImGui::CollapsingHeader("Camera")) {
                ImGui::Text("Camera Info");
                ImGui::Text("Pos(%f, %f)", camera.getCenter().x, camera.getCenter().y);
                ImGui::Text("Size(%f, %f)", camera.getSize().x, camera.getSize().y);
            }


        }

        if (ImGui::CollapsingHeader("Slope")) {
            ImGui::Text("Engine Info");
            ImGui::Checkbox("Fill in Slope", &slope.fillSlope);


        }
        ImGui::End();
    }
}

void Engine::pasueDraw(sf::RenderWindow &window) {
//    ImGuiWindowFlags window_flags = 0;
//    window_flags |= ImGuiWindowFlags_NoTitleBar;
//    window_flags |= ImGuiWindowFlags_NoScrollbar;
//    window_flags |= ImGuiWindowFlags_MenuBar;
//    window_flags |= ImGuiWindowFlags_NoMove;
//    window_flags |= ImGuiWindowFlags_NoResize;
//    window_flags |= ImGuiWindowFlags_NoCollapse;
//    window_flags |= ImGuiWindowFlags_NoNav;
//    window_flags |= ImGuiWindowFlags_NoBackground;
//    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
    ImGui::Begin("Pause Menu", NULL, 0 | ImGuiWindowFlags_NoDecoration);
//    ImGuiStyle style = ImGui::GetStyle();
//    style.FrameRounding ;
    ImVec2 size(230 , 200);
    ImVec2 pos(windowSize.x/2 - size.x/2, windowSize.y/2 - size.y/2);
    ImGui::SetWindowPos(pos);
    ImGui::SetWindowSize(size);


    ImGui::SetWindowFontScale(5);
    ImGui::Text("PAUSED");

    ImGui::SetWindowFontScale(1);
    if(ImGui::Button("Play",ImVec2(100,50))) {
//            isPaused = !isPaused;
//            if(isPaused) state = State::PAUSE;
//            else if(state == State::PAUSE){
//                state = State::PLAY;
//            }
        play();
    }
    ImGui::SameLine();
    if(ImGui::Button("Main Menu",ImVec2(100,50))) {
        restart();
        pause();
        state = State::MAINMENU;
    }

    ImGui::End();



}

void Engine::mainMenuDraw(sf::RenderWindow &window) {

    window.clear(sf::Color::Black);
      ImGui::Begin("Main Menu", NULL, 0 | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove| ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoBackground);
//    ImGuiStyle style = ImGui::GetStyle();
//    style.FrameRounding ;
    ImVec2 size(350 , 500);
    ImVec2 pos(100, windowSize.y/2);
    ImGui::SetWindowPos(pos);
    ImGui::SetWindowSize(size);


    //windowSize = window.getSize();

    ImGui::SetWindowFontScale(5);

    ImGui::Text("Main Menu");

    ImGui::SetWindowFontScale(1);
    if(ImGui::Button("Play",ImVec2(330,50))) {
        isPaused = false;
        state = State::PLAY;
    }

    player.volumeMenu();

    ImGui::End();

}

void Engine::gameoverDraw(sf::RenderWindow &window) {

    window.clear(sf::Color::Black);
      ImGui::Begin("Game Over", NULL, 0 | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove| ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoBackground);
//    ImGuiStyle style = ImGui::GetStyle();
//    style.FrameRounding ;
    ImVec2 btnSize(310, 50);
    ImVec2 size(windowSize.x , windowSize.y);
    ImVec2 pos(windowSize.x/2 - btnSize.x/2,windowSize.y/2);
    ImGui::SetWindowPos(pos);
    ImGui::SetWindowSize(size);


    ImGui::SetWindowFontScale(5);

    ImGui::Text("Game Over");
    ImGui::SetWindowFontScale(2);
    ImGui::Text("Score: %d", player.getScore());

    if (player.getScore() >= highscore) {
        highscore = player.getScore();
    }
    ImGui::Text("High Score: %d" , highscore );
    ImGui::SetWindowFontScale(1);
//    if(ImGui::Button("Contine",btnSize)) {
//        play();
//    }


    if(ImGui::Button("Try Again",btnSize)) {
        restart();
    }

    if(ImGui::Button("Main Menu",btnSize)) {


        restart();
        pause();
        state = State::MAINMENU;
    }

    ImGui::End();

}