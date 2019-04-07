//
// Created by syonfox on 09/03/19.
//

#ifndef MOTION_FLOW_PLAYER_HPP
#define MOTION_FLOW_PLAYER_HPP


#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Text.hpp>
#include "imconfig.h"
#include "slope.hpp"
#include "motion.hpp"

class Player {
private:
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f acc;
    sf::Vector2f force;
    float mass;
    float angle;
    float velAngle;
    float aoi; //angle of incidence

    float rotation;

    float airTime;
    bool inAir;

    float boostFactor;
    float boostThreshold;
    float boostMax;

    float g; //gravity accelearation
    sf::Vector2f c; //drag coefficient

    sf::Color color;
    sf::ConvexShape shape;

//    sf::ConvexShape body;
//    sf::VertexArray ski;

//    sf::Color bodyColor;
//    sf::Color skiColor;
    int scarfLength;
    sf::VertexArray scarf;
    std::deque<sf::Vector2f> scarfPoints;
    sf::Color scarfColor;

    sf::Texture texture;
    sf::Sprite sprite;

    sf::Text landingText;
    sf::Color textColor;
    sf::Color textOutlineColor;
    float textDecay;
    float textDuration;
    void updateText(float dt);


    void updateSounds();
    void updateVolumes();
    void updateScarf();
    sf::Vector2f scarfPoint;
    //void drawScarf(void);
    sf::Transform transform;

    bool debugDraw;
    sf::VertexArray debugLines;

//    int bodyWidth, bodyHeight;
//    void genBody(int width, int hight);



    Pose pose;
    Pose getControl();

    float score;
    int combo;

    //sounds


    float masterVolume;
    float musicVolume;
    float gameVolume;

    sf::SoundBuffer backgroundSoundBuffer;
    sf::Sound backgroundSound;
    float backgroundBaseVolume;
    sf::SoundBuffer snowSoundBuffer;
    sf::Sound snowSound;
    float snowBaseVolume;
    sf::SoundBuffer crashSoundBuffer;
    sf::Sound crashSound;
    float crashBaseVolume;
    sf::SoundBuffer flySoundBuffer;
    sf::Sound flySound;
    float flyBaseVolume;



public:



    Player();
    void update(sf::Time dt, Slope s);
    void restart();
    void pause();
    void play();
    void render(sf::RenderWindow &window);

    void volumeMenu();

    void applyForce(const sf::Vector2f &f);

    const sf::Vector2f &getPos() const;

    void setPos(const sf::Vector2f &pos);

    const sf::Vector2f &getVel() const;

    void setVel(const sf::Vector2f &vel);

    const sf::Vector2f &getAcc() const;

    void setAcc(const sf::Vector2f &acc);

    float getAngle() const;

    void setAngle(float angle);

    float getMass() const;

    void setMass(float mass);

    float getRotation() const;

    void setRotation(float rotation);

    float getAirTime() const;

    int getScore() const;

    int getCombo() const;

    bool isInAir() const;
};


#endif //MOTION_FLOW_PLAYER_HPP
