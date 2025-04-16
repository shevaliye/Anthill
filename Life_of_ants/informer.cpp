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
	for (int i = 0; i < subscribers.size(); i++)
	{
		if (subscribers[i] == index)
		{
			unsubscribe(index);
			for (int x = i + 1; x < subscribers.size(); x++)
			{
				subscribers[x]--;
			}
			break;
		}
		if (subscribers[i] > index)
		{
			for (int x = i + 1; x < subscribers.size(); x++)
			{
				subscribers[x]--;
			}
			break;
		}
		///!!!!!!!!
	}
}

