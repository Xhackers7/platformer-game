#include "Scenes/StartScene.hpp"
#include "Engine/Log.hpp"

static float yVelocity = 0;
static float xVelocity = 0;
static bool left = false, right = false, top = false, bottom = false;
static sf::Sprite sprite;

StartScene::StartScene(std::shared_ptr<Engine::Context> &context) : currentContext(context)
{
}

StartScene::~StartScene()
{
}

void StartScene::init()
{
  currentContext->m_assetManager->addTexture(0, "assets/grass.png");
  currentContext->m_assetManager->addTexture(2, "assets/player.png");
  for (int i = 0; i < 6; i++)
  {
    blocks[i].setPosition(320 + (i * 40), 400);
    blocks[i].setTexture(currentContext->m_assetManager->getTexture(0));
  }

  test.setPosition(400, 100);
  currentContext->m_assetManager->addTexture(1, "assets/background.jpg");
  test.setTexture(currentContext->m_assetManager->getTexture(2));
  sprite.setTexture(currentContext->m_assetManager->getTexture(1));
}

void StartScene::handleInputs()
{
  sf::Event event;
  while (currentContext->m_window->pollEvent(event))
  {
    switch (event.type)
    {
    case sf::Event::Closed:
      currentContext->m_window->close();
      break;

    case sf::Event::MouseMoved:

      break;

    case sf::Event::KeyPressed:
      switch (event.key.code)
      {
      case sf::Keyboard::Space:
        if (bottom)
          yVelocity -= 5;
        break;

      case sf::Keyboard::A:
        xVelocity = -3;
        break;

      case sf::Keyboard::D:
        xVelocity = +3;
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

  char surface[7] = "NNNNNN";
  if (!bottom)
    yVelocity += .2;
  yVelocity = yVelocity > 3 ? 3 : yVelocity;
  test.move(sf::Vector2f(xVelocity, yVelocity));
  xVelocity = 0;
  for (int i = 0; surface[i] != 0; i++)
  {
    test.handleCollision(blocks[i], surface[i]);
  }

  // Engine::Log::info(surface);
  bool isFirstTime = true;
  for (char collision : surface)
  {
    if (isFirstTime)
      top = bottom = left = right = false;
    switch (collision)
    {
    case 'B':
      bottom = true;
      yVelocity = 0;
      break;

    default:
      break;
    }
    isFirstTime = false;
  }
}

void StartScene::draw()
{
  currentContext->m_window->draw(sprite);
  currentContext->m_window->draw(test);
  for (auto block : blocks)
  {
    currentContext->m_window->draw(block);
  }
}