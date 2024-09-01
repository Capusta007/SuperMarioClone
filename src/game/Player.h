#pragma once

#include <SFML/Graphics.hpp>

#include "../engine/ResourceManager.h"

class Player {
public:
	Player(float x, float y, float moveSpeed, ResourceManager& rm);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);

private:
	void handleInput(float deltaTime);

	sf::Sprite m_sprite;
	float m_moveSpeed;
	sf::Vector2f m_playerPos;
	ResourceManager& m_resourceManager;
};