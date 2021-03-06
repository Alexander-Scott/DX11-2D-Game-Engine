#include "TiledBGRenderer.h"

TiledBGRenderer::TiledBGRenderer(int renderLayer)
{
	RenderLayer = renderLayer;
	mType = "Tiled BG Renderer";
}

TiledBGRenderer::~TiledBGRenderer()
{
}

void TiledBGRenderer::Draw(ICamera * cam)
{
	// Find closest tile centre to focusTrans
	// Find X and Y indivudally
	// Multiply trans.x by spriteWidth. Store the difference between newX and focusTrans.x. Loop until the new difference is greater than the old difference.
	// Repeat for Y
	// Around this central tile draw 8 more tiles around it by adding/subtracing spriteWidth and spriteHeight

	float centreTileXPos;
	float xDiffOld = 10000000;
	float xDiffNew = 0;
	int count = 0;

	// Find the closest X centre
	while (true)
	{
		if (mFocusTrans->GetWorldPosition().x > 0)
			centreTileXPos = GetTransform()->GetWorldPosition().x + (mSpriteWidth * count);
		else
			centreTileXPos = GetTransform()->GetWorldPosition().x - (mSpriteWidth * count);
		xDiffNew = std::abs(centreTileXPos - mFocusTrans->GetWorldPosition().x);

		if (xDiffNew > xDiffOld)
		{
			if (mFocusTrans->GetWorldPosition().x > 0)
				centreTileXPos -= mSpriteWidth/2;
			else
				centreTileXPos += mSpriteWidth/2;
			break;
		}
		else 
		{
			count++;
			xDiffOld = xDiffNew;
		}
	}

	float centreTileYPos;
	float yDiffOld = 10000000;
	float yDiffNew = 0;
	count = 0;

	// Find the closest Y centre
	while (true)
	{
		if (mFocusTrans->GetWorldPosition().y > 0)
			centreTileYPos = GetTransform()->GetWorldPosition().y + (mSpriteHeight * count);
		else
			centreTileYPos = GetTransform()->GetWorldPosition().y - (mSpriteHeight * count);
		yDiffNew = std::abs(centreTileYPos - mFocusTrans->GetWorldPosition().y);

		if (yDiffNew > yDiffOld)
		{
			if (mFocusTrans->GetWorldPosition().y > 0)
				centreTileYPos -= mSpriteHeight / 2;
			else
				centreTileYPos += mSpriteHeight / 2;
			break;
		}
		else
		{
			count++;
			yDiffOld = yDiffNew;
		}
	}

	switch (mScrollDir)
	{
		case TiledBGDirection::eHorizontal:
			for (int i = -2; i < 3; i++)
			{
				cam->DrawSpriteWorldSpace(mSpriteFileName, Vec2(centreTileXPos + (i * mSpriteWidth), GetTransform()->GetWorldPosition().y), 
					nullptr, GetTransform()->GetWorldRotation(), GetTransform()->GetWorldScale(), Vec2(0,0));
			}
			break;

		case TiledBGDirection::eVertical:
			for (int i = -2; i < 3; i++)
			{
				cam->DrawSpriteWorldSpace(mSpriteFileName, Vec2(GetTransform()->GetWorldPosition().x, centreTileYPos + (i * mSpriteHeight)), 
					nullptr, GetTransform()->GetWorldRotation(), GetTransform()->GetWorldScale(), Vec2(0, 0));
			}
			break;

		case TiledBGDirection::eHoriztonalAndVertical:
			// Draw more tiles around the centre tile to get the illusion of a massive background
			for (int i = -2; i < 3; i++)
			{
				for (int j = -2; j < 3; j++)
				{
					cam->DrawSpriteWorldSpace(mSpriteFileName, Vec2(centreTileXPos + (i * mSpriteWidth), centreTileYPos + (j * mSpriteHeight)), 
						nullptr, GetTransform()->GetWorldRotation(), GetTransform()->GetWorldScale(), Vec2(0, 0));
				}
			}
			break;
	}
}

void TiledBGRenderer::Update(float deltaTime)
{
	Vec2 dist = mFocusTrans->GetWorldPosition() - mPrevFocusPos;
	float length = dist.Len();
	if (length < 1)
	{
		return; // If the movement is so small, just return as the background will move too fast
	}

	dist.Normalize();

	switch (mScrollDir)
	{
		case TiledBGDirection::eHorizontal:
			dist.y = 0;
			break;

		case TiledBGDirection::eVertical:
			dist.x = 0;
			break;
	}

	GetTransform()->SetWorldPosition(GetTransform()->GetWorldPosition() - (dist * mScrollRate));
	mPrevFocusPos = mFocusTrans->GetWorldPosition();
}
