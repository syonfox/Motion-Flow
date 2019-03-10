//
// Created by syonfox on 09/03/19.
//

#include <cmath>
#include <SFML/Window/Keyboard.hpp>
#include "player.hpp"
Player::Player():
pos(0,0),
vel(0,0),
acc(0,0),
color(sf::Color::Red)
{
    mass = 1;
    rotation = 0;
    angle = 0;
    g = 10;

    shape = sf::ConvexShape(3);
    shape.setPoint(0, sf::Vector2f(-20, 0));
    shape.setPoint(1, sf::Vector2f(20, 0));
    shape.setPoint(2, sf::Vector2f(0, -50));
    shape.setFillColor(color);
}
    void Player::update(sf::Time dt, Slope s){
    float t = dt.asSeconds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->applyForce(sf::Vector2f(-100,0));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->applyForce(sf::Vector2f(100,0));
    }


    bool applyGravity = true;

    float intersectDeapth = s.colisionPoint(transform.transformPoint(shape.getPoint(0)));
    if(intersectDeapth < 0 ){
        rotation++;
        float f = (2*intersectDeapth*mass);
        this->applyForce(sf::Vector2f(0,f));
        pos.y+=intersectDeapth;
        applyGravity = false;
    }

    intersectDeapth = s.colisionPoint(transform.transformPoint(shape.getPoint(1)));
    if(intersectDeapth < 0 ){
        rotation--;
        float f = (2*intersectDeapth*mass);
        this->applyForce(sf::Vector2f(0,f));
        pos.y+=intersectDeapth;
        applyGravity = false;
    }
    if(applyGravity){
        this->applyForce(sf::Vector2f(0,g));
    }

    sf::Vector2f dp =  (vel * t) + (0.5f * acc * (t * t));
    pos += dp;
    vel += acc * t;
    acc.x=0;
    acc.y=0;

    float da = rotation*t;
    angle += da;

    //recalculate each time since it would have to anyway and this way there is no error
    //the cost is storing the original polygon
    transform = sf::Transform();
    transform.translate(pos);
    transform.rotate(angle);

}
void Player::render(sf::RenderWindow &window){


    window.draw(shape,transform);

}

void Player::applyForce(const sf::Vector2f &f) {
    acc += f/mass;
}

const sf::Vector2f &Player::getPos() const {
    return pos;
}

void Player::setPos(const sf::Vector2f &pos) {
    Player::pos = pos;
}

const sf::Vector2f &Player::getVel() const {
    return vel;
}

void Player::setVel(const sf::Vector2f &vel) {
    Player::vel = vel;
}

const sf::Vector2f &Player::getAcc() const {
    return acc;
}

void Player::setAcc(const sf::Vector2f &acc) {
    Player::acc = acc;
}

float Player::getAngle() const {
    return angle;
}

void Player::setAngle(float angle) {
    Player::angle = angle;
}

float Player::getMass() const {
    return mass;
}

void Player::setMass(float mass) {
    Player::mass = mass;
}

float Player::getRotation() const {
    return rotation;
}

void Player::setRotation(float rotation) {
    Player::rotation = rotation;
}
