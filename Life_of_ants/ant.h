#pragma once
#include <iostream>
#include "informer.h"
#include "role.h"
class chetirka
{
public:
	chetirka(int fr, int to_) :from(fr), to(to_) {};
	int get_from() const { return from; };
	int get_to() const { return to; };
private:
	int from;
	int to;

};

class Ant
{
public:
	Ant(int ind);
	void grow();
	int get_ages() { return ages; };
	int health_decrease(int damage);
	void set_status(bool stat);
	bool get_status() {return status;};
	chetirka* role_update();
	Role* get_role() { return role; };
private:
	int ages;
	int damage;
	int health;
	Role* role;
	static const int NURSE_AGE = 2;
	static const int SOLDIER_AGE = 5;
	static const int COLLECTOR_AGE = 10;
	static const int CLEANER_AGE = 15;
	bool status;
};
