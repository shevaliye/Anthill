#include "informer.h"

void Informer::subscribe(int index)
{
	subscribers.push_back(index);
}

void Informer::unsubscribe(int index)
{
	for (int i = 0; i < subscribers.size(); i++)
	{
		if (subscribers[i] == index)
		{
			auto iter = subscribers.cbegin();
			subscribers.erase(iter + i);
		}
	}
}

void Informer::death_ant(int index)
{
	unsubscribe(index);
	for (int i = 0; i < subscribers.size(); i++)
	{
		if (subscribers[i] > index)
		{
			subscribers[i]--;
		}
		///!!!!!!!!
	}
}

