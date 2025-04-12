#pragma once
#include <iostream>
#include "role.h"

class Ant 
{
public:
	Ant();
	void grow();
private:
	int ages;
	int health;
	Role* role;
	static const int NURSE_AGE = 10;
	static const int SOLDIER_AGE = 25;
	static const int COLLECTOR_AGE = 50;
	static const int CLEANER_AGE = 75;
	void role_update();
};