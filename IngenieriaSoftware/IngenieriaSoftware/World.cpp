#include "World.h"

std::vector<MovableObject*>World::GetTObjects()
{
	return m_tObjects;
}

World World::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new World();
	}
	return *m_pInstance;
}
