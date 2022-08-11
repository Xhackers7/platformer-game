#include "ECS/Component.hpp"

uint32_t BaseComponent::registerNewComponent(createComponentFunction createFn, deleteComponentFunction deleteFn, size_t size)
{
  uint32_t id = componentTypes.size();
  componentTypes.push_back(std::tuple<createComponentFunction, deleteComponentFunction, size_t>(createFn, deleteFn, size));
  return id;
}