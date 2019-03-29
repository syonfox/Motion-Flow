//
// Created by syonfox on 09/03/19.
//

#include <cmath>
#include <SFML/Window/Keyboard.hpp>
#include <Thor/Vectors.hpp>
#include <imgui-sfml/imgui.h>
#include "player.hpp"

Player::Player():
pos(010,010),
vel(0,0),
acc(0,0),
color(sf::Color::Red),
skiColor(sf::Color::Green),
bodyColor(sf::Color::Red),
scarfColor(sf::Color::Blue),
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

    int len = 20;
    ski = sf::VertexArray(sf::TrianglesStrip,6);
    ski[0] = sf::Vertex(sf::Vector2f(-len,0), skiColor);
    ski[1] = sf::Vertex(sf::Vector2f(-len,-3), skiColor);
    ski[2] = sf::Vertex(sf::Vector2f(len-5,0), skiColor);
    ski[3] = sf::Vertex(sf::Vector2f(len-5,-3), skiColor);
    ski[4] = sf::Vertex(sf::Vector2f(len,-3), skiColor);
    ski[5] = sf::Vertex(sf::Vector2f(len-2,-10), skiColor);
//    ski.setPoint(0, sf::Vector2f(-20,0));
//    ski.setPoint(1, sf::Vector2f(15,0));
//    ski.setPoint(2, sf::Vector2f(20,-5));
//    ski.setPoint(3, sf::Vector2f(20,-10));
//    ski.setPoint(4, sf::Vector2f(15,-5));
//    ski.setPoint(5, sf::Vector2f(-20,-5));
//    ski.setFillColor(skiColor);

    scarfLength = 100;
    //std::deque<sf::Vector2f> scarfPoints;
    //scarf= sf::VertexArray(sf::LinesStrip 10)

    bodyWidth = 20;
    bodyHeight = 60;
    body = sf::ConvexShape(6);
    genBody(bodyWidth, bodyHeight);


}



void Player::genBody(int width, int hight){
    body.setPoint(0, sf::Vector2f(-width/2,0));
    body.setPoint(1, sf::Vector2f(width/4,0));
    body.setPoint(2, sf::Vector2f(width/2,-hight+hight/4));
    body.setPoint(3, sf::Vector2f(width/2,-hight+hight/8));
    body.setPoint(4, sf::Vector2f(0, -hight));
    body.setPoint(5, sf::Vector2f(-width/2,-hight+hight/8));
    body.setFillColor(bodyColor);
}

void Player::updateScarf() {
    sf::Vector2f p = transform.transformPoint(sf::Vector2f(0,-bodyHeight+bodyHeight/4));
    if(thor::length( p - scarfPoints.front()) > 2){
        scarfPoints.push_front(p);
    }


    std::deque<sf::Vector2f>::iterator it = scarfPoints.begin();
    if(scarfPoints.size() < 2){
        return;
    }
    float len = 0;
    for(it = scarfPoints.begin(); it != scarfPoints.end(); it++){
        it[0].y +=1; //make the scarf fall down
        len+= (thor::length( it[0] - it[1])); //calc length of a segment
        if(len >= scarfLength){
            break;
        }
    }

    while (scarfPoints.end() != it){
        scarfPoints.pop_back();
    }

}

void Player::update(sf::Time dt, Slope s){
    float t = dt.asSeconds();
    //c = 0.01
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->applyForce(sf::Vector2f(-100*mass,0));

        //acc.x -= 50;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        //acc.x += 50;
        this->applyForce(sf::Vector2f(100*mass,0));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        //this->applyForce(sf::Vector2f(0, -100*mass));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

    }

    applyForce(sf::Vector2f(0,g*mass));



    sf::Vector2f mtv, p ,Fn;

    //the point in world cords
    p = transform.transformPoint(sf::Vector2f(0,0));


    float slopeAngle = thor::polarAngle(sf::Vector2f(1, -s.slope(p.x)));
    if(vel != sf::Vector2f(0,0))
        velAngle = thor::polarAngle(vel);

    //colisions should be done after the physics update since if done before the player can
    // sink into the ground a little bit
    if(s.colisionPoint(p, mtv) && mtv != sf::Vector2f(0,0)){
        if(debugDraw) {
            debugLines[0] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Green);
            debugLines[1] = sf::Vertex(mtv * 10.f, sf::Color::Green);
        }
        pos+=mtv; //move the player out of the ground

        //angle = thor::polarAngle(mtv)+90;
        aoi = fabs(velAngle - slopeAngle);

        thor::setPolarAngle(vel, slopeAngle);

        if(aoi > 20){
            //You lose
            vel.x *= (1-(aoi)/180);
            vel.y *= (1-(aoi)/180);
        }

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

        if(inAir) {
            if(aoi < 20 ){
            //speed boost
                vel.x *=2;
                vel.y *=2;
            }
        }

        airTime = 0;
        inAir = false;
    } else {
        airTime += t;
    }

    if(airTime > 0.5)
        inAir = true;




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


    if(thor::squaredLength(vel) > 10 ) {
        angle = velAngle;
    } else {
        angle = slopeAngle;
    }


    if(debugDraw) {
        debugLines[4] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Yellow);
        debugLines[5] = sf::Vertex(vel, sf::Color::Yellow);
    }
    //recalculate each time since it would have to anyway and this way there is no error
    //the cost is storing the original polygon
    transform = sf::Transform();
    transform.translate(pos);
    transform.rotate(angle);

    updateScarf();

}
void Player::render(sf::RenderWindow &window){



    scarf.clear();
    scarf.resize(scarfPoints.size());
    int size = scarfPoints.size();
    for(int i =size-1; i >= 0; i--){
        scarf[i]= sf::Vertex(scarfPoints[i], scarfColor);
    }


    window.draw(scarf);
    //window.draw(shape,transform);
    //transform.rotate(velAngle);
    window.draw(body,transform);
    //transform.rotate(angle);
    window.draw(ski,transform);
    if(debugDraw) {
        transform.rotate(-velAngle);
        window.draw(debugLines, transform);
    }

    if(debugWindow){

        ImGui::Begin("Debug");
        if (ImGui::CollapsingHeader("Player")) {
//            ImGui::Text("Player Info");
//            ImGui::SameLine();
            ImGui::Checkbox("Draw Debug Stuff", &debugDraw);
            ImGui::Text("Position:(%f,%f) \t angle: %f", pos.x, pos.y, angle);
            ImGui::Text("Velocity:(%f,%f)", vel.x, vel.y);

            ImGui::Text("Vel Angle: %f \t aoi: %f", velAngle, aoi);
            ImGui::SliderFloat("Gravity Constant", &g, 0,1000);
            ImGui::SliderFloat("Drag Constant", &c, 0, 1,"%.5f", 2.f);
            ImGui::SliderInt("Scarf Length", &scarfLength, 10, 1000 );
            ImGui::Text("In Air: %d \t Air Time: %f", inAir, airTime);

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
