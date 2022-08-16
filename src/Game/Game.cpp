#include "Game/Game.hpp"
#include "Scenes/StartScene.hpp"

Game::Game(unsigned int fps) : context(std::make_shared<Context>())
{
  context->window->create(sf::VideoMode(800, 800), "Hola", sf::Style::Close);
  context->window->setFramerateLimit(fps);
  context->sceneManager->addScene(std::make_unique<StartScene>(context), true);
}

Game::~Game()
{
}

void Game::run()
{

  context->window->setFramerateLimit(60);
  float deltaTime = 0;
  sf::Clock clock;
  while (context->window->isOpen())
  {
    deltaTime = clock.restart().asSeconds();

    context->sceneManager->processSceneChange();
    context->sceneManager->getCurrent()->handleInputs();
    context->sceneManager->getCurrent()->update(deltaTime);
    context->window->clear();
    context->sceneManager->getCurrent()->draw();
    context->window->display();
  }
}