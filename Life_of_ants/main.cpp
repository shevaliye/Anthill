#include <iostream>
#include "anthill.h"
#include "Enemy.h"
#include <random>
#include <chrono>
#include <thread>
#include "visual.h"

int main() {


    std::srand(std::time(0));
    auto start = std::chrono::steady_clock::now();
    Anthill anthill;
    Enemy* enemy = nullptr;
    int heavy_branch = 0;
    int heavy_berry = 0;

    // Запуск визуализации в отдельном потоке
    thread visualThread([&]() {
        Visualizer::visualize(anthill);
        });
    while (anthill.get_size()!=0) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
        if (elapsed % 1 == 0 && elapsed != 0) {
            anthill.addant();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        if (elapsed % 5 == 0 && elapsed != 0 ) {
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
                        //std::cout << "heavy branch" << std::endl;
                        heavy_branch = 20;
                        anthill.notify(4);
                    }
                }
                else
                {
                    branches = std::rand() % 10;
                    anthill.workers(branches,4);
                }  
            }
            int heavy = std::rand() % 5;
            if (heavy == 0)
            {
                if (anthill.get_count_informers(4))
                {
                    //std::cout << "heavy berry" << std::endl;
                    heavy_berry = 150;
                    anthill.notify(3);
                }
            }
            else
            {
                berries = 100;
                anthill.workers(berries, 3);
            }
            anthill.eat();
            if (enemy != nullptr)
            {
                int choice = std::rand() % 2;
                if (choice)
                {
                    enemy->attack(anthill);
                }
                else
                {
                    enemy->steal(anthill);
                }
                
            }
            //std::cout << anthill.get_max_count() << std::endl;
            //std::cout << anthill.get_size() << std::endl;
            //std::cout << anthill.get_food_count() << std::endl;
            //anthill.get_roles();


            std::this_thread::sleep_for(std::chrono::seconds(1));

        }

        if (elapsed % 9 == 0 && elapsed != 0) {
            anthill.grow_ant();
            if (enemy != nullptr)
            {
                if (enemy->get_health() <= 0)
                {
                    enemy = nullptr;
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
        if (elapsed % 14 == 0 && elapsed != 0) {
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
    visualThread.join();
    return 0;
}