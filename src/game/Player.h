#pragma once

#include <SFML/Graphics.hpp>

#include "../engine/ResourceManager.h"
#include "Entity.h"

class Player : public Entity {
public:
	Player(float x, float y, sf::Vector2f moveSpeed, ResourceManager& rm);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);

private:
	void handleInput(float deltaTime);

	sf::Sprite m_sprite;
	ResourceManager& m_resourceManager;
};