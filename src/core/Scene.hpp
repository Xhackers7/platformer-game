#pragma once

#include <SFML/Graphics.hpp>


  class Scene
  {
  public:

    Scene(){};
    ~Scene(){};

    virtual void init() = 0;
    virtual void handleInputs() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;

    virtual void pause(){};
    virtual void start(){};
  };
;