#include "Engine/AssetManager.hpp"
#include "Engine/Log.hpp"

Engine::AssetManager::AssetManager()
{
}

Engine::AssetManager::~AssetManager()
{
}

void Engine::AssetManager::addTexture(unsigned int id, const std::string &filepath, bool isRepeated)
{
  auto texture = std::make_unique<sf::Texture>();

  if (!texture->loadFromFile(filepath))
    Log::error(("Failed to load texture " + filepath).c_str(), -1);

  texture->setRepeated(isRepeated);
  m_Textures[id] = std::move(texture);
  Log::info(("Loaded texture " + filepath).c_str());
}

void Engine::AssetManager::addFont(unsigned int id, const std::string &filepath)
{
  auto font = std::make_unique<sf::Font>();

  if (!font->loadFromFile(filepath))
    Log::error(("Failed to load font " + filepath).c_str(), -1);

  m_Fonts[id] = std::move(font);
  Log::info(("Loaded font " + filepath).c_str());
}

void Engine::AssetManager::addMusic(unsigned int id, const std::string &filepath, bool isLooped)
{
  auto music = std::make_unique<sf::Music>();

  if (!music->openFromFile(filepath))
    Log::error(("Failed to load music " + filepath).c_str(), -1);

  music->setLoop(isLooped);
  m_Music[id] = std::move(music);
  Log::info(("Loaded music " + filepath).c_str());
}

void Engine::AssetManager::addSound(unsigned int id, const std::string &filepath)
{
  auto sound = std::make_unique<sf::SoundBuffer>();

  if (!sound->loadFromFile(filepath))
    Log::error(("Failed to load sound effect " + filepath).c_str(), -1);

  m_Sound[id] = std::move(sound);
  Log::info(("Loaded sound effect " + filepath).c_str());
}

const sf::Texture &Engine::AssetManager::getTexture(unsigned int id) const
{
  return *(m_Textures.at(id).get());
}

const sf::Font &Engine::AssetManager::getFont(unsigned int id) const
{
  return *(m_Fonts.at(id).get());
}

const sf::Music &Engine::AssetManager::getMusic(unsigned int id) const
{
  return *(m_Music.at(id).get());
}

const sf::SoundBuffer &Engine::AssetManager::getSound(unsigned int id) const
{
  return *(m_Sound.at(id).get());
}
