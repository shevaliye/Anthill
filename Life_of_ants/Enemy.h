#pragma once
#include "anthill.h"
#include <iostream>
class Enemy
{
public:
	Enemy();
	void attack(Anthill& anthill);
	void steal(Anthill &anthill);
	//~Enemy();
private:
	int health;
	int damage;
};