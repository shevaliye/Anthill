#pragma once
#include "ant.h"
#include <vector>
using namespace std;
class Anthill
{
public:
	Anthill();
	void steal();
	void grow(int branches,int food);
	void decrease();
	void starve();//:)))))
private:
	vector<Ant> anthill;
	int size;
	int max_count;
	int food_count;
	int max_food;
};
