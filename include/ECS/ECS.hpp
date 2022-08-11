#pragma once
#include "Component.hpp"
#include "System.hpp"
#include <map>

typedef Array<std::pair<uint32_t, uint32_t>> Entity;

class ECS
{
public:
  ECS(){}
  ~ECS();

  //  Entity
  EntityHandle makeEntity(BaseComponent* components, const uint32_t* componentIDs, size_t num);
  void removeEntity(EntityHandle handle);

  // Component
  template<class Component>
  void addComponent(EntityHandle entity, Component* component);

  template<class Component>
  void removeComponent(EntityHandle entity);

  template<class Component>
  void getComponent(EntityHandle entity);

  // System
  inline void addSystem(BaseSystem& system)
  {
    systems.push_back(&system);
  }
  
  void updateSystems(float deltaTime);
  void removeSystem();

private:
  Array<BaseSystem*> systems;
  std::map<uint32_t, Array<uint8_t>> components;
  Array<std::pair<uint32_t, Entity>*> entities;

  inline std::pair<uint32_t, Entity>* toRawEntity(EntityHandle entity)
  {
    return (std::pair<uint32_t, Entity>*)entity;
  }

  inline uint32_t getEntityIndex(EntityHandle entity)
  {
    return toRawEntity(entity)->first;
  }

  inline Entity& toEntity(EntityHandle entity)
  {
    return toRawEntity(entity)->second;
  }

  NULL_COPY_AND_ASSIGN(ECS);
};