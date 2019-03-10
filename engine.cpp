//
// Created by syonfox on 07/03/19.
//

#include "engine.hpp"


Engine::Engine(sf::Vector2u ws):
    slope(1,1000,100)
{
    player.setPos(sf::Vector2f(100, 100));
    windowSize = ws;
    camera = sf::View( sf::FloatRect( sf::Vector2f(0,0), sf::Vector2f((float) ws.x, (float) ws.y) ) );



}
void Engine::update(sf::Time dt) {
    if(state != State::PAUSE) {

        slope.update(dt, sf::Vector2f(0,0));
        player.update(dt, slope);
    }
}

void Engine::handleEvent(sf::Event &e) {
    if (e.type == sf::Event::KeyPressed)
    {
        if(e.key.code == sf::Keyboard::Space) {
            isPaused = !isPaused;
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


    //camera.setCenter(player.getPosition());
    //window.setView(camera);
    draw(window);
    //window.setView(window.getDefaultView());
}

void Engine::draw(sf::RenderWindow &window) {
    slope.render(window);
    player.render(window);
}

void Engine::gui() {
    ImGui::Begin("Debug");

    if (ImGui::CollapsingHeader("Engine")) {
        ImGui::Text("Engine Info");
        if (ImGui::CollapsingHeader("Camera")) {
            ImGui::Text("Camera Info");
            ImGui::Text("Pos(%f, %f)", camera.getCenter().x, camera.getCenter().y);

        }


    }
    ImGui::End();
}