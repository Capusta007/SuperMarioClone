#pragma once

#include <SFML/Graphics.hpp>

#include "../engine/ResourceManager.h"
#include "../engine/Physics.h"

class Block {
public:

	Block(float x, float y, ResourceManager& rm);
	void update();
	void setSpriteRect(sf::IntRect rect);
	void render(sf::RenderWindow& window);
	sf::FloatRect getGlobalBounds() const { return m_sprite.getGlobalBounds(); }


private:
	sf::Vector2f m_position;
	sf::Sprite m_sprite;
	ResourceManager& m_resourceManager;

};