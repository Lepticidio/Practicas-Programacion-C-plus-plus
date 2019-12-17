#include "RenderManager.h"

RenderManager::RenderManager() 
{

}
void RenderManager::Render()
{
	//Render
	system("cls");
	printf("\r");
	printf("\n ancho: %d", World::GetInstance().GetWidth());
	for (int i = 0; i < World::GetInstance().GetWidth(); i++)
	{
		bool bEmptyPosition = true;
		int iCounter = 0;
		while (iCounter < World::GetInstance().GetNumberObjects() && bEmptyPosition)
		{
			MovableObject* pObject = World::GetInstance().GetObjectAtIndex(iCounter);

			if (pObject->GetX() == i)
			{
				pObject->Render();
				bEmptyPosition = false;
			}
			iCounter++;
		}
		if (bEmptyPosition)
		{
			printf("-");
		}
	}
	Player* pPlayer = World::GetInstance().GetPlayer();
	printf("%d", pPlayer->GetScore());

}

RenderManager RenderManager::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new RenderManager();
	}
	return *m_pInstance;
}

RenderManager* RenderManager::m_pInstance = &RenderManager::GetInstance();