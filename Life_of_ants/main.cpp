#include <iostream>
#include "anthill.h"
#include "Enemy.h"
#include <random>
#include <chrono>
#include <thread>

int main() {
    auto start = std::chrono::steady_clock::now();
    Anthill anthill;
    int heavy_branch = 0;
    int heavy_berry = 0;
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
            std::srand(std::time(0));
            int choice = std::rand() % 2;
            if (choice)
            {
                int heavy = std::rand() % 5;
                if (heavy == 0)
                {
                    if (anthill.get_count_informers(4))
                    {
                        std::cout << "heavy branch" << std::endl;
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
                    std::cout << "heavy berry" << std::endl;
                    heavy_berry = 50;
                    anthill.notify(3);
                }
            }
            else
            {
                berries = 30;
                anthill.workers(berries, 3);
            }
            anthill.eat();



            std::this_thread::sleep_for(std::chrono::seconds(1));

        }

        if (elapsed % 10 == 0 && elapsed != 0) {
            anthill.grow_ant();
            anthill.now_stay_active();
            anthill.add_food(heavy_berry);
            anthill.add_branch(heavy_branch);
            heavy_berry = 0;
            heavy_branch = 0;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        if (elapsed % 15 == 0 && elapsed != 0) {
            anthill.grow();
            std::cout << anthill.get_max_count() << std::endl;
            std::cout << anthill.get_size() << std::endl;
            std::cout << anthill.get_food() << std::endl;
            anthill.get_roles();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}