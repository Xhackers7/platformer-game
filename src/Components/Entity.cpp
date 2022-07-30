#include "Components/Entity.hpp"

Entity::Entity()
{
  weight = 0.5;
}

Entity::Entity(float weight)
{
  this->weight = std::clamp(weight, 0.f, 0.9f);
}

void Entity::move(sf::Vector2f velocity)
{
  body.move(velocity);
}