#pragma once
#include "anthill.h"
#include <iostream>
class Enemy
{
public:
	Enemy();
	void attack(Anthill& anthill);
	void steal(Anthill &anthill);
	int get_health() { return health; };
	//~Enemy();
private:
	int health;
	int damage;
};