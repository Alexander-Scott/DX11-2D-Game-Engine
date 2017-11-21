#include "ComponentFactory.h"


TransformComponent * ComponentFactory::MakeTransform(Vec2 position, float rotation, float scale)
{
	TransformComponent * transform = new TransformComponent();
	transform->SetPosition(position);
	transform->SetRotation(rotation);
	transform->SetScale(scale);

	return transform;
}

SpriteRendererComponent * ComponentFactory::MakeSpriteRenderer(std::string fileName, TransformComponent* transform)
{
	SpriteRendererComponent * spriteRenderer = new SpriteRendererComponent();
	spriteRenderer->SetFilename(fileName);
	if (transform == nullptr)
	{
		throw std::exception("This object requires a transform component.");
	}
	spriteRenderer->SetTransform(transform);

	return spriteRenderer;
}

SpriteAnimatorComponent * ComponentFactory::MakeSpriteAnimator(std::string fileName, TransformComponent * transform, std::vector<AnimationDesc> animDescs, int currentAnim)
{
	SpriteAnimatorComponent * spriteAnimator = new SpriteAnimatorComponent();
	spriteAnimator->SetFilename(fileName);
	if (transform == nullptr)
	{
		throw std::exception("This object requires a transform component.");
	}
	spriteAnimator->SetTransform(transform);
	spriteAnimator->SetAnimations(currentAnim, animDescs);

	return spriteAnimator;
}

RigidBodyComponent * ComponentFactory::MakeRigidbody(TransformComponent* transform, bool setStatic)
{
	RigidBodyComponent * rigidBody = new RigidBodyComponent();
	if (transform == nullptr)
	{
		throw std::exception("This object requires a transform component.");
	}
	if (setStatic)
	{
		rigidBody->SetStatic();
	}
	rigidBody->SetTransform(transform);

	return rigidBody;
}

TextRendererComponent * ComponentFactory::MakeTextRenderer(std::string text, TransformComponent * transform)
{
	TextRendererComponent * textRenderer = new TextRendererComponent();
	if (transform == nullptr)
	{
		throw std::exception("This object requires a transform component.");
	}
	textRenderer->SetTransform(transform);
	textRenderer->SetText(text);

	return textRenderer;
}

CircleColliderComponent * ComponentFactory::MakeCircleCollider(float radius, TransformComponent * transform, RigidBodyComponent * rigidbody)
{
	CircleColliderComponent * circleCollider = new CircleColliderComponent();
	if (transform == nullptr)
	{
		throw std::exception("This object requires a transform component.");
	}
	if (rigidbody == nullptr)
	{
		throw std::exception("This object requires a rigidbody component.");
	}
	circleCollider->SetTransformComponent(transform);
	circleCollider->SetRigidbodyComponent(rigidbody);
	circleCollider->SetRadius(radius);

	return circleCollider;
}

PolygonColliderComponent * ComponentFactory::MakePolygonCollider(Vec2 * verticies, int vertexCount, TransformComponent * transform, RigidBodyComponent * rigidbody)
{
	PolygonColliderComponent * polygonCollider = new PolygonColliderComponent();
	if (transform == nullptr)
	{
		throw std::exception("This object requires a transform component.");
	}
	if (rigidbody == nullptr)
	{
		throw std::exception("This object requires a rigidbody component.");
	}
	polygonCollider->SetTransformComponent(transform);
	polygonCollider->SetRigidbodyComponent(rigidbody);
	polygonCollider->SetVerticies(verticies, vertexCount);
	polygonCollider->SetOrient(0);

	return polygonCollider;
}
