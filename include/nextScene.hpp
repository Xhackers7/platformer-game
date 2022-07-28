#pragma once

#include <SFML/Graphics.hpp>
#include "Engine/Game.hpp"
#include "Engine/Collider.hpp"

class nextScene : public Engine::Scene {
private:
    std::shared_ptr<Engine::Context> m_context;

public:
    nextScene(std::shared_ptr<Engine::Context> &context);
    ~nextScene();
    void init() override;
    void handleInputs() override;
    void update(float deltaTime) override;
    void draw() override;

private:
    sf::Sprite sprite;
};