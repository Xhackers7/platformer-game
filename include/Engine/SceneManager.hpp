#pragma once

#include <stack>
#include <memory>

#include "Engine/Scene.hpp"

namespace Engine
{

    class SceneManager
    {

    private:
        std::stack<std::unique_ptr<Scene>> m_sceneStack;
        std::unique_ptr<Scene> m_newScene;

        bool m_remove;
        bool m_replace;

    public:
        SceneManager();
        ~SceneManager();

        void addScene(std::unique_ptr<Scene> scene, bool replace);
        void pop();
        void processSceneChange();
        std::unique_ptr<Scene> &getCurrent();
    };
}