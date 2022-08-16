#pragma once

#include <SFML/Graphics.hpp>
#include "Game/Game.hpp"

class StartScene : public Scene
{
private:
    std::shared_ptr<Context> context;
public:
    StartScene(std::shared_ptr<Context>& context);
    ~StartScene();

    void init() override;
    void handleInputs() override;
    void update(float deltaTime) override;
    void draw() override;
private:
    sf::RectangleShape player;
    sf::RectangleShape other;

    
};