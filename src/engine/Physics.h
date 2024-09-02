#pragma once

#include "../game/Entity.h"

constexpr float GRAVITY = 3000.f;

class Physics {
public:
	static void applyGravity(Entity* entity, sf::Vector2f& velosity, float deltaTime);
};