//
// Created by syonfox on 07/03/19.
//

#ifndef MOTION_FLOW_SLOPE_HPP
#define MOTION_FLOW_SLOPE_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <deque>


class Slope {
private:
    std::deque<sf::Vector2f> points;
    sf::VertexArray sprite;
    int step;
    int frontBufferDistance;
    int backBufferDistance;
    int bufferSize;

    double slopeFunction(double x);
public:

    Slope(int _step, int _frontBufferDistance, int _backBufferDistance);
    void update(sf::Time dt,  sf::Vector2f playerPos);
    void render(sf::RenderWindow &window);
    float colisionPoint(sf::Vector2f p);
};


#endif //MOTION_FLOW_SLOPE_HPP
