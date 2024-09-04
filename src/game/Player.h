#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../engine/ResourceManager.h"
#include "../engine/Animation.h"
#include "Entity.h"
#include "Block.h"

class Player : public Entity {
public:
	Player(float x, float y, sf::Vector2f moveSpeed, ResourceManager& rm);
	void update(float deltaTime, std::vector<Block> blocks);
	void render(sf::RenderWindow& window);

private:
	void handleInput(float deltaTime);
	void handleCollision(std::vector<Block> blocks);

	sf::Sprite m_sprite;
	ResourceManager& m_resourceManager;
	Animation m_runAnimation;
	bool m_isMoving;
};