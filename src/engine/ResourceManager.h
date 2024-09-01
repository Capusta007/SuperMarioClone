#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <map>

class ResourceManager {
public:
	ResourceManager(const std::string& pathToExecutable);
	sf::Texture& getTexture(const std::string& textureName);
	sf::Font& getFont(const std::string& fontName);

private:
	std::map<std::string, sf::Texture> m_textures;
	std::map<std::string, sf::Font> m_fonts;
	std::string m_pathToExecutableFolder;
};