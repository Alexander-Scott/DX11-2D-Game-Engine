#pragma once

#include "ComponentFactory.h"

#include "PlayerComponent.h"
#include "DamageableComponent.h"
#include "ProjectileComponent.h"
#include "AIAgentComponent.h"
#include "ProjectileManagerComponent.h"
#include "GUITextValueComponent.h"

namespace ComponentFactory
{
	PlayerComponent * MakePlayerComponent(TransformComponent* trans, SpriteAnimatorComponent* anim, RigidBodyComponent* rb, DamageableComponent* dmg, ProjectileManagerComponent* proj, TransformComponent* cameraTransform);
	DamageableComponent * MakeDamageableComponent(float startHealth, std::string hitNoise);
	ProjectileComponent * MakeProjectileComponent(std::string affectedTag, float lifeSpan, float dmg);
	ProjectileManagerComponent * MakeProjectileManagerComponent(std::vector<GameObject*> projectiles);
	AIAgentComponent * MakeAIAgentComponent(TransformComponent* trans, SpriteAnimatorComponent* anim, RigidBodyComponent* rb, DamageableComponent* dmg, ProjectileManagerComponent* proj, TransformComponent* cameraTransform, float patrolTime, AIAgentPatrolDirection patrolStartDir, float idleTime, TransformComponent* targetTransform, float viewRange, float shotInterval);
	GUITextValueComponent * MakeGUITextValueComponent(std::string text, XMVECTORF32 colour, TransformComponent* transform, float& watchedValue);
}