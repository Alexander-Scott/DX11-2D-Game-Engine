#pragma once

#include "Graphics.h"
#include "Vec2.h"

class Actor
{
public:
	Actor(const Vec2& pos);
	void Draw(Graphics& gfx) const;

private:
	Vec2 pos;
};