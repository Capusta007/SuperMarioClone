#include "ResourceManager.h"

#include <iostream>
#include <fstream>

ResourceManager::ResourceManager(const std::string& pathToExecutable)
{
	size_t index = pathToExecutable.find_last_of("/\\");
	m_pathToExecutableFolder = pathToExecutable.substr(0, index);
}

sf::Texture& ResourceManager::getTexture(const std::string& textureName) 
{
	auto it = m_textures.find(textureName);
	if (it != m_textures.end()) {
		return it->second;
	}
	else {
		sf::Texture texture;
		if (!texture.loadFromFile(m_pathToExecutableFolder + "/assets/textures/" + textureName)) {
			throw std::runtime_error("Unable to load texture: " + textureName);
		}
		else {
			m_textures.emplace(textureName, texture);
		}
		return m_textures[textureName];
	}
}

sf::Font& ResourceManager::getFont(const std::string& fontName)
{

	auto it = m_fonts.find(fontName);
	if (it != m_fonts.end()) {
		return it->second;
	}
	else {
		sf::Font font;
		if (!font.loadFromFile(m_pathToExecutableFolder + "/assets/fonts/" + fontName)) {
			throw std::runtime_error("Unable to load font: " + fontName);
		}
		else {
			m_fonts.emplace(fontName, font);
		}
		return m_fonts[fontName];
	}

}

void ResourceManager::loadLevelData(LevelData& levelData, const std::string& filename)
{
	std::ifstream inFile(m_pathToExecutableFolder + "/levels/" + filename, std::ios::binary);

	if (!inFile) {
		throw std::runtime_error("Error opening file for reading: " + filename);
	}

	// Load size of map
	size_t mapSize = 0;
	inFile.read(reinterpret_cast<char*>(&mapSize), sizeof(mapSize));

	// Load maps elements
	for (size_t i = 0; i < mapSize; ++i) {
		std::pair<int, int> key;
		std::pair<int, int> value;

		// Load coordinates of block
		inFile.read(reinterpret_cast<char*>(&key.first), sizeof(key.first));
		inFile.read(reinterpret_cast<char*>(&key.second), sizeof(key.second));
		// Load texture coordinates
		inFile.read(reinterpret_cast<char*>(&value.first), sizeof(value.first));
		inFile.read(reinterpret_cast<char*>(&value.second), sizeof(value.second));

		levelData.blocks[key] = value;
	}

	inFile.close();
}
