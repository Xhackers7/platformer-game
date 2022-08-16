#include "StartScene.hpp"
#include "nextScene.hpp"

StartScene::StartScene(std::shared_ptr<Context> &context) : context(context)
{
}

StartScene::~StartScene()
{
}

void StartScene::init()
{
  player.setSize(sf::Vector2f(40, 40));
  player.setOrigin(20, 20);
  player.setPosition(400, 400);
  player.setFillColor(sf::Color::Red);

  other.setSize(sf::Vector2f(40, 40));
  other.setOrigin(20, 20);
  other.setPosition(600, 600);
  other.setFillColor(sf::Color::Green);
}

void StartScene::handleInputs()
{
  sf::Event event;
  while (context->window->pollEvent(event))
  {
    switch (event.type)
    {
    case sf::Event::Closed:
      context->window->close();
      break;

    case sf::Event::MouseMoved:
      player.setPosition((float)event.mouseMove.x, (float)event.mouseMove.y);
      break;

    case sf::Event::KeyPressed:
      switch (event.key.code)
      {
      case sf::Keyboard::S:
        context->sceneManager->addScene(std::make_unique<nextScene>(context), true);
        break;

      default:
        break;
      };
    default:
      break;
    }
  }
}
void StartScene::update(float deltaTime)
{
  
}

void StartScene::draw()
{
  context->window->draw(player);
  context->window->draw(other);
}