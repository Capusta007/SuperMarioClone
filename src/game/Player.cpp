#include "Player.h"

#include <iostream>

constexpr float SCALE_FACTOR = 2.0f;
constexpr float JUMP_STRENGHT = 1000.f;

constexpr int BIG_MARIO_LEFT = 0;
constexpr int BIG_MARIO_TOP = 0;
constexpr int BIG_MARIO_WIDTH = 18;
constexpr int BIG_MARIO_HEIGHT = 36;

constexpr int SMALL_MARIO_LEFT = 0;
constexpr int SMALL_MARIO_TOP = 72;
constexpr int SMALL_MARIO_WIDTH = 18;
constexpr int SMALL_MARIO_HEIGHT = 18;



Player::Player(float x, float y, sf::Vector2f moveSpeed, ResourceManager& rm) : m_resourceManager(rm)
{
	m_position = { x,y };
	m_moveSpeed = moveSpeed;
	m_sprite.setTexture(m_resourceManager.getTexture("mario_and_items.png"));
	m_sprite.setScale({ SCALE_FACTOR, SCALE_FACTOR });
	m_sprite.setTextureRect({ BIG_MARIO_LEFT ,BIG_MARIO_TOP,BIG_MARIO_WIDTH,BIG_MARIO_HEIGHT });
}

void Player::update(float deltaTime)
{
	handleInput(deltaTime);
	applyGravity(deltaTime);
	m_sprite.setTextureRect({ BIG_MARIO_LEFT ,BIG_MARIO_TOP,BIG_MARIO_WIDTH,BIG_MARIO_HEIGHT });
	m_sprite.setPosition(m_position);

	//Todo: ѕока так оставь, потом убери эту фигню
	if (m_position.y > 500)
	{
		m_position.y = 500;
		m_moveSpeed.y = 0;
		isOnGround = true;
	}
	else
	{
		isOnGround = false;
	}
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Player::handleInput(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isOnGround) {
		m_moveSpeed = { m_moveSpeed.x, JUMP_STRENGHT };
		isOnGround = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_position += {0.f, m_moveSpeed.y* deltaTime};
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_position += {-m_moveSpeed.x * deltaTime, 0.f};
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_position += {m_moveSpeed.x* deltaTime, 0.f};
	}
}
