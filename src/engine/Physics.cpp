#include "Physics.h"

void Physics::applyGravity(Entity* entity, sf::Vector2f& velosity, float deltaTime)
{
	velosity.y -= GRAVITY * deltaTime;
	entity->setPos(entity->getPos().x, entity->getPos().y - velosity.y * deltaTime);
}
