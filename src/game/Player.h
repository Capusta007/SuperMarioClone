#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
	Player(float x, float y, float moveSpeed);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);

private:
	void handleInput(float deltaTime);

	float m_moveSpeed;
	sf::Vector2f m_playerPos;
	sf::RectangleShape m_playerShape;
};