//
// Created by syonfox on 07/03/19.
//

#ifndef MOTION_FLOW_ENGINE_HPP
#define MOTION_FLOW_ENGINE_HPP

#include "imgui-sfml/imgui.h"
#include "slope.hpp"
#include "player.hpp"
#include "fonts.hpp"
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

enum class State{QUIT,MAINMENU, PAUSE, PLAY, GAMEOVER};

class Engine {
private:
    sf::Vector2u windowSize;
    sf::View camera; //View port intow the game world

    State state; //Curent game state

    bool isPaused = false;

    void pasueDraw(sf::RenderWindow & window);
    void mainMenuDraw(sf::RenderWindow & window);
    void gameoverDraw(sf::RenderWindow & window);


    void gui();
    void draw(sf::RenderWindow & window);

    Slope slope;
    Player player;
    float g;

    float skySetting;
    sf::Color skyColor;
    sf::Color skyColorDay;
    sf::Color skyColorDusk;
    sf::Color skyColorNight;

    float skyThreshold;

    float skyTimer;
    float skyDelay;
    float skyInc;

    void updateSkyColor();
    sf::Color blendColor(sf::Color c1, sf::Color c2, float blend );

    int highscore;




public:

    static bool showDebugWindow;
    static std::vector<Font> Fonts;

    static Font& findFont(const std::string &name);
    Engine(sf::Vector2u windowSize);
    void update(sf::Time dt);
    void restart();
    void pause();
    void play();
    void handleEvent(sf::Event &e);
    void render(sf::RenderWindow &window);



};

#endif //MOTION_FLOW_ENGINE_HPP
