#include "ant.h"
#include <random>
Ant::Ant()
{
    ages = 0;
    std::srand(std::time(0));
    int random_choice = std::rand() % 2;
    health = (random_choice == 0) ? 50 : 100;
}

void Ant::grow()
{
    ages++;
    role_update();
}

void Ant::role_update()
{
    if (ages < NURSE_AGE) return;
    if (ages >= NURSE_AGE && ages < SOLDIER_AGE)
    {
        Nurse nurse;
        role = &nurse;
        return;
    }
    if (ages >= SOLDIER_AGE && ages <COLLECTOR_AGE)
    {
        if (health <= 50)
        {
            Shepherd shepherd;
            role = &shepherd;
        }
        else
        {
            Soldier soldier;
            role = &soldier;
        }
        return;
    }
    if (ages >= COLLECTOR_AGE && ages < CLEANER_AGE)
    {
        Collector collector;
        role = &collector;
        return;
    }
    Cleaner cleaner;
    role = &cleaner;
}
