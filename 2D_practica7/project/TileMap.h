#pragma once

#include <glfw3.h>
#include <litegfx.h>
#include "Vec2.h"

class TileMap
{
	TileMap();
	const int m_iWidth, m_iHeight, m_iWidthTile, m_iHeightTile;
	Vec2 tTilesPositions[16];
	ltex_t texture;

	void DrawTile(int _iX, int _iY);
	void Draw();
	void CheckCollision(int _iX, int _iY);
};

