#include "anthill.h"

Anthill::Anthill()
{
	size = 2;
	Ant ant1;
	Ant ant2;
	anthill.push_back(ant1);
	anthill.push_back(ant2);
	max_count = 100;
	max_food = 100;
	food_count = 2;
}

void Anthill::grow(int branches,int food)
{
	max_count += branches;
	max_food += branches/2;
	if (food_count + food >= max_food)
	{
		food_count = max_food;
	}
	else
	{
		food_count += food;
	}
}

void Anthill::decrease()
{
	max_count -= 10;
	while (size > max_count)
	{
		auto iter = anthill.cbegin();
		anthill.erase(iter + 1);
		size--;
	}

}
