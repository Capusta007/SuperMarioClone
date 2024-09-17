#pragma once

#include <SFML/Graphics.hpp>

#include <string>

class TextLabel {
public:
	TextLabel(const std::string& text, const std::string& fontFileName, ResourceManager& resourceManager, unsigned int fontSize = 50);

	void setPosition(float x, float y);
	void setText(const std::string& text);
	void render(sf::RenderWindow& window);

private:

	sf::Vector2f m_position;
	sf::Text m_text;
	ResourceManager& m_resourceManeger;

};