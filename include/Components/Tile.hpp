#pragma once
#include <SFML/Graphics.hpp>

class Tile : public sf::Drawable
{

public:
    Tile(sf::Vector2f pos, const sf::Texture& texture);
    Tile(sf::Vector2f pos);
    Tile();
    ~Tile(){};

    void setTexture(const sf::Texture& texture);
    void setPosition(float x, float y);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

protected:
    sf::RectangleShape body;
    sf::Vector2f tileSize;
};