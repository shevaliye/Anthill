#pragma once
#include "ant.h"
#include "anthill.h"
class Enemy
{
	Enemy();
	void attack(Ant & ant);
	void steal(Anthill& anthill);
	//~Enemy();
private:
	int health;
	int damage;
};