#include "PlayCamera.h"

PlayCamera::PlayCamera(IGraphics* graphics) : ICameraGameObject(graphics)
{
}

void PlayCamera::DrawSpriteScreenSpace(std::string name, Vec2 pos, RECT * rect, float rot, float scale, Vec2 offset)
{
	gfx->DrawSprite(name, pos, rect, rot, scale, offset);
}

void PlayCamera::DrawSpriteWorldSpace(std::string name, Vec2 pos, RECT * rect, float rot, float scale, Vec2 offset)
{
	gfx->DrawSprite(name, pos - mTransform->GetWorldPosition(), rect, rot, scale, offset);
}

void PlayCamera::DrawTextScreenSpace(std::string text, Vec2 pos, float rot, float* rgb, float scale, Vec2 offset)
{
	gfx->DrawText(text, pos, rot, rgb, scale, offset);
}

void PlayCamera::DrawTextWorldSpace(std::string text, Vec2 pos, float rot, float* rgb, float scale, Vec2 offset)
{
	gfx->DrawText(text, pos - mTransform->GetWorldPosition(), rot, rgb, scale, offset);
}

void PlayCamera::DrawLine(Vec2 v1, Vec2 v2)
{
	Vec2 newV1 = v1 - mTransform->GetWorldPosition();
	Vec2 newV2 = v2 - mTransform->GetWorldPosition();
	gfx->DrawLine(v1, v2);
}
