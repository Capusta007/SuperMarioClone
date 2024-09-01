#include "Player.h"

Player::Player() : m_playerShape({ 50,50 })
{
	m_playerShape.setFillColor(sf::Color::Red);
}

void Player::update()
{
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_playerShape);
}
