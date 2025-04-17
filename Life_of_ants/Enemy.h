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
	int get_damage() { return damage; };
	//~Enemy();
private:
	int health;
	int damage;
};