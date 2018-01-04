#pragma once

#include "ObjectManager.h"
#include "PhysicsManager.h"

class GameLevel
{
public:
	GameLevel();
	~GameLevel();

	void CacheComponents(GameObject* gameObj, int renderLayer);

	void ConstructLevel(LevelData levelData);
	void BuildGUI();
	void BuildCamera();

	void Update(float deltaTime);
	void Draw();

private:
	void BuildCustomObjects();
	GameObject* FindGameObject(std::string tag);

	ObjectManager									mObjectManager;
	PhysicsManager									mPhysicsManager;
	LevelData										mLevelData;

	float											mScore;

	std::vector<GameObject*>						mRenderLayer0;
	std::vector<GameObject*>						mRenderLayer1;
	std::vector<GameObject*>						mRenderLayer2;

	std::vector<GameObject*>						mGameObjects;
	std::map<GameObject*, DamageableComponent*>		mDamageableGameObjects;
};