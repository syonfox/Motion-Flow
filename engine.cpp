//
// Created by syonfox on 07/03/19.
//

#include <Thor/Vectors.hpp>
#include "engine.hpp"
#include "motion.hpp"


bool Engine::showDebugWindow = true;

Engine::Engine(sf::Vector2u ws):
    slope(1,5000,3000)
{


    player.setPos(sf::Vector2f(100, 100));
    windowSize = ws;
    camera = sf::View( sf::FloatRect( sf::Vector2f(0,0), sf::Vector2f((float) ws.x, (float) ws.y) ) );

    state = State::PLAY;


}
void Engine::update(sf::Time dt) {
    if(state == State::PLAY) {
        slope.update(dt, player.getPos());
        player.update(dt, slope);
    }
}

void Engine::handleEvent(sf::Event &e) {
    if (e.type == sf::Event::KeyPressed)
    {
        if(e.key.code == sf::Keyboard::Space) {
            isPaused = !isPaused;
            if(isPaused) state = State::PAUSE;
            else if(state == State::PAUSE){
                state = State::PLAY;
            }
        }
        if(e.key.code == sf::Keyboard::W) {

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
}

void Engine::render(sf::RenderWindow &window) {
    gui();
    float lenth = thor::length(player.getVel());
    camera.setCenter(player.getPos());
    //lenth = 400;
    sf::Vector2f targetSize = sf::Vector2f(windowSize.x+(windowSize.x*lenth)/400, windowSize.y+(windowSize.y*lenth)/400);
    sf::Vector2f size = camera.getSize();
    if(size.x < targetSize.x){
        size.x +=windowSize.x/1000.f;
    } else {
        size.x -=windowSize.x/1000.f;
    }
    if(size.y < targetSize.y){
        size.y +=windowSize.y/1000.f;
    } else {
        size.y -=windowSize.y/1000.f;
    }
    camera.setSize(size);

    window.setView(camera);
    draw(window);
    window.setView(window.getDefaultView());

    ImGui::Begin("Score", NULL, 0 | ImGuiWindowFlags_NoDecoration |ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoBringToFrontOnFocus );
    ImGui::SetWindowFontScale(2);
    ImGui::SetWindowPos(ImVec2(10,10));
    ImGui::SetWindowSize(ImVec2(500,200));
    ImGui::TextColored(ImColor(0,0,0), "Score:    %d", player.getScore());
    ImGui::Text("Air Time: %.2f", player.getAirTime());

    ImGui::End();


    if(state == State::PAUSE) {
        pasueDraw(window);
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
        isPaused = !isPaused;
            if(isPaused) state = State::PAUSE;
            else if(state == State::PAUSE){
                state = State::PLAY;
            }
    }
    ImGui::SameLine();
    ImGui::Button("Main Menu",ImVec2(100,50));

    ImGui::End();

}