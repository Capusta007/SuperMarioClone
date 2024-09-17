#include "TextLabel.h"

TextLabel::TextLabel(const std::string& text, const std::string& fontFileName, ResourceManager& resourceManager, unsigned int fontSize)
	: m_resourceManeger(resourceManager)
{
	m_text.setString(text);
	m_text.setFont(m_resourceManeger.getFont(fontFileName));
	m_text.setCharacterSize(fontSize);
}

void TextLabel::setPosition(float x, float y)
{
	m_position = { x,y };
	m_text.setPosition(m_position);
}

void TextLabel::setText(const std::string& text)
{
	m_text.setString(text);
}

void TextLabel::render(sf::RenderWindow& window)
{
	window.draw(m_text);
}
