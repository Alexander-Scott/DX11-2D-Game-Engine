#pragma once

#include "ICameraGameObject.h"

class PlayCamera : public ICameraGameObject
{
public:
	PlayCamera(IGraphics* graphics);

	void DrawSpriteScreenSpace(std::string name, Vec2 pos, RECT* rect, float rot, float scale, Vec2 offset) override;
	void DrawSpriteWorldSpace(std::string name, Vec2 pos, RECT* rect, float rot, float scale, Vec2 offset) override;

	void DrawTextScreenSpace(std::string text, Vec2 pos, float rot, float* rgb, float scale, Vec2 offset) override;
	void DrawTextWorldSpace(std::string text, Vec2 pos, float rot, float* rgb, float scale, Vec2 offset) override;

	virtual void DrawLine(Vec2 v1, Vec2 v2) override;
};

