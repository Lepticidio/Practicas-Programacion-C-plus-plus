#include "StateMachine.h"
#include "Enemy.h"

void Flee(MovableObject* _object)
{
	Enemy* enemy = static_cast<Enemy*>(_object);
	enemy->MoveAwayFromPlayer();
}
void Attack(MovableObject* _object)
{
	Enemy* enemy = static_cast<Enemy*>(_object);
	enemy->MoveTowardsPlayer();
}
StateMachine::StateMachine()
{
	m_currentState = Attack;
}

//This is called in every frame for every enemy
//Checks if current state must be changed
//Also, calls current state, providing enemy's update behaviour
void StateMachine::CheckState(MovableObject* _object)
{
	Enemy* enemy = static_cast<Enemy*>(_object);
	if (!(enemy->IsNearBullet()))
	{
		m_currentState = Attack;
	}
	else
	{
		m_currentState = Flee;
	}
	m_currentState(enemy);
}