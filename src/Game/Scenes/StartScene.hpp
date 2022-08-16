#pragma once

#include <SFML/Graphics.hpp>

#include "Game/Game.hpp"



class StartScene : public Scene
{
private:

    std::shared_ptr<Context> current_context;

public:
    StartScene(std::shared_ptr<Context>& context);
    ~StartScene();

    void init() override;
    void handleInputs() override;
    void update(float deltaTime) override;
    void draw() override;
private:
    EntityHandle player;
    EntityHandle other;

    struct ShapeComponent : public ECSComponent<ShapeComponent>
    {
        sf::RectangleShape shape;
    } playerRect, otherRect;

};