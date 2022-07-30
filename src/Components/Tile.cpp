#include "Components/Tile.hpp"

Tile::Tile(sf::Vector2f pos, const sf::Texture &texture) : tileSize(40.f, 40.f)
{
  body.setOrigin(tileSize.x / 2, tileSize.y / 2);
  body.setSize(tileSize);
  body.setPosition(pos);
  body.setTexture(&texture);
}

Tile::Tile(sf::Vector2f pos) : tileSize(40.f, 40.f)
{
  body.setOrigin(tileSize.x / 2, tileSize.y / 2);
  body.setSize(tileSize);
  body.setPosition(pos);
}

Tile::Tile() : tileSize(40.f, 40.f)
{
  body.setOrigin(tileSize.x / 2, tileSize.y / 2);
  body.setSize(tileSize);
}

void Tile::setTexture(const sf::Texture &texture)
{
  body.setTexture(&texture);
}

void Tile::setPosition(float x, float y)
{
  body.setPosition(x, y);
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(body, states);
}