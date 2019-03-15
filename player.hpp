//
// Created by syonfox on 09/03/19.
//

#ifndef MOTION_FLOW_PLAYER_HPP
#define MOTION_FLOW_PLAYER_HPP


#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "imconfig.h"
#include "slope.hpp"

class Player {
private:
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f acc;
    sf::Vector2f force;
    float mass;
    float angle;
    float rotation;

    float g;

    sf::Color color;
    sf::ConvexShape shape;

    sf::Transform transform;

    bool debugDraw;
    sf::VertexArray debugLines;


public:
    Player();
    void update(sf::Time dt, Slope s);
    void render(sf::RenderWindow &window);

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

};


#endif //MOTION_FLOW_PLAYER_HPP
