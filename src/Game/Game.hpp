#pragma once

#include <memory>

#include "core/SceneManager.hpp"
#include "core/AssetManager.hpp"

struct Context
{
    std::unique_ptr<SceneManager> sceneManager;
    std::unique_ptr<AssetManager> assetManager;
    std::unique_ptr<sf::RenderWindow> window;

    Context()
    {
        sceneManager = std::make_unique<SceneManager>();
        assetManager = std::make_unique<AssetManager>();
        window = std::make_unique<sf::RenderWindow>();
    }
};

class Game
{
private:
    std::shared_ptr<Context> context;
    unsigned int m_fps;

public:
    Game(unsigned int fps);
    ~Game();

    void run();
};
