//
// Created by syonfox on 09/03/19.
//

#include <cmath>
#include <SFML/Window/Keyboard.hpp>
#include <Thor/Vectors.hpp>
#include <imgui-sfml/imgui.h>
#include "player.hpp"

Player::Player():
pos(0,0),
vel(0,0),
acc(0,0),
color(sf::Color::Red),
debugLines(sf::Lines, 6)
{
    debugDraw = true;
    debugWindow = true;
    mass = 10;
    rotation = 0;
    angle = 0;
    g = 100;
    c = 0.01;

    shape = sf::ConvexShape(3);
    shape.setPoint(0, sf::Vector2f(-20, 0));
    shape.setPoint(1, sf::Vector2f(20, 0));
    shape.setPoint(2, sf::Vector2f(0, -50));
    shape.setFillColor(color);
}
    void Player::update(sf::Time dt, Slope s){
    float t = dt.asSeconds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->applyForce(sf::Vector2f(-100*mass,0));
        //acc.x -= 50;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        //acc.x += 50;
        this->applyForce(sf::Vector2f(100*mass,0));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->applyForce(sf::Vector2f(0, -100*mass));
    }

    applyForce(sf::Vector2f(0,g*mass));



    sf::Vector2f mtv, p ,Fn;
    p = transform.transformPoint(sf::Vector2f(0,0));

    //colisions should be done after the physics update since if done before the player can
    // sink into the ground a little bit
    if(s.colisionPoint(p, mtv) && mtv != sf::Vector2f(0,0)){
        if(debugDraw) {
            debugLines[0] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Green);
            debugLines[1] = sf::Vertex(mtv * 10.f, sf::Color::Green);
        }
        pos+=mtv; //move the player out of the ground

        angle = thor::polarAngle(mtv)+90;
        thor::setPolarAngle(vel, angle);

        float scale = force.y/mtv.y;

        Fn.x = -scale*mtv.x;
        if(fabs(angle) > 10){ // this is so that we dont get massive force spoces on slopes close to 0
            if((mtv.x < -0 && Fn.x+force.x > 0) ||(mtv.x > 0 && Fn.x+force.x < 0)){
                scale = force.x/mtv.x;
                Fn.x = -force.x;
            }
        }
        Fn.y = -(scale * mtv.y);

        applyForce(Fn);
        //applyGravity = false;
        //applyForce(sf::Vector2f(-g*mtv.x/mtv.y, 0));
    }

    if(vel != sf::Vector2f(0,0)) { //if there is speed
        float drag = c * thor::squaredLength(vel);
        sf::Vector2f dragF = vel * -1.f;
        thor::setLength(dragF, drag);
        applyForce(dragF);
    }

    if(debugDraw) {
        debugLines[2] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Blue);
        debugLines[3] = sf::Vertex(force * 0.1f, sf::Color::Blue);
    }

    acc += force/mass;
    force.x = 0;
    force.y = 0;
    sf::Vector2f dp =  (vel * t) + (0.5f * acc * (t * t));

    pos += dp;
    vel += acc * t;
//    vel.y*=0.99;
//    vel.x*=0.99;
    acc.x=0;
    acc.y=0;

    float da = rotation*t;
    angle += da;
    if(debugDraw) {
        debugLines[4] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Yellow);
        debugLines[5] = sf::Vertex(vel, sf::Color::Yellow);
    }
    //recalculate each time since it would have to anyway and this way there is no error
    //the cost is storing the original polygon
    transform = sf::Transform();
    transform.translate(pos);
    transform.rotate(angle);

}
void Player::render(sf::RenderWindow &window){


    window.draw(shape,transform);

    if(debugDraw) {
        transform.rotate(-angle);
        window.draw(debugLines, transform);
    }

    if(debugWindow){

        ImGui::Begin("Debug");
        if (ImGui::CollapsingHeader("Player")) {
            ImGui::Text("Player Info");
            ImGui::Text("Position:(%f,%f) \t angle: %f", pos.x, pos.y, angle);
            ImGui::SliderFloat("Gravity Constant", &g, 0,1000);
            ImGui::SliderFloat("Drag Constant", &c, 0, 1,"%.5f", 2.f);

        }

        ImGui::End();
    }


}

void Player::applyForce(const sf::Vector2f &f) {
    force += f;
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
