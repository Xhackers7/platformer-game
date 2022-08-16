#include "core/AssetManager.hpp"
#include "core/Log.hpp"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

void AssetManager::addTexture(unsigned int id, const std::string &filepath, bool isRepeated)
{
  auto texture = std::make_unique<sf::Texture>();

  if (!texture->loadFromFile(filepath))
    Log::error(("Failed to load texture " + filepath).c_str(), -1);

  texture->setRepeated(isRepeated);
  textures[id] = std::move(texture);
  Log::info(("Loaded texture " + filepath).c_str());
}

void AssetManager::addFont(unsigned int id, const std::string &filepath)
{
  auto font = std::make_unique<sf::Font>();

  if (!font->loadFromFile(filepath))
    Log::error(("Failed to load font " + filepath).c_str(), -1);

  fonts[id] = std::move(font);
  Log::info(("Loaded font " + filepath).c_str());
}

void AssetManager::addMusic(unsigned int id, const std::string &filepath, bool isLooped)
{
  auto music = std::make_unique<sf::Music>();

  if (!music->openFromFile(filepath))
    Log::error(("Failed to load music " + filepath).c_str(), -1);

  music->setLoop(isLooped);
  this->music[id] = std::move(music);
  Log::info(("Loaded music " + filepath).c_str());
}

void AssetManager::addSound(unsigned int id, const std::string &filepath)
{
  auto sound = std::make_unique<sf::SoundBuffer>();

  if (!sound->loadFromFile(filepath))
    Log::error(("Failed to load sound effect " + filepath).c_str(), -1);

  soundEffects[id] = std::move(sound);
  Log::info(("Loaded sound effect " + filepath).c_str());
}

const sf::Texture &AssetManager::getTexture(unsigned int id) const
{
  return *(textures.at(id).get());
}

const sf::Font &AssetManager::getFont(unsigned int id) const
{
  return *(fonts.at(id).get());
}

const sf::Music &AssetManager::getMusic(unsigned int id) const
{
  return *(music.at(id).get());
}

const sf::SoundBuffer &AssetManager::getSound(unsigned int id) const
{
  return *(soundEffects.at(id).get());
}
