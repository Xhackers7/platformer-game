#pragma once

#include <memory>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager
{
private:
    std::map<int, std::unique_ptr<sf::Texture>> textures;
    std::map<int, std::unique_ptr<sf::Font>> fonts;
    std::map<int, std::unique_ptr<sf::Music>> music;
    std::map<int, std::unique_ptr<sf::SoundBuffer>> soundEffects;

public:
    AssetManager();
    ~AssetManager();

    void addTexture(unsigned int id, const std::string &filepath, bool isRepeated = false);
    void addFont(unsigned int id, const std::string &filepath);
    void addMusic(unsigned int id, const std::string &filepath, bool isLooped = false);
    void addSound(unsigned int id, const std::string &filepath);

    const sf::Texture &getTexture(unsigned int id) const;
    const sf::Font &getFont(unsigned int id) const;
    const sf::Music &getMusic(unsigned int id) const;
    const sf::SoundBuffer &getSound(unsigned int id) const;
};
