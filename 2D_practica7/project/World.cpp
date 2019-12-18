#include "World.h"
#include "pugixml.hpp"
#include "pugiconfig.hpp"

float Clamp(float n, float lower, float upper)
{
	n = (n > lower)* n + !(n > lower)* lower;
	return (n < upper) * n + !(n < upper) * upper;
}

World::World
(
	float clearRed, float clearGreen, float clearBlue,
	const ltex_t* back0
) : fClearRed(clearRed), fClearGreen(clearGreen), fClearBlue(clearBlue), pBackgrounds{new Background(back0) }
{
	for (int i = 0; i < 1; i++)
	{
		Background* pBackground = const_cast<Background*>(pBackgrounds[i]);
		//if (vLevelSize.x < pBackground->getTexture()->width)
		//{
		//	vLevelSize = Vec2(pBackground->getTexture()->width, pBackground->getTexture()->height);
		//}
		vLevelSize = Vec2(800, 800);
	}
	for (int i = 0; i < 1; i++)
	{
		Background* pBackground = const_cast<Background*>(pBackgrounds[i]);
		pBackground->setScale(vLevelSize / pBackground->getSize());
	}
	const_cast<Background*>(pBackgrounds[0])->SetScrollRatio(0.4f);
	const_cast<Background*>(pBackgrounds[0])->SetScrollSpeed(Vec2(-16.f, -8.f));
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
	for each (const Background * background in pBackgrounds)
	{
		Background* pBackground = const_cast<Background*>(background);
		pBackground->update(deltaTime);
	}	
}
void World::draw(const Vec2& screenSize)
{
	//Clear screen with color
	lgfx_clearcolorbuffer(fClearRed, fClearGreen, fClearBlue);

	//Center camera on first sprite
	vCameraPosition = Vec2(tSprites[0].getPosition().x - screenSize.x/2, tSprites[0].getPosition().y - screenSize.y/2);
	vCameraPosition = Vec2(Clamp(vCameraPosition.x, 0, vLevelSize.x - screenSize.x), Clamp(vCameraPosition.y, 0, vLevelSize.y - screenSize.y));
	lgfx_setorigin(vCameraPosition.x, vCameraPosition.y);

	//Draw backgrounds and sprites
	for each (const Background* background in pBackgrounds)
	{
		background->draw(vLevelSize, vCameraPosition);
	}
	for (int i = 0; i < tSprites.size(); i++)
	{
		tSprites[i].draw();
	}
}
bool World::loadMap(const char* filename, uint16_t firstColId)
{
	bool bResult = false;
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename);
	if (result) 
	{
		// Cargado correctamente, podemos analizar su contenido ...
		bResult = true;
	}
	else 
	{
		// No se ha podido cargar
		std::cout << result.description() << std::endl;
	}
	return bResult;
}