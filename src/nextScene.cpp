#include "nextScene.hpp"
#include "StartScene.hpp"

nextScene::nextScene(std::shared_ptr<Engine::Context> &context) : m_context(context)
{

}

nextScene::~nextScene() {

}

void nextScene::init()
{
  m_context->m_assetManager->addTexture(0, "assets/background.jpg");
  sprite.setTexture(m_context->m_assetManager->getTexture(0));
}

void nextScene::handleInputs()
{
  sf::Event event;
  while (m_context->m_window->pollEvent(event))
  {
    switch (event.type)
    {
    case sf::Event::Closed:
      m_context->m_window->close();
      break;
    case sf::Event::KeyPressed:
      switch (event.key.code)
      {
      case sf::Keyboard::S:
        m_context->m_sceneManager->addScene(std::make_unique<StartScene>(m_context), true);
        break;
      
      default:
        break;
      }
      break;

    default:
      break;
    }
  }
}

void nextScene::update(float deltaTime)
{

}

void nextScene::draw()
{
  m_context->m_window->draw(sprite);
}