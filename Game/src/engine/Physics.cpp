#include "Physics.h"

void Physics::applyGravity(Entity* entity, sf::Vector2f& moveSpeed, float deltaTime)
{
	moveSpeed.y += GRAVITY * deltaTime;
	entity->setPos(entity->getPos().x, entity->getPos().y + moveSpeed.y * deltaTime);
}
