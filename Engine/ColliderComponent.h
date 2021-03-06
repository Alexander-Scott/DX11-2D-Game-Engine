#pragma once

#include "IComponent.h"

#include "Consts.h"
#include "TransformComponent.h"
#include "RigidBodyComponent.h"

class ColliderComponent : public IComponent
{
public:
	RigidBodyComponent* GetRigidbodyComponent() { return mRigidyBodyComponent; }
	TransformComponent* GetTransformComponent() { return mTransformComponent; }

	virtual ColliderType GetType(void) const = 0;
	virtual void ComputeMass(float density) = 0;
	virtual Rect GetRect() = 0;

	void SetPreviousRect(Rect r) { mPreviousRect = r; }
	Rect GetPreviousRect() { return mPreviousRect; }

	virtual Vec2 GetCentre() = 0;

	int								CentreGridSquare;
	int								LeftGridSquare;
	int								RightGridSquare;
	int								BottomGridSquare;
	int								TopGridSquare;

protected:
	TransformComponent*				mTransformComponent;
	RigidBodyComponent*				mRigidyBodyComponent;
	Rect							mPreviousRect;
};

