#include "Enemy.h"
Enemy::Enemy()
{
	health = 50;
	damage = 15;
}
void Enemy::attack(Ant& ant)
{
	ant.health_decrease(damage);
}

void Enemy::steal(Anthill& anthill)
{
	anthill.steal();
}

//Enemy::~Enemy()
//{
//	delete this;
//}
