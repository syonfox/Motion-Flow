//
// Created by syonfox on 07/03/19.
//

#include <Thor/Vectors.hpp>
#include "engine.hpp"
#include "motion.hpp"


Engine::Engine(sf::Vector2u ws):
    slope(2,500,1000)
{


    player.setPos(sf::Vector2f(100, 100));
    windowSize = ws;
    camera = sf::View( sf::FloatRect( sf::Vector2f(0,0), sf::Vector2f((float) ws.x, (float) ws.y) ) );



}
void Engine::update(sf::Time dt) {
    if(state != State::PAUSE) {

        slope.update(dt, player.getPos());
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
}

void Engine::draw(sf::RenderWindow &window) {
    slope.render(window);
    player.render(window);
}

void Engine::gui() {
    if(debugWindow) {
        ImGui::Begin("Debug");

        if (ImGui::CollapsingHeader("Engine")) {
            ImGui::Text("Engine Info");
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