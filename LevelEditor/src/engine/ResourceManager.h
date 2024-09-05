	#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <map>

#include "LevelData.h"

class ResourceManager {
public:
	ResourceManager(const std::string& pathToExecutable);
	sf::Texture& getTexture(const std::string& textureName);
	sf::Font& getFont(const std::string& fontName);
	void saveLevelData(const LevelData& levelData, const std::string& filename);

private:
	std::map<std::string, sf::Texture> m_textures;
	std::map<std::string, sf::Font> m_fonts;
	std::string m_pathToExecutableFolder;
};