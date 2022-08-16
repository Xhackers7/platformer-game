#include "nextScene.hpp"
#include "StartScene.hpp"

nextScene::nextScene(std::shared_ptr<Context> &context) : context(context)
{

}

nextScene::~nextScene() {

}

void nextScene::init()
{
  context->assetManager->addTexture(0, "assets/background.jpg");
  sprite.setTexture(context->assetManager->getTexture(0));
}

void nextScene::handleInputs()
{
  sf::Event event;
  while (context->window->pollEvent(event))
  {
    switch (event.type)
    {
    case sf::Event::Closed:
      context->window->close();
      break;
    case sf::Event::KeyPressed:
      switch (event.key.code)
      {
      case sf::Keyboard::S:
        context->sceneManager->addScene(std::make_unique<StartScene>(context), true);
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
  context->window->draw(sprite);
}