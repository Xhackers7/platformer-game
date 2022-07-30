#include "Components/Block.hpp"

class Entity : public Block
{
public:
  Entity();
  Entity(float weight);

  void setWeight(float weight){this->weight = weight;}
  void move(sf::Vector2f velocity);
};