#include "StartScene.hpp"
#include "nextScene.hpp"

StartScene::StartScene(std::shared_ptr<Context> &context) : current_context(context)
{
}

StartScene::~StartScene()
{
}

void StartScene::init()
{
  playerRect.shape.setSize(sf::Vector2f(40, 40));
  playerRect.shape.setOrigin(20, 20);
  player = current_context->ecs->makeEntity(playerRect);
}

void StartScene::handleInputs()
{
  sf::Event event;
  while (current_context->window->pollEvent(event))
  {
    switch (event.type)
    {
    case sf::Event::Closed:
      current_context->window->close();
      break;

    case sf::Event::MouseMoved:
      current_context->ecs->getComponent<ShapeComponent>(player)->shape.setPosition((float)event.mouseMove.x, (float)event.mouseMove.y);
      break;

    case sf::Event::KeyPressed:
      switch (event.key.code)
      {
      case sf::Keyboard::S:
        current_context->sceneManager->addScene(std::make_unique<nextScene>(current_context), true);
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
  current_context->window->draw(current_context->ecs->getComponent<ShapeComponent>(player)->shape);
}