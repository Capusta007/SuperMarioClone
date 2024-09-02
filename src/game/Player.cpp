#include "Player.h"
#include <iostream>



constexpr float SCALE_FACTOR = 5.0f;
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
	m_isMoving = false;
	m_position = { x,y };
	m_moveSpeed = moveSpeed;
	m_sprite.setTexture(m_resourceManager.getTexture("mario_and_items.png"));
	m_sprite.setScale({ SCALE_FACTOR, SCALE_FACTOR });
	m_sprite.setTextureRect({ BIG_MARIO_LEFT ,BIG_MARIO_TOP,BIG_MARIO_WIDTH,BIG_MARIO_HEIGHT });



	// Animations
	m_runAnimation.addFrame({ BIG_MARIO_LEFT + BIG_MARIO_WIDTH * 4,BIG_MARIO_TOP, BIG_MARIO_WIDTH, BIG_MARIO_HEIGHT });
	m_runAnimation.addFrame({ BIG_MARIO_LEFT + BIG_MARIO_WIDTH * 5,BIG_MARIO_TOP, BIG_MARIO_WIDTH, BIG_MARIO_HEIGHT });
	m_runAnimation.addFrame({ BIG_MARIO_LEFT + BIG_MARIO_WIDTH * 6,BIG_MARIO_TOP, BIG_MARIO_WIDTH, BIG_MARIO_HEIGHT });
}

void Player::update(float deltaTime)
{
	/// delta time handle
	handleInput(deltaTime);
	applyGravity(deltaTime);
	m_runAnimation.update(deltaTime);


	/// player movements 
	if (m_isMoving && m_isOnGround) {
		m_runAnimation.setSprite(&m_sprite);
		m_runAnimation.start(0.1);
	}
	else if (!m_isOnGround) {
		m_sprite.setTextureRect({ BIG_MARIO_LEFT + BIG_MARIO_WIDTH * 2, BIG_MARIO_TOP,BIG_MARIO_WIDTH,BIG_MARIO_HEIGHT });
	}
	else {
		m_runAnimation.stop();
		m_sprite.setTextureRect({ BIG_MARIO_LEFT ,BIG_MARIO_TOP,BIG_MARIO_WIDTH,BIG_MARIO_HEIGHT });
	}

	/// sprite handle
	m_sprite.setPosition(m_position);

	//Todo: ѕока так оставь, потом убери эту фигню
	if (m_position.y >= 500)
	{
		m_position.y = 500;
		m_moveSpeed.y = 0;
		m_isOnGround = true;
	}
	else
	{
		m_isOnGround = false;
	}

}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Player::handleInput(float deltaTime)
{
	m_isMoving = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_isOnGround) {
		m_moveSpeed = { m_moveSpeed.x, -JUMP_STRENGHT };
		m_isOnGround = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_position += {-m_moveSpeed.x * deltaTime, 0.f};
		m_isMoving = true;
		m_sprite.setScale(-SCALE_FACTOR, SCALE_FACTOR);
		m_sprite.setOrigin(m_sprite.getGlobalBounds().width / SCALE_FACTOR, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_position += {m_moveSpeed.x* deltaTime, 0.f};
		m_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
		m_sprite.setOrigin(0, 0);
		m_isMoving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_isMoving = false;
	}
}
