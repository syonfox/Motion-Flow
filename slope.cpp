//
// Created by syonfox on 07/03/19.
//

#include <cmath>
#include <assert.h>
#include "slope.hpp"




//double Slope::rand()
//{
//    Z =  (A * Z + C) % M;
//    return Z / M - 0.5;
//}
//
//double Slope::interpolate(double pa, double pb , double px) {
//    double ft = px * PI,
//           f = (1 - cos(ft)) * 0.5;
//    return pa * (1 - f) + pb * f;
//}


double Slope::slopeFunction(double x){
    //return 100+ 50*sin(x/100)+(0.3*x) +30* cos(x/75)+  20*sin(x/50) + 169*sin((x)/300);
    return  100+ 70* sin(x/100)+ 40*sin(x/200)+ 20*sin(x/300)+ 100*sin(x/400) + 40*sin(x/800) + (0.1*x);
}
double Slope::slope(double x){
    return (slopeFunction(x-epsilon) - slopeFunction(x+epsilon)) / (2*epsilon);
}

double Slope::squareDistance(sf::Vector2f &p, sf::Vector2f &q ) {
    return pow((p.x-q.x),2) + pow((p.y-q.y),2);
}

double Slope::squareDistance(sf::Vector2f &p, double &x ) {
    return pow((p.x-x),2) + pow((p.y-slopeFunction(x)),2);

}
sf::Vector2f Slope::lineLineIntersection(sf::Vector2f &p1 , sf::Vector2f &p2, sf::Vector2f &q1,sf::Vector2f &q2){
// Line AB represented as a1x + b1y = c1
    double a1 = p2.y - p1.y;
    double b1 = p1.x - p2.x;
    double c1 = a1*(p1.x) + b1*(p1.y);

    // Line CD represented as a2x + b2y = c2
    double a2 = q2.y - q1.y;
    double b2 = q1.x - q2.x;
    double c2 = a2*(q1.x)+ b2*(q1.y);

    double determinant = a1*b2 - a2*b1;

    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        printf("ERROR: Determinaint = 0");
        assert(0);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return sf::Vector2f(x, y);
    }
}


float Slope::colisionPoint_depth(sf::Vector2f p){
    return slopeFunction(p.x)-p.y ;
}


bool Slope::colisionPoint(sf::Vector2f p, sf::Vector2f &mtv){

    sf::Vector2f q(p.x, slopeFunction(p.x));
    if(p.y<=q.y) return false; //no colision

    double m = slope(p.x);
    if(fabs(m) < 0.01){
        mtv.x = 0;
        mtv.y = q.y - p.y;
    }
    sf::Vector2f p2 = p + sf::Vector2f(1, 1/m);
    sf::Vector2f q2 = q + sf::Vector2f(1, -m);

    mtv = lineLineIntersection(p,p2,q,q2) - p;
    if(mtv.y > 4){
        printf("toobig");
    }
    return true;



}
//bool Slope::colisionPoint(sf::Vector2f p, sf::Vector2f &mtv){
//    sf::Vector2f q(p.x, slopeFunction(p.x));
//
//    if(p.y<=q.y) return false; //no colision
//
//    int n = 8; //num of itterations
//    double a,b,c;
//    double A,B,C;
//    a = p.x-8;
//    A = squareDistance(p, a);
//    b = p.x+8;
//    B = squareDistance(p, b);
//
//    while(n>0){
//        c = (a+b)/2;
//        C = squareDistance(p , c);
//
//        if(A > B){
//            a = c;
//            A = C;
//        } else {
//            b = c;
//            B = C;
//        }
//        n--;
//    }
//
//    mtv = sf::Vector2f(c-p.x, slopeFunction(c) - p.y);
//    return true;
//}

Slope::Slope(int _step, int _frontBufferDistance, int _backBufferDistance){
    epsilon = 1;
    step = _step;
    frontBufferDistance = _frontBufferDistance;
    backBufferDistance = _backBufferDistance;
    bufferSize = (frontBufferDistance+backBufferDistance)/step;

    sprite = sf::VertexArray(sf::LineStrip, bufferSize);
    points.push_front(sf::Vector2f(0, slopeFunction(0)));

    fillSlope = true;
}

void Slope::update(sf::Time dt,  sf::Vector2f playerPos){

    while(points.front().x < playerPos.x+frontBufferDistance) {
        points.push_front(sf::Vector2f(points.front().x+step, slopeFunction(points.front().x+step)));
    }

    while(points.back().x < playerPos.x-backBufferDistance){
        points.pop_back();
    }

    while(points.back().x > playerPos.x-backBufferDistance){
        points.push_back(sf::Vector2f(points.back().x-step, slopeFunction(points.back().x-step)));
    }

    while(points.front().x > playerPos.x+frontBufferDistance) {
        points.pop_front();
    }

    //printf("points.size = %dm bufSz = %d", points.size(), bufferSize);

}

void Slope::render(sf::RenderWindow &window){
    sprite.clear();

    if(fillSlope) {
        sprite.setPrimitiveType(sf::TrianglesStrip);
        sprite.resize(points.size()*2);
        int size = points.size()*2;
        for (int i = size - 1; i >= 0; i--) {
            if(i%2 == 0)
                sprite[i] = (sf::Vertex(points[i/2], sf::Color::White));
            else
                sprite[i] = (sf::Vertex(sf::Vector2f(points[i/2].x, points[i/2].y+2000), sf::Color::White));
        }
    } else {
        sprite.setPrimitiveType(sf::LineStrip);
        sprite.resize(points.size());
        int size = points.size();
        for (int i = size - 1; i >= 0; i--) {
            sprite[i] = (sf::Vertex(points[i], sf::Color::White));
        }
    }
    window.draw(sprite);
}