#include "Player.h"

Player::Player(float x, float y, float moveSpeed) : m_playerPos(x,y), m_playerShape({ 50,50 })
{
	m_moveSpeed = moveSpeed;
	m_playerShape.setFillColor(sf::Color::Red);
	m_playerShape.setPosition(m_playerPos);
}

void Player::update(float deltaTime)
{
	handleInput(deltaTime);
	m_playerShape.setPosition(m_playerPos);
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_playerShape);
}

void Player::handleInput(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_playerPos += {0.f, -m_moveSpeed * deltaTime};
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_playerPos += {0.f, m_moveSpeed* deltaTime};
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_playerPos += {-m_moveSpeed * deltaTime, 0.f};
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_playerPos += {m_moveSpeed* deltaTime, 0.f};
	}
}
