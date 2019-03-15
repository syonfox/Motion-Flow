//
// Created by syonfox on 07/03/19.
//

#ifndef MOTION_FLOW_ENGINE_HPP
#define MOTION_FLOW_ENGINE_HPP

#include "imgui-sfml/imgui.h"
#include "slope.hpp"
#include "player.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

enum class State{QUIT,MAINMENU, PAUSE, PLAY};

class Engine {
private:
    sf::Vector2u windowSize;
    sf::View camera;

    State state = State::PLAY;

    bool isPaused = false;


    void gui();
    void draw(sf::RenderWindow & window);

    Slope slope;
    Player player;
    float g;



public:
    bool debugWindow;

    Engine(sf::Vector2u windowSize);
    void update(sf::Time dt);
    void handleEvent(sf::Event &e);
    void render(sf::RenderWindow &window);


};

#endif //MOTION_FLOW_ENGINE_HPP
