//
// Created by syonfox on 07/03/19.
//

#include <cmath>
#include "slope.hpp"]

double Slope::slopeFunction(double x){
    return 100+ 100*sin(x/50)+(0.8*x);
}
float Slope::colisionPoint(sf::Vector2f p){
    return slopeFunction(p.x)-p.y ;
}

Slope::Slope(int _step, int _frontBufferDistance, int _backBufferDistance){
    step = _step;
    frontBufferDistance = _frontBufferDistance;
    backBufferDistance = _backBufferDistance;
    bufferSize = (frontBufferDistance+backBufferDistance)/step;

    sprite = sf::VertexArray(sf::LineStrip, bufferSize);
    points.push_front(sf::Vector2f(0, slopeFunction(0)));
}

void Slope::update(sf::Time dt,  sf::Vector2f playerPos){

    while(points.front().x < playerPos.x+frontBufferDistance) {
        points.push_front(sf::Vector2f(points.front().x+step, slopeFunction(points.front().x+step)));
    }
    while(points.back().x < playerPos.x-backBufferDistance){
        points.pop_back();
    }

    //printf("points.size = %dm bufSz = %d", points.size(), bufferSize);

}

void Slope::render(sf::RenderWindow &window){
    sprite.clear();
    sprite.resize(points.size());
    for(int i =points.size()-1; i >= 0; i--){
        sprite.append(sf::Vertex(points[i], sf::Color::White));
    }
    window.draw(sprite);
}