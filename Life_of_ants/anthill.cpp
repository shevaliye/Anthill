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

void Anthill::steal()
{
	if (food_count > 0) 
	{
		food_count -= 1;
	}
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
		anthill.erase(iter);
		size--;
	}
}
void Anthill::starve()
{
	for (int i = 0; i < size ; i++)
	{
		if (anthill[i].health_decrease(1) == 0)
		{
			auto iter = anthill.cbegin();
			anthill.erase(iter + i);
		}
	}
}
