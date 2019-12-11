#include "World.h"

float Clamp(float n, float lower, float upper)
{
	n = (n > lower)* n + !(n > lower)* lower;
	return (n < upper) * n + !(n < upper) * upper;
}

World::World
(
	float clearRed, float clearGreen, float clearBlue,
	const ltex_t* back0, const ltex_t* back1,
	const ltex_t* back2, const ltex_t* back3
) : fClearRed(clearRed), fClearGreen(clearGreen), fClearBlue(clearBlue), pBackgrounds{new Background(back3), new Background(back2), new Background(back1), new Background(back0) }
{
	for (int i = 0; i < 4; i++)
	{
		Background* pBackground = const_cast<Background*>(pBackgrounds[i]);
		if (vLevelSize.x < pBackground->getTexture()->width)
		{
			vLevelSize = Vec2(pBackground->getTexture()->width, pBackground->getTexture()->height);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		Background* pBackground = const_cast<Background*>(pBackgrounds[i]);
		pBackground->setScale(vLevelSize / pBackground->getSize());
	}
}
float World::getClearRed() const
{
	return fClearRed;
}
float World::getClearGreen() const
{
	return fClearGreen;
}
float World::getClearBlue() const
{
	return fClearBlue;
}
float World::getScrollRatio(size_t layer)
{
	Background background = *(pBackgrounds[layer]);
	return background.GetScrollRatio();
}
const Vec2& World::getScrollSpeed(size_t layer) const
{
	Background background = *(pBackgrounds[layer]);
	return background.GetScrollSpeed();
}
const Vec2& World::getCameraPosition() const
{
	return vCameraPosition;
}
const ltex_t* World::getBackground(size_t layer) const
{
	return pBackgrounds[layer]->getTexture();
}
void World::setScrollRatio(size_t layer, float ratio)
{
	Background background = *(pBackgrounds[layer]);
	background.SetScrollRatio(ratio);
}
void World::setScrollSpeed(size_t layer, const Vec2& speed)
{
	Background background = *(pBackgrounds[layer]);
	background.SetScrollSpeed(speed);
}
void World::setCameraPosition(const Vec2& pos)
{
	vCameraPosition = pos;
}
void World::addSprite(Sprite& sprite)
{
	tSprites.push_back(sprite);
}
void World::removeSprite(Sprite& sprite)
{
	int iCounter = 0;
	while (iCounter < tSprites.size() && &(tSprites[iCounter]) != &sprite)
	{
		iCounter++;
	}
	if (iCounter < tSprites.size())
	{
		tSprites.erase(tSprites.begin() + iCounter);
	}
}
void World::update(float deltaTime)
{
	
	for (int i = 0; i < tSprites.size(); i++)
	{
		tSprites[i].update(deltaTime);
	}	
	vCameraPosition = Vec2(tSprites[0].getPosition().x - 600, tSprites[0].getPosition().y - 400);
	vCameraPosition = Vec2(Clamp(vCameraPosition.x, 0, vLevelSize.x - 1200), Clamp(vCameraPosition.y, 0, vLevelSize.y - 800));
	lgfx_setorigin(vCameraPosition.x, vCameraPosition.y);
}
void World::draw(const Vec2& screenSize)
{
	lgfx_clearcolorbuffer(fClearRed, fClearGreen, fClearBlue);

	for each (const Background* background in pBackgrounds)
	{
		background->draw();
	}
	for (int i = 0; i < tSprites.size(); i++)
	{
		tSprites[i].draw();
	}
}