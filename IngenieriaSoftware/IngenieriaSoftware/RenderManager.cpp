#include "RenderManager.h"

RenderManager& RenderManager::GetInstance()
{
	static RenderManager render;
	return render;
}
RenderManager::RenderManager()
{

}
void RenderManager::Render()
{
	//Render
	system("cls");
	printf("\r");
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