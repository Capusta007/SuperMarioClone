#include "Player.h"
#include <iostream>

#include "GameSettings.h"
#include "TextureCoords.h"



Player::Player(float x, float y, sf::Vector2f moveSpeed, ResourceManager& rm) : m_resourceManager(rm)
{
	m_isMoving = false;
	m_position = { x,y };
	m_moveSpeed = moveSpeed;
	m_sprite.setTexture(m_resourceManager.getTexture("mario_and_items.png"));
	m_sprite.setScale({ SCALE_FACTOR, SCALE_FACTOR });
	m_sprite.setTextureRect({ BIG_MARIO_LEFT ,BIG_MARIO_TOP,BIG_MARIO_WIDTH,BIG_MARIO_HEIGHT });



	// Animations
	m_runAnimation.addFrame({ BIG_MARIO_RUN_LEFT,BIG_MARIO_RUN_TOP, BIG_MARIO_WIDTH, BIG_MARIO_HEIGHT });
	m_runAnimation.addFrame({ BIG_MARIO_RUN_LEFT + BIG_MARIO_WIDTH ,BIG_MARIO_RUN_TOP, BIG_MARIO_WIDTH, BIG_MARIO_HEIGHT });
	m_runAnimation.addFrame({ BIG_MARIO_RUN_LEFT + BIG_MARIO_WIDTH * 2,BIG_MARIO_RUN_TOP, BIG_MARIO_WIDTH, BIG_MARIO_HEIGHT });
}

void Player::update(float deltaTime, std::vector<Block> blocks)
{
	handleCollision(blocks);

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
		m_moveSpeed.x = -MARIO_SPEED;
		m_position += {m_moveSpeed.x* deltaTime, 0.f};
		m_isMoving = true;
		m_sprite.setScale(-SCALE_FACTOR, SCALE_FACTOR);
		m_sprite.setOrigin(m_sprite.getGlobalBounds().width / SCALE_FACTOR, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_moveSpeed.x = MARIO_SPEED;
		m_position += {m_moveSpeed.x* deltaTime, 0.f};
		m_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
		m_sprite.setOrigin(0, 0);
		m_isMoving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_isMoving = false;
	}
}

void Player::handleCollision(std::vector<Block> blocks)
{
	for (Block block : blocks) {
		if (block.getGlobalBounds().intersects(m_sprite.getGlobalBounds())) {
			float playerBottom = m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height;
			float playerRight = m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width;
			float platformBottom = block.getGlobalBounds().top + block.getGlobalBounds().height;
			float platformRight = block.getGlobalBounds().left + block.getGlobalBounds().width;

			// check side where collision appears
			float bottomCollision = platformBottom - m_sprite.getGlobalBounds().top;
			float topCollision = playerBottom - block.getGlobalBounds().top;
			float leftCollision = playerRight - block.getGlobalBounds().left;
			float rightCollision = platformRight - m_sprite.getGlobalBounds().left;

			bool movingDown = m_moveSpeed.y > 0;
			bool movingUp = m_moveSpeed.y < 0;
			bool movingLeft = m_moveSpeed.x < 0;
			bool movingRight = m_moveSpeed.x > 0;


			// top collision
			if (topCollision <= bottomCollision && topCollision <= leftCollision && topCollision <= rightCollision && movingDown) {
				m_position.y = platformBottom - m_sprite.getGlobalBounds().height - block.getGlobalBounds().height;
				m_moveSpeed.y = 0;
				m_isOnGround = true;
			}
			//botton collision
			else if (bottomCollision <= topCollision && bottomCollision <= leftCollision && bottomCollision <= rightCollision && movingUp) {
				m_position.y = platformBottom;
				m_moveSpeed.y = 0;
			}
			// left collision
			else if (leftCollision <= topCollision && leftCollision <= rightCollision && leftCollision <= bottomCollision && movingRight) {
				m_position.x = platformRight - block.getGlobalBounds().width - m_sprite.getGlobalBounds().width;
				m_moveSpeed.x = 0;
			}
			// right collision
			else if (rightCollision <= topCollision && rightCollision <= leftCollision && rightCollision <= bottomCollision && movingLeft) {
				m_position.x = platformRight;
				m_moveSpeed.x = 0;
			}
		}
	}
}
