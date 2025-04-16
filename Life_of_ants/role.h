#pragma once
#include <iostream>
class Role //-1
{
public:
	virtual void work() = 0;
	virtual int get_number() = 0;
};
class Nurse :public Role//0
{
public:
	void work() override
	{
		std::cout << 1;
	}
	int get_number() override { return 0; };

};
class Soldier :public Role//1
{
public:
	void work() override
	{
		std::cout << 1;
	}
	int get_number() override { return 1; };
};
class Shepherd :public Role//2
{
public:
	void work() override
	{
		std::cout << 1;
	}
	int get_number() override { return 2; };
};
class Collector :public Role//3
{
public:
	void work() override
	{
		std::cout << 1;
	}
	int get_number() override { return 3; };
};
class Builder :public Role//4
{
public:
	void work() override
	{
		std::cout << 1;
	}
	int get_number() override { return 4; };
};
class Cleaner :public Role//5
{
public:
	void work() override
	{
		std::cout << 1;
	}
	int get_number() override { return 5; };
};