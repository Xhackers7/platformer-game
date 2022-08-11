#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>
#include <tuple>

template <typename Type>
using Array = std::vector<Type>;

struct BaseComponent;
typedef void* EntityHandle;
typedef uint32_t (*createComponentFunction)(Array<uint8_t> &memory, EntityHandle entity, BaseComponent *component);
typedef void (*deleteComponentFunction)(BaseComponent *component);
#define null_entity nullptr

struct BaseComponent
{
  static uint32_t registerNewComponent(createComponentFunction createFn, deleteComponentFunction deleteFn, size_t size);
  EntityHandle entity = null_entity;

  inline static createComponentFunction getCreateFunction(uint32_t id)
  {
    return std::get<0>(componentTypes[id]);
  }

inline static deleteComponentFunction getDeleteFunction(uint32_t id)
  {
    return std::get<1>(componentTypes[id]);
  }

inline static size_t getSize(uint32_t id)
  {
    return std::get<2>(componentTypes[id]);
  }

private:
  static Array<std::tuple<createComponentFunction, deleteComponentFunction, size_t>> componentTypes;
};

Array<std::tuple<createComponentFunction, deleteComponentFunction, size_t>> BaseComponent::componentTypes;

template <typename T>
struct Component : BaseComponent
{
  static const uint32_t id;
  static const size_t size;
  static const createComponentFunction createFunction;
  static const deleteComponentFunction deleteFunction;
};

template <typename Component>
uint32_t createComponent(Array<uint8_t> &memory, EntityHandle entity, BaseComponent *component)
{
  uint32_t index = memory.size();
  memory.resize(index + Component::size);
  Component *newComponent = new (&memory[index]) Component(*(Component *)component);
  newComponent->entity = entity;
  return index;
}

template <typename Component>
void deleteComponent(BaseComponent *component)
{
  Component *newComponent = (Component *)component;
  newComponent->~Component();
}

template <typename T>
const uint32_t Component<T>::id(
  BaseComponent::registerNewComponent(createComponent<T>, 
                                      deleteComponent<T>, 
                                      sizeof(T)));

template <typename T>
const size_t Component<T>::size(sizeof(T));

template <typename T>
const createComponentFunction Component<T>::createFunction(createComponent<T>);

template <typename T>
const deleteComponentFunction Component<T>::deleteFunction(deleteComponent<T>);

// Example usage

struct positionComponent : public Component<positionComponent>
{
  float x;
  float y;
};
