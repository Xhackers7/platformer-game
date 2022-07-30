#pragma once

#include <SFML/Graphics.hpp>

namespace Engine
{
    class Collider
    {
    private:
        sf::RectangleShape &body;

    public:
        Collider(sf::RectangleShape &shape);
        ~Collider();

        bool handleCollision(sf::RectangleShape &other, float weight, float otherWeight, char &surface);
        bool checkCollision(const sf::RectangleShape &other, float &xDistance, float &yDistance, float &xIntersect, float &yIntersect) const;
        bool checkCollision(const sf::RectangleShape &other) const;
    };
}