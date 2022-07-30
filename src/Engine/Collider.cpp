#include "Engine/Collider.hpp"
#include "Engine/Log.hpp"

Engine::Collider::Collider(sf::RectangleShape &shape) : body(shape)
{
}

Engine::Collider::~Collider()
{
}

bool Engine::Collider::handleCollision(sf::RectangleShape &other, float weight, float otherWeight, char &surface)
{
  float xIntersect, yIntersect, xDistance, yDistance;

  weight = otherWeight - weight;
  otherWeight = weight - otherWeight;

  weight = std::clamp(weight, 0.f, 1.f);
  otherWeight = std::clamp(otherWeight, 0.f, 1.f);

  if (!(checkCollision(other, xDistance, yDistance, xIntersect, yIntersect)))
  {
    surface = 'N';
    return false;
  }

  weight = std::clamp(weight, 0.f, 1.f);
  if (xIntersect > yIntersect)
  {
    if (xDistance > 0.f)
    {
      body.move(sf::Vector2f(xIntersect * weight, 0.f));
      other.move(sf::Vector2f(-xIntersect * otherWeight, 0.f));
      surface = 'R';
    }
    else
    {
      body.move(sf::Vector2f(-xIntersect * weight, 0.f));
      other.move(sf::Vector2f(xIntersect * otherWeight, 0.f));
      surface = 'L';
    }
  }
  else
  {
    if (yDistance > 0.f)
    {
      body.move(sf::Vector2f(0.f, yIntersect * weight));
      other.move(sf::Vector2f(0.f, -yIntersect * otherWeight));
      surface = 'B';
    }
    else
    {
      body.move(sf::Vector2f(0.f, -yIntersect * weight));
      other.move(sf::Vector2f(0.f, yIntersect * otherWeight));
      surface = 'T';
    }
  }
  return true;
}

bool Engine::Collider::checkCollision(const sf::RectangleShape &other, float &xDistance, float &yDistance, float &xIntersect, float &yIntersect) const
{
  sf::Vector2f otherPos = other.getPosition();
  sf::Vector2f otherHalfSize = sf::Vector2f(other.getSize().x / 2, other.getSize().y / 2);

  sf::Vector2f thisPos = body.getPosition();
  sf::Vector2f thisHalfSize = sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2);

  float xDist = otherPos.x - thisPos.x;
  float yDist = otherPos.y - thisPos.y;

  float xDelta = std::abs(xDist) - (otherHalfSize.x + thisHalfSize.x);
  float yDelta = std::abs(yDist) - (otherHalfSize.y + thisHalfSize.y);

  xDistance = xDist;
  yDistance = yDist;
  xIntersect = xDelta;
  yIntersect = yDelta;

  return (xDelta < 0.f && yDelta < 0.f);
}

bool Engine::Collider::checkCollision(const sf::RectangleShape &other) const
{
  sf::Vector2f otherPos = other.getPosition();
  sf::Vector2f otherHalfSize = sf::Vector2f(other.getSize().x / 2, other.getSize().y / 2);

  sf::Vector2f thisPos = body.getPosition();
  sf::Vector2f thisHalfSize = sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2);

  float xDist = otherPos.x - thisPos.x;
  float yDist = otherPos.y - thisPos.y;

  float xDelta = std::abs(xDist) - (otherHalfSize.x + thisHalfSize.x);
  float yDelta = std::abs(yDist) - (otherHalfSize.y + thisHalfSize.y);

  return (xDelta < 0.f && yDelta < 0.f);
}
