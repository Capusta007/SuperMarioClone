#pragma once

#include <SFML/Graphics.hpp>

class Entity {
public:

	void applyGravity(float deltaTime);

	sf::Vector2f getPos() const { return m_position; }
	sf::Vector2f getSpeed() const { return m_moveSpeed; }

	void setPos(float x, float y) { m_position = { x,y }; }
	void setSpeed(sf::Vector2f speed) { m_moveSpeed = speed; }

protected:
	sf::Vector2f m_position;
	sf::Vector2f m_moveSpeed;
	bool m_isOnGround = false;
};