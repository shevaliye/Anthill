#include "anthill.h"
#include <random>
Anthill::Anthill()
{
	for (int i = 0; i < 6; i++)
	{
		Informer inf;
		informers.push_back(inf);
	}
	branches = 0;
	food = 0;
	size = 0;
	Ant *ant1 = new Ant(size++);
	Ant *ant2 = new Ant(size++);
	anthill.push_back(ant1);
	anthill.push_back(ant2);
	max_count = 100;
	max_food = 1000;
	food_count = 1000;
}

void Anthill::steal()
{
	if (food_count > 0) 
	{
		food_count-=5;
	}
}

void Anthill::grow()
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
	branches = 0;
	food = 0;
}
void Anthill::grow_ant()
{
	for (int i = 0; i < size; i++)
	{
		anthill[i]->grow();
		redistribution(i);
		if (anthill[i]->get_ages() > 20)
		{
			death_ant(i);
		}
	}
}
void Anthill::decrease()
{
	max_count -= 20;
	while (size > max_count)
	{
		auto iter = anthill.cbegin();
		delete anthill[0];
		anthill.erase(iter);
		size--;
	}
}
void Anthill::death_ant(int ind)
{
	for (int i = 0; i < 6; i++)
	{
		informers[i].death_ant(ind);
	}
	auto iter = anthill.cbegin();
	delete anthill[ind];
	anthill.erase(iter + ind);
	size--;

}
void Anthill::redistribution(int i)
{
	chetirka* chet = anthill[i]->role_update();
	if (chet->get_from() == -1)
	{
		if (chet->get_to() == -1)
		{
			return;
		}
		else
		{
			informers[chet->get_to()].subscribe(i);
		}
	}
	else
	{
		if (chet->get_from() != chet->get_to())
		{
			informers[chet->get_from()].unsubscribe(i);
			informers[chet->get_to()].subscribe(i);
		}
		else
		{
			return;
		}

	}
}
void Anthill::workers(int work, int ind_inf)
{
	for (int i = 0; i < size; i++)
	{
		if (anthill[i]->get_role() != nullptr)
		{
			if (anthill[i]->get_role()->get_number() == ind_inf && anthill[i]->get_status())
			{
				work--;
				anthill[i]->set_status(false);
			}
			if (work == 0)
			{
				break;
			}
		}
	}
}
Ant* Anthill::get_ant(int index) {
	if (index >= 0 && index < anthill.size()) {
		return anthill[index];
	}
	return nullptr;
}
void Anthill::now_stay_active()
{
	for (int i = 0; i < size; i++)
	{
		if (!anthill[i]->get_status())
		{
			anthill[i]->set_status(true);
			if (anthill[i]->get_role()->get_number() == 4)
			{
				branches++;
			}
			if (anthill[i]->get_role()->get_number() == 3)
			{
				food++;
			}
		}
	}
}
void Anthill::attacked(int id,int damage)
{
	if (anthill[id]->health_decrease(damage)<= 0)
	{
		death_ant(id);
	}
}
void Anthill::addant()
{
	if (size < max_count && food_count>0)
	{
		Ant* ant = new Ant(size++);
		anthill.push_back(ant);
	}
}
void Anthill::eat()
{
	if (food_count == 0)
	{
		starve();
	}
	else if(food_count<size/4)
	{
		food_count = 0;
	}
	else
	{
		food_count -= size/4;
	}
}
void Anthill::notify(int inf)
{
	for (int i = 0; i < informers[inf].get_size(); i++)
	{
		if (anthill[informers[inf].get_subscribers()[i]]->get_status())
		{
			anthill[informers[inf].get_subscribers()[i]]->set_status(false);
		}
	}
}
void Anthill::starve()
{
	for (int i = 0; i < size ; i++)
	{
		if (anthill[i]->health_decrease(5) <= 0)
		{
			death_ant(i);
		}
	}
}

void Anthill::add_food(int berry)
{
	food += berry;
}

void Anthill::add_branch(int branch)
{
	branches += branch;
}

int Anthill::get_count_informers(int inf)
{
	return informers[inf].get_size();
}

int Anthill::get_role_id(int id)
{
	if (anthill[id]->get_role() != nullptr)
	{
		return anthill[id]->get_role()->get_number();
	}
	return -1;
}

void Anthill::get_roles()
{
	vector<int> jobs(6,0);
	for (int i = 0; i < size; i++)
	{
		if (anthill[i]->get_role() != nullptr)
		{
			jobs[anthill[i]->get_role()->get_number()]++;
		}
	}
	cout << "Nurses: " << jobs[0] << endl;
	cout << "Soldiers: " << jobs[1] << endl;
	cout << "Shepherds: " << jobs[2] << endl;
	cout << "Collectors: " << jobs[3] << endl;
	cout << "Builders: " << jobs[4] << endl;
	cout << "Cleaners: " << jobs[5] << endl;
}

int Anthill::get_count_role(int inf)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (anthill[i]->get_role() != nullptr)
		{
			if (anthill[i]->get_role()->get_number() == inf)
			{
				count++;
			}
		}
	}
	return count;
}

int Anthill::damage_together()
{
	int res = 0;
	for (int i = 0; i < size; i++)
	{
		if (anthill[i]->get_role() != nullptr)
		{
			if (anthill[i]->get_role()->get_number() != 0)
			{
				res += anthill[i]->get_damage();
			}
		}
	}
	return res/2;
}



