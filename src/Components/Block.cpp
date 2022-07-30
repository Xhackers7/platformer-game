#include "Components/Block.hpp"

Block::Block() : collider(body)
{
  weight = 1;
}

bool Block::checkCollision(Block &other)
{
    return collider.checkCollision(other.body);
}

bool Block::handleCollision(Block &other, char &surface)
{
  return collider.handleCollision(other.body, weight, other.weight, surface);
}