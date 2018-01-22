#pragma once

#include "IScene.h"
#include "EditorCamera.h"

class EditorScene :	public IScene
{
public:
	EditorScene(Camera* cam);
	~EditorScene();

	void Update(float deltaTime) override;
	void Draw() override;
	void CacheComponents(shared_ptr<GameObject> gameObj) override;
};

