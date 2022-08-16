#pragma once

#include <SFML/Graphics.hpp>

class Collider
{
private:
    sf::RectangleShape &body;

public:
    Collider(sf::RectangleShape &shape);
    ~Collider();

    bool handleCollision(sf::RectangleShape &other, float weight);
    bool checkCollision(const sf::RectangleShape &other, float &xDistance, float &yDistance, float &xIntersect, float &yIntersect) const;
};
