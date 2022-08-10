#include "ECS/Component.hpp"

uint32_t BaseComponent::nextID()
{
  static uint32_t id = 0;
  return id++;
}