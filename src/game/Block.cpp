#include "Block.h"

#include "GameSettings.h"
#include "../engine/TextureCoords.h"

Block::Block(float x, float y, ResourceManager& rm)
	: m_resourceManager(rm)
{
	m_position = { x,y };
	m_sprite.setPosition(m_position);
	m_sprite.setTexture(m_resourceManager.getTexture("blocks.png"));
	m_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
	m_sprite.setTextureRect({ BLOCK_LEFT, BLOCK_TOP, BLOCK_WIDTH, BLOCK_HEIGHT });
}

void Block::update()
{
	m_sprite.setPosition(m_position);
}

void Block::setSpriteRect(sf::IntRect rect)
{
	m_sprite.setTextureRect(rect);
}

void Block::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
