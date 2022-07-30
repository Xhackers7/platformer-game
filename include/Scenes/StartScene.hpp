#pragma once

#include <SFML/Graphics.hpp>
#include "Engine/Game.hpp"
#include "Engine/Collider.hpp"
#include "Components/Block.hpp"
#include "Components/Entity.hpp"

class StartScene : public Engine::Scene
{
private:
    std::shared_ptr<Engine::Context> currentContext;
public:
    StartScene(std::shared_ptr<Engine::Context>& context);
    ~StartScene();

    void init() override;
    void handleInputs() override;
    void update(float deltaTime) override;
    void draw() override;
private:
    Block blocks[6];
    Entity test;
};