#include "World.h"
World::World
(
	float clearRed, float clearGreen, float clearBlue,
	const ltex_t* back0, const ltex_t* back1,
	const ltex_t* back2, const ltex_t* back3
) : fClearRed(clearRed), fClearGreen(clearGreen), fClearBlue(clearBlue), pBackground0(back0), pBackground1(back1), pBackground2(back2), pBackground3(back3)
{

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
float World::getScrollRatio(size_t layer) const
{
	return fScrollRatio;
}
const Vec2& World::getScrollSpeed(size_t layer) const
{
	return vScrollSpeed;
}
const Vec2& World::getCameraPosition() const
{
	return vCameraPosition;
}
const ltex_t* World::getBackground(size_t layer) const
{
	return pBackground0;
}
void World::setScrollRatio(size_t layer, float ratio)
{
	fScrollRatio = ratio;
}
void World::setScrollSpeed(size_t layer, const Vec2& speed)
{
	vScrollSpeed = speed;
}
void World::setCameraPosition(const Vec2& pos)
{
	vCameraPosition = pos;
}
void World::addSprite(Sprite& sprite)
{

}
void World::removeSprite(Sprite& sprite)
{

}
void World::update(float deltaTime)
{

}
void World::draw(const Vec2& screenSize)
{

}