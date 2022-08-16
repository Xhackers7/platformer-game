#pragma once

#include <SFML/Graphics.hpp>
#include "Game/Game.hpp"

class nextScene : public Scene {
private:
    std::shared_ptr<Context> context;

public:
    nextScene(std::shared_ptr<Context> &context);
    ~nextScene();
    void init() override;
    void handleInputs() override;
    void update(float deltaTime) override;
    void draw() override;

private:
    sf::Sprite sprite;
};