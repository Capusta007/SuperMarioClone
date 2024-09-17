#include "ResourceManager.h"

#include <iostream>
#include <fstream>
#include <filesystem>

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

void ResourceManager::saveLevelData(const LevelData& levelData, const std::string& filename) {
	const std::string folderPath = m_pathToExecutableFolder + "/CreatedLevels";

	// check is folder exists
	if (!std::filesystem::exists(folderPath)) {
		std::filesystem::create_directories(folderPath);
	}

	// full path to file
	std::string fullPath = folderPath + "/" + filename;

	std::ofstream outFile(fullPath, std::ios::binary | std::ios::trunc);

	if (!outFile) {
		throw std::runtime_error("Error opening file for writing: " + fullPath);
	}

	// save size of map
	size_t mapSize = levelData.blocksSprites.size();
	outFile.write(reinterpret_cast<const char*>(&mapSize), sizeof(mapSize));

	for (const auto& pair : levelData.blocksSprites) {
		// write coord and sprite in file
		outFile.write(reinterpret_cast<const char*>(&pair.first), sizeof(pair.first));
		outFile.write(reinterpret_cast<const char*>(&pair.second), sizeof(pair.second));
	}

	outFile.close();
}