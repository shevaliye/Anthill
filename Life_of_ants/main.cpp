#include <iostream>
#include "anthill.h"
#include "Enemy.h"
#include <random>
#include <chrono>
#include <thread>
#include "graphics.cpp"

int main() {
    std::srand(std::time(0));
    auto start = std::chrono::steady_clock::now();
    Anthill anthill;
    Enemy* enemy = nullptr;
    int heavy_branch = 0;
    int heavy_berry = 0;
    bool flag = true;
    while (anthill.get_size()!=0) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
        if (elapsed % 1 == 0 && elapsed != 0) {
            anthill.addant();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        if (elapsed % 5 == 0 && elapsed != 0 ) {
            std::vector<std::string> events;
            int branches;
            int berries;
            int choice = std::rand() % 2;
            if (choice)
            {
                int heavy = std::rand() % 5;
                if (heavy == 0)
                {
                    if (anthill.get_count_informers(4))
                    {
                        Events(events, "Heavy branch");
                        //std::cout << "heavy branch" << std::endl;
                        heavy_branch = 20;
                        anthill.notify(4);
                    }
                }
                else
                {
                    Events(events, "branch");
                    branches = std::rand() % 10;
                    anthill.workers(branches,4);
                }  
            }
            int heavy = std::rand() % 5;
            if (heavy == 0)
            {
                if (anthill.get_count_informers(4))
                {
                    Events(events, "Heavy berry");
                    //std::cout << "heavy berry" << std::endl;
                    heavy_berry = 150;
                    anthill.notify(3);
                }
            }
            else
            {
                Events(events, "berry");
                berries = 100;
                anthill.workers(berries, 3);
            }
            anthill.eat();
            visualize(anthill, enemy, events);
            if (enemy != nullptr && enemy->get_health()>0) 
            {
                int choice = std::rand() % 2;
                if (choice && flag)
                {
                    enemy->steal(anthill);
                }
                else
                {
                    enemy->attack(anthill);
                    flag = false;
                }
                
            }
            //std::cout << anthill.get_max_count() << std::endl;
            //std::cout << anthill.get_size() << std::endl;
            //std::cout << anthill.get_food_count() << std::endl;
            //anthill.get_roles();


            std::this_thread::sleep_for(std::chrono::seconds(1));

            
        }

        if (elapsed % 11 == 0 && elapsed != 0) {
            anthill.grow_ant();
            if (enemy != nullptr)
            {
                if (enemy->get_health() == 0)
                {
                    enemy = nullptr;
                    flag = true;
                    //std::cout << "enemy died" << std::endl;
                }

            }
            anthill.now_stay_active();
            anthill.add_food(heavy_berry);
            anthill.add_branch(heavy_branch);
            heavy_berry = 0;
            heavy_branch = 0;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        if (elapsed % 15 == 0 && elapsed != 0) {
            if (anthill.get_count_informers(4) && anthill.get_branches() == 0)
            {
                anthill.decrease();
            }
            if ((anthill.get_branches() > 0 || anthill.get_food()>0))
            {
                anthill.grow();
            }
            if (anthill.get_count_informers(1))
            {
                int choice = std::rand() % 2;
                if (choice && enemy == nullptr)
                {
                    enemy = new Enemy;
                    //std::cout << "enemy appeared" << std::endl;
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}