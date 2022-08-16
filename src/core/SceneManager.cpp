#include "core/SceneManager.hpp"
#include "core/Log.hpp"

SceneManager::SceneManager()
{
  m_replace = false;
  m_remove = false;
}

SceneManager::~SceneManager()
{
}

void SceneManager::addScene(std::unique_ptr<Scene> scene, bool replace = false)
{
  m_newScene = std::move(scene);
  m_replace = replace;
}

void SceneManager::pop()
{
  m_remove = true;
}

void SceneManager::processSceneChange()
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

std::unique_ptr<Scene> &SceneManager::getCurrent()
{
  return m_sceneStack.top();
}