#pragma once
#include <vector>
#include <iostream>

class Informer
{
public:
	void subscribe(int index);
	void unsubscribe(int index);
	void death_ant(int index);
	int get_size() { return subscribers.size(); };
	std::vector<int> get_subscribers() {return subscribers;};
private:
	std::vector<int> subscribers;
};
