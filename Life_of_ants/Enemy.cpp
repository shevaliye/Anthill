#include "Enemy.h"
#include <random>
Enemy::Enemy()
{
	health = 50;
	damage = 15;
}
void Enemy::attack(Anthill& anthill)
{
	std::srand(std::time(0));
	int id = std::rand() % anthill.get_size();
	anthill.attacked(id,damage);
}

void Enemy::steal(Anthill& anthill)
{
	anthill.steal();
}

//Enemy::~Enemy()
//{
//	delete this;
//}
