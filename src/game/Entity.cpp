#include "Entity.h"
#include "../engine/Physics.h"

void Entity::applyGravity(float deltaTime)
{
	Physics::applyGravity(this, m_moveSpeed, deltaTime);
}
