//
// Created by syonfox on 07/03/19.
//

#ifndef MOTION_FLOW_SLOPE_HPP
#define MOTION_FLOW_SLOPE_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <deque>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class Slope {
private:
    double epsilon;
    std::deque<sf::Vector2f> points;
    sf::VertexArray sprite;
    int step;
    int frontBufferDistance;
    int backBufferDistance;
    int bufferSize;



    double squareDistance(sf::Vector2f &p , sf::Vector2f &q);
    double squareDistance(sf::Vector2f &p, double &x ); //computes y for you
    //Computes the intersection point of 2 lines //PARALEL LINES NOT ALLOWED
    sf::Vector2f lineLineIntersection(sf::Vector2f &p1 , sf::Vector2f &p2, sf::Vector2f &q1,sf::Vector2f &q2);


    //perlina noise


    std::deque<sf::Sprite> trees;
    sf::Texture tree1;

    std::deque<sf::Sprite> clouds;
    sf::Texture cloud1;



    int treeSpacing;
    int treeVar;
    int nextTree;

    int cloudSpacing;
    int cloudVar;
    int nextCloud;



public:
    bool fillSlope;
    double slopeFunction(double x);
    double slope(double x);
    Slope(int _step, int _frontBufferDistance, int _backBufferDistance);
    void update(sf::Time dt,  sf::Vector2f playerPos);
    void restart();
    void render(sf::RenderWindow &window);
    float colisionPoint_depth(sf::Vector2f p);

    //returns true if collision happens and set mtv if no colision mtv is unchanged

    bool colisionPoint(sf::Vector2f p, sf::Vector2f &mtv);
};


#endif //MOTION_FLOW_SLOPE_HPP
