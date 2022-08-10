#include "Engine/Game.hpp"
#include "StartScene.hpp"
#include <iostream>

Engine::Game::Game(unsigned int fps) : m_context(std::make_shared<Context>())
{
  m_fps = fps;
  m_context->m_window->create(sf::VideoMode(800, 800), "Hola", sf::Style::Close);

  m_context->m_sceneManager->addScene(std::make_unique<StartScene>(m_context), true);
}

Engine::Game::~Game()
{
}

void Engine::Game::run()
{

  sf::Clock clock;
  float deltaTime = 0;
  m_context->m_window->setFramerateLimit(60);
  while (m_context->m_window->isOpen())
  {
    deltaTime = clock.restart().asSeconds();
    float fps = 1.f / deltaTime;

    m_context->m_sceneManager->processSceneChange();
    m_context->m_sceneManager->getCurrent()->handleInputs();
    m_context->m_sceneManager->getCurrent()->update(deltaTime);
    m_context->m_window->clear();
    m_context->m_sceneManager->getCurrent()->draw();
    m_context->m_window->display();
  }
}