#pragma once
class Role 
{
public:
	virtual void work() = 0;
};
class Nurse :public Role 
{
public:
	void work() override;

};
class Soldier :public Role
{
public:
	void work() override;

};
class Shepherd :public Role
{
public:
	void work() override;

};
class Collector :public Role
{
public:
	void work() override;

};
class Cleaner :public Role
{
public:
	void work() override;

};