//
// Created by syonfox on 09/03/19.
//

#include <cmath>
#include <SFML/Window/Keyboard.hpp>
#include <Thor/Vectors.hpp>
#include <imgui-sfml/imgui.h>
#include "player.hpp"
#include "engine.hpp"

Player::Player():
pos(010,010),
vel(0,0),
acc(0,0),
color(sf::Color::Red),
textColor(sf::Color::Red),
scarfColor(sf::Color::Red),
debugLines(sf::Lines, 6)
{
    debugDraw = true;
    mass = 10;
    rotation = 0;
    angle = 0;
    g = 100;
    c.x = 0.005;
    c.y = 0.02;


    boostMax = 2;
    boostThreshold = 20;
//    shape = sf::ConvexShape(3);
//    shape.setPoint(0, sf::Vector2f(-20, 0));
//    shape.setPoint(1, sf::Vector2f(20, 0));
//    shape.setPoint(2, sf::Vector2f(0, -50));
//    shape.setFillColor(color);
//
//    int len = 20;
//    ski = sf::VertexArray(sf::TrianglesStrip,6);
//    ski[0] = sf::Vertex(sf::Vector2f(-len,0), skiColor);
//    ski[1] = sf::Vertex(sf::Vector2f(-len,-3), skiColor);
//    ski[2] = sf::Vertex(sf::Vector2f(len-5,0), skiColor);
//    ski[3] = sf::Vertex(sf::Vector2f(len-5,-3), skiColor);
//    ski[4] = sf::Vertex(sf::Vector2f(len,-3), skiColor);
//    ski[5] = sf::Vertex(sf::Vector2f(len-2,-5), skiColor);


    scarfLength = 100;
    //std::deque<sf::Vector2f> scarfPoints;
    //scarf= sf::VertexArray(sf::LinesStrip 10)

//    bodyWidth = 20;
//    bodyHeight = 40;
//    body = sf::ConvexShape(6);
//    genBody(bodyWidth, bodyHeight);


    texture.loadFromFile("../res/penguin.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
    sprite.setPosition(-64, -128);
    scarfPoint = sf::Vector2f(-64+90, -128+106);


    landingText.setFont(Engine::findFont("tusj").sffont);
    landingText.setString("Great");
    landingText.setFillColor(sf::Color::Red);
    landingText.setScale(3,3);
    textDuration = 1;

     backgroundSoundBuffer.loadFromFile("../res/background.wav");
     backgroundSound.setBuffer(backgroundSoundBuffer);
     backgroundSound.setLoop(true);
     backgroundSound.setVolume(60);
     backgroundSound.play();


    snowSoundBuffer.loadFromFile("../res/snow.wav");
    snowSound.setBuffer(snowSoundBuffer);
    snowSound.setLoop(true);
    //snowSound.play();

    crashSoundBuffer.loadFromFile("../res/crash_sound.wav");
    crashSound.setBuffer(crashSoundBuffer);
    crashSound.setPitch(2);
    crashSound.setLoop(false);

    flySoundBuffer.loadFromFile("../res/fly_sound_trimmed.wav");
    flySound.setBuffer(flySoundBuffer);
    flySound.setLoop(false);
}



//void Player::genBody(int width, int hight){
//    body.setPoint(0, sf::Vector2f(-width/2,0));
//    body.setPoint(1, sf::Vector2f(width/4,0));
//    body.setPoint(2, sf::Vector2f(width/2,-hight+hight/4));
//    body.setPoint(3, sf::Vector2f(width/2,-hight+hight/8));
//    body.setPoint(4, sf::Vector2f(0, -hight));
//    body.setPoint(5, sf::Vector2f(-width/2,-hight+hight/8));
//    body.setFillColor(bodyColor);
//}

void Player::updateScarf() {
    sf::Vector2f p = transform.transformPoint(scarfPoint);
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

void Player::updateText(float dt) {
    //landingText.setPosition(0,0);
    if(textDecay > 0) {
        landingText.move(0,-1);
        textColor.a = (textDecay/textDuration)* 255;

        landingText.setFillColor(textColor);
        textDecay-=dt;

    }
}

void Player::updateSounds() {

//    if(inAir && snowSound.getStatus() == sf::Sound::Status::Playing)
//        snowSound.pause();
//
//    if(!inAir && snowSound.getStatus() == sf::Sound::Status::Paused)
//        snowSound.play();

    // how to figure out a bad landing


}

Pose Player::getControl(){
    if(Motion::isRunning()) {
        return Motion::getPose();
    }

    //else use keyboard;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        return Pose::CROUCH;

    int lean = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
       lean--;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
       lean++;

    if(lean == -1)
        return Pose::LEANLEFT;
    if(lean == 1)
        return  Pose::LEANRIGHT;

    return Pose::STAND;
}

void Player::update(sf::Time dt, Slope s){

    score = pos.x;

    float t = dt.asSeconds();
    //c = 0.01
    //the point in world cords
    sf::Vector2f p = transform.transformPoint(sf::Vector2f(0,0));

    updateText(t);

    pose = getControl();
    switch(pose) {
        case Pose::CROUCH:
            if(inAir){
                applyForce(sf::Vector2f(0,3000.f));
            } else {
                sf::Vector2f boostF = vel;
                thor::setLength(boostF, 3000.f);
                applyForce(boostF);


            }
            break;

        case Pose::STAND:
        default:

            break;
    }


    applyForce(sf::Vector2f(0,g*mass));



    sf::Vector2f mtv ,Fn;

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
//        if(aoi > 20){
//            //You lose
//            vel.x *= (1-(aoi)/180);
//            vel.y *= (1-(aoi)/180);
//        }
        if(inAir) {
            if(aoi < boostThreshold) {
                boostFactor = (boostThreshold - aoi) / boostThreshold;
                boostFactor *= (boostMax - 1);
                boostFactor += 1;
            } else {
                boostFactor = 1 - ((aoi - boostThreshold)/(90 - boostThreshold));
            }

            vel.x *= boostFactor;
            vel.y *= boostFactor;

            std::string s = "";
            if(aoi < boostThreshold * 0.25 ){
                s = "Perfect Landing";
                flySound.play();

            } else if(aoi < boostThreshold * 0.5) {
                flySound.play();
                s = "Great Landing";

            } else if (aoi < boostThreshold * 0.75) {
                flySound.play();
                s = "Good Landing";
            }else if (aoi < boostThreshold) {
                s = "Okay Landing";
            } else {
                crashSound.play();
                s = "Bad Landing";
            }


            if(airTime > 5){
                s += "  Big Air";
            }
            landingText.setString(s);
            landingText.setPosition(pos.x, pos.y-100);
            textDecay = textDuration;
        }

        airTime = 0;
        inAir = false;
    } else {
        airTime += t;
    }

    if(airTime > 0.3)
        inAir = true;




    if(vel != sf::Vector2f(0,0)) { //if there is speed
//        float drag = c * thor::squaredLength(vel);
//        sf::Vector2f dragF = vel * -1.f;
//        thor::setLength(dragF, drag);

        sf::Vector2f dragF;
        dragF.x = -c.x * vel.x*vel.x;
        dragF.y = -c.y * vel.y*vel.y;

        if(vel.x < 0)
            dragF.x = -dragF.x;
        if(vel.y < 0)
            dragF.y = -dragF.y;


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

    acc.x=0;
    acc.y=0;

    float da = rotation*t;
    angle += da;


    if(vel.x > 15) {
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
    updateSounds();

}
void Player::render(sf::RenderWindow &window){

    scarf.clear();
    scarf.setPrimitiveType(sf::LinesStrip);
    scarf.resize(scarfPoints.size());
    int size = scarfPoints.size();
    for(int i =size-1; i >= 0; i--){
        scarf[i]= sf::Vertex(scarfPoints[i], scarfColor);
    }

    //window.draw(shape,transform);
    //transform.rotate(velAngle);
    //window.draw(body,transform);
    //transform.rotate(angle);
    //window.draw(ski,transform);

    window.draw(sprite, transform);
    window.draw(scarf);

    window.draw(landingText);

    if(debugDraw) {
        transform.rotate(-velAngle);
        window.draw(debugLines, transform);
        transform.rotate(velAngle);
    }



    if(Engine::showDebugWindow){

        ImGui::Begin("Debug");
        if (ImGui::CollapsingHeader("Player")) {
//            ImGui::Text("Player Info");
//            ImGui::SameLine();
            ImGui::Checkbox("Draw Debug Stuff", &debugDraw);
            ImGui::Text("Position:(%f,%f) \t angle: %f", pos.x, pos.y, angle);
            ImGui::Text("Velocity:(%f,%f)", vel.x, vel.y);

            ImGui::Text("Vel Angle: %f \t aoi: %f", velAngle, aoi);
            ImGui::SliderFloat("Gravity Constant", &g, 0,1000);
            ImGui::SliderFloat("Drag Coefecent X", &c.x, 0, 1,"%.5f", 2.f);
            ImGui::SliderFloat("Drag Coefecent Y", &c.y, 0, 1,"%.5f", 2.f);
            ImGui::SliderInt("Scarf Length", &scarfLength, 10, 1000 );
            ImGui::Text("In Air: %d \t Air Time: %f", inAir, airTime);
            ImGui::SliderFloat("Max Boost Factor", &boostMax, 1, 6,"%.5f", 1.f);
            ImGui::SliderFloat("Threshold Factor", &boostThreshold, 1, 90,"%.5f", 1.f);

             ImGui::Text("Boost Factor: %f", boostFactor);
            ImGui::Text("Pose: %d", pose);
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

float Player::getAirTime() const {
    return airTime;
}

int Player::getScore() const {
    return score;
}

bool Player::isInAir() const {
    return inAir;
}
