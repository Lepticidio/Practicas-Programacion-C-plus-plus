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
	//Clears the console, so it can be updated
	system("cls");
	printf("\r");

	//For each position of world, checks if there is an object and draws it
	//If none is found, it just draws a '_'
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
	//Prints current score
	Player* pPlayer = World::GetInstance().GetPlayer();
	printf("%d", pPlayer->GetScore());

}