#include <iostream>
#include "anthill.h"
#include <vector>
#include <string>
#include "Enemy.h"

void Events(std::vector<std::string>& events, const std::string& message)
{
	events.push_back(message);
}

void ShowEvents(std::vector<std::string>& events)
{
	std::cout << "Current Events" << std::endl;
	for (int i = 0; i < events.size(); i++)
	{
		std::cout << events[i] << std::endl;
	}
}

void AnthillInfo(Anthill& anthill, Enemy* enemy, std::vector<std::string>& events)
{
	std::cout << "Information about the anthill" << std::endl;
	std::cout << "Size: " << anthill.get_size() << std::endl;
	std::cout << "MAX_Size: " << anthill.get_max_count() << std::endl;
	std::cout << "Food: " << anthill.get_food_count() << std::endl;
	//std::cout << "Berry: " << anthill.get_food() << std::endl;
	//std::cout << "Branches: " << anthill.get_branches() << std::endl;

	std::cout << "\n";

	std::cout << "Information about the roles of ants" << std::endl;
	//std::cout << "Children" << anthill.get_count_role() << " ant(s)" << std::endl;
	std::cout << "Nurses: " << anthill.get_count_role(0) << " ant(s)" << std::endl;
	std::cout << "Soldiers: " << anthill.get_count_role(1) << " ant(s)" << std::endl;
	std::cout << "Shepherds: " << anthill.get_count_role(2) << " ant(s)" << std::endl;
	std::cout << "Collectors: " << anthill.get_count_role(3) << " ant(s)" << std::endl;
	std::cout << "Builders: " << anthill.get_count_role(4) << " ant(s)" << std::endl;
	std::cout << "Cleaners: " << anthill.get_count_role(5) << " ant(s)" << std::endl;

	std::cout << "\n";

	ShowEvents(events);

	std::cout << "\n";

	if (enemy != nullptr)
	{
		std::cout << "Enemy" << std::endl;
		std::cout << "Health: " << enemy->get_health() << std::endl;
		std::cout << "Damage: " << enemy->get_damage() << std::endl;
	}
}

void visualize(Anthill& anthill, Enemy* enemy, std::vector<std::string>& events)
{
	system("cls"); // Очищаем терминал перед следующим выводом
	AnthillInfo(anthill, enemy, events);

}