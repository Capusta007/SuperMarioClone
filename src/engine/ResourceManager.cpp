#include "ResourceManager.h"

#include <iostream>

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
