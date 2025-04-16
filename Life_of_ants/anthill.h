#pragma once
#include <vector>
#include "role.h"
#include "ant.h"
#include <iostream>
#include "informer.h"
using namespace std;

class Anthill
{
public:
	Anthill();
	void steal();
	void grow();
	void grow_ant();
	void decrease();
	void death_ant(int ind);
	void redistribution(int i);
	void workers(int work, int ind_inf);
	void now_stay_active();
	void attacked(int id,int damage);
	void addant();
	void eat();
	void notify(int inf);
	void starve();//:)))))
	void add_food(int berry);
	void add_branch(int branch);
	int get_count_informers(int inf);
	int get_size() {return size;};
	int get_max_count() { return max_count; };
	void get_roles();
	int get_food() { return food_count; };
private:
	vector<Ant*> anthill;
	vector<Informer> informers;
	int size;
	int branches;
	int food;
	int max_count;
	int food_count;
	int max_food;
};
