#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>

template <typename Type>
using Array = std::vector<Type>;

struct BaseComponent;
typedef void* Entity;
typedef uint32_t (*addComponent)(Array<uint8_t> &memory, Entity entity, BaseComponent *component);
typedef void (*deleteComponent)(BaseComponent *component);
#define null_entity nullptr

struct BaseComponent
{
  static uint32_t nextID();
  Entity entity = null_entity;
};

template <typename T>
struct Component : BaseComponent
{
  static const uint32_t id;
  static const size_t size;
  static const addComponent addFunction;
  static const deleteComponent deleteFunction;
};

template <typename Component>
uint32_t createComponent(Array<uint8_t> &memory, Entity entity, BaseComponent *component)
{
  uint32_t index = memory.size();
  memory.resize(index + Component::size);
  Component *newComponent = new (&memory[index]) Component(*(Component *)component);
                                newComponent->entity = entity;
  return index;
}

template <typename Component>
void freeComponent(BaseComponent *component)
{
  Component *newComponent = (Component *)component;
  newComponent->~Component();
}

template <typename T>
const uint32_t Component<T>::id(BaseComponent::nextID());

template <typename T>
const size_t Component<T>::size(sizeof(T));

template <typename T>
const addComponent Component<T>::addFunction(createComponent<T>);

template <typename T>
const deleteComponent Component<T>::deleteFunction(freeComponent<T>);

// Example usage

struct positionComponent : public Component<positionComponent>
{
  float x;
  float y;
};
