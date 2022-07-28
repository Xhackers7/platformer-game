#include "Engine/SceneManager.hpp"
#include "Engine/Log.hpp"

Engine::SceneManager::SceneManager()
{
  m_replace = false;
  m_remove = false;
}

Engine::SceneManager::~SceneManager()
{
}

void Engine::SceneManager::addScene(std::unique_ptr<Scene> scene, bool replace = false)
{
  m_newScene = std::move(scene);
  m_replace = replace;
}

void Engine::SceneManager::pop()
{
  m_remove = true;
}

void Engine::SceneManager::processSceneChange()
{
  if (m_remove && !m_sceneStack.empty())
  {
    m_sceneStack.pop();
    if (!m_sceneStack.empty())
      m_sceneStack.top()->start();
    m_remove = false;
    Log::info("Removed scene");
  }

  if (m_newScene)
  {
    if (m_replace && !m_sceneStack.empty())
      m_sceneStack.pop();

    if (!m_sceneStack.empty())
      m_sceneStack.top()->pause();

    m_sceneStack.push(std::move(m_newScene));
    m_sceneStack.top()->init();
    m_sceneStack.top()->start();

    m_replace = false;
    m_newScene = nullptr;

    Log::info("Added new scene");
  }
}

std::unique_ptr<Engine::Scene> &Engine::SceneManager::getCurrent()
{
  return m_sceneStack.top();
}