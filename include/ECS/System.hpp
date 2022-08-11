#pragma once

#include "Component.hpp"

class BaseSystem
{
public:
  BaseSystem(const Array<uint32_t> &componentTypesIn) : componentTypes(componentTypesIn) {}
  virtual void update(float deltaTime, BaseComponent **components) {}
  const Array<uint32_t> &getComponentTypes()
  {
    return componentTypes;
  }

private:
  Array<uint32_t> componentTypes;
};