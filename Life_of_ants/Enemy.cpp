#include "Enemy.h"
#include <random>
Enemy::Enemy()
{
	health = 200;
	damage = 20;
}
void Enemy::attack(Anthill& anthill)
{
	int id = std::rand() % anthill.get_size();
	if (anthill.get_role_id(id) == 1)
	{
		anthill.notify(1);
		anthill.attacked(id, damage);
		health -= anthill.get_count_role(1) * 30;
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			anthill.notify(i);
		}
		anthill.attacked(id, damage);
	}

}

void Enemy::steal(Anthill& anthill)
{
	anthill.steal();
}

//Enemy::~Enemy()
//{
//	delete this;
//}
