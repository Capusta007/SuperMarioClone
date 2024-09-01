#include "Player.h"



constexpr float SCALE_FACTOR = 2.0f;
constexpr int BIG_MARIO_LEFT = 0;
constexpr int BIG_MARIO_TOP = 0;
constexpr int BIG_MARIO_WIDTH = 18;
constexpr int BIG_MARIO_HEIGHT = 36;

constexpr int SMALL_MARIO_LEFT = 0;
constexpr int SMALL_MARIO_TOP = 72;
constexpr int SMALL_MARIO_WIDTH = 18;
constexpr int SMALL_MARIO_HEIGHT = 18;



Player::Player(float x, float y, float moveSpeed, ResourceManager& rm) : m_playerPos(x, y), m_resourceManager(rm)
{
	m_moveSpeed = moveSpeed;
	m_sprite.setTexture(m_resourceManager.getTexture("mario_and_items.png"));
	m_sprite.setScale({ SCALE_FACTOR, SCALE_FACTOR });
	m_sprite.setTextureRect({ BIG_MARIO_LEFT ,BIG_MARIO_TOP,BIG_MARIO_WIDTH,BIG_MARIO_HEIGHT});
}

void Player::update(float deltaTime)
{
	m_sprite.setTextureRect({ BIG_MARIO_LEFT ,BIG_MARIO_TOP,BIG_MARIO_WIDTH,BIG_MARIO_HEIGHT});
	handleInput(deltaTime);
	m_sprite.setPosition(m_playerPos);
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
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
