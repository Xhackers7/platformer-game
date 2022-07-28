#include "StartScene.hpp"
#include "nextScene.hpp"

StartScene::StartScene(std::shared_ptr<Engine::Context> &context) : m_context(context), playerCollider(player), otherCollider(other)
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
  while (m_context->m_window->pollEvent(event))
  {
    switch (event.type)
    {
    case sf::Event::Closed:
      m_context->m_window->close();
      break;

    case sf::Event::MouseMoved:
      player.setPosition((float)event.mouseMove.x, (float)event.mouseMove.y);
      break;

    case sf::Event::KeyPressed:
      switch (event.key.code)
      {
      case sf::Keyboard::S:
        m_context->m_sceneManager->addScene(std::make_unique<nextScene>(m_context), true);
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
  playerCollider.handleCollision(other, 0.5);
}

void StartScene::draw()
{
  m_context->m_window->draw(player);
  m_context->m_window->draw(other);
}