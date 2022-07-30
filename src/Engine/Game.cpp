#include "Engine/Game.hpp"
#include "Scenes/StartScene.hpp"

Engine::Game::Game(unsigned int fps) : m_context(std::make_shared<Context>())
{
  m_deltaTime = sf::seconds(1.f / (float)fps);
  m_context->m_window->create(sf::VideoMode(800, 800), "Platformer", sf::Style::Close);

  m_context->m_sceneManager->addScene(std::make_unique<StartScene>(m_context), true);
}

Engine::Game::~Game()
{
}

void Engine::Game::run()
{

  sf::Time deltaTime = sf::Time::Zero;
  sf::Clock clock;
  while (m_context->m_window->isOpen())
  {
    deltaTime += clock.restart();
    
    while (deltaTime > m_deltaTime)
    {
      deltaTime -= m_deltaTime;

      m_context->m_sceneManager->processSceneChange();
      m_context->m_sceneManager->getCurrent()->handleInputs();
      m_context->m_sceneManager->getCurrent()->update((float)deltaTime.asSeconds());
      m_context->m_window->clear();
      m_context->m_sceneManager->getCurrent()->draw();
      m_context->m_window->display();
    }
    
  }
}