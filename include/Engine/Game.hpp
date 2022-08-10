#pragma once

#include <memory>

#include "Engine/SceneManager.hpp"
#include "Engine/AssetManager.hpp"

namespace Engine
{
    struct Context
    {
        std::unique_ptr<SceneManager> m_sceneManager;
        std::unique_ptr<AssetManager> m_assetManager;
        std::unique_ptr<sf::RenderWindow> m_window;

        Context()
        {
            m_sceneManager = std::make_unique<SceneManager>();
            m_assetManager = std::make_unique<AssetManager>();
            m_window = std::make_unique<sf::RenderWindow>();
        }
    };
    
    class Game
    {
    private:
        std::shared_ptr<Context> m_context;
        unsigned int m_fps;

    public:
        Game(unsigned int fps);
        ~Game();

        void run();
    };
}