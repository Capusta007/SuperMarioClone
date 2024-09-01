#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <map>

class ResourceManager {
public:
	ResourceManager(const std::string& pathToExecutable);
	sf::Texture& getTexture(const std::string& textureName);


private:
	std::map<std::string, sf::Texture> m_textures;
	std::string m_pathToExecutableFolder;
};