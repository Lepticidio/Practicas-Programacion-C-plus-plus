#include "RenderManager.h"

RenderManager::RenderManager(std::vector<MovableObject*> _tObjects, int _iWidth) : m_tObjects(_tObjects),  m_iWidth(_iWidth)
{

	for (int i = 0; i < _tObjects.size(); i++)
	{
		if (_tObjects[i]->GetType() == PLAYER)
		{
			m_pPlayer = static_cast<Player*>(_tObjects[i]);
		}
	}

}
void RenderManager::Render()
{
	//Render
	system("cls");
	printf("\r");
	for (int i = 0; i < m_iWidth; i++)
	{
		bool bEmptyPosition = true;
		int iCounter = 0;
		while (iCounter < m_tObjects.size() && bEmptyPosition)
		{

			if (m_tObjects[iCounter]->GetX() == i)
			{
				m_tObjects[iCounter]->Render();
				bEmptyPosition = false;
			}
			iCounter++;
		}
		if (bEmptyPosition)
		{
			printf("-");
		}
	}
	printf("%d", m_pPlayer->GetScore());

}