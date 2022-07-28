#pragma once

#include <SFML/Graphics.hpp>
#include "Engine/Game.hpp"
#include "Engine/Collider.hpp"

class StartScene : public Engine::Scene
{
private:
    std::shared_ptr<Engine::Context> m_context;
public:
    StartScene(std::shared_ptr<Engine::Context>& context);
    ~StartScene();

    void init() override;
    void handleInputs() override;
    void update(float deltaTime) override;
    void draw() override;
private:
    sf::RectangleShape player;
    sf::RectangleShape other;

    Engine::Collider playerCollider;
    Engine::Collider otherCollider;
};