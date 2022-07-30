#pragma once
#include "Components/Tile.hpp"
#include "Engine/Collider.hpp"

class Block : public Tile
{
public:
  Block();

  bool checkCollision(Block &other);
  bool handleCollision(Block &other, char &surface);

protected:
  Engine::Collider collider;
  float weight;
};