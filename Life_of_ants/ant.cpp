#include "ant.h"
Ant::Ant(int ind)
{
    status = true;
    damage = 1;
    ages = 0;
    int random_choice = std::rand() % 2;
    health = (random_choice == 0) ? 50 : 100;
    role = nullptr;
}

void Ant::grow()
{
    ages++;
}

int Ant::health_decrease(int damage)
{
    health -= damage;
    return health;
}

void Ant::set_status(bool stat)
{
    status = stat;
}

chetirka* Ant::role_update()
{
    if (ages < NURSE_AGE)
    {
        chetirka* func = new chetirka(-1, -1);
        return func;
    }
       
    if (ages >= NURSE_AGE && ages < SOLDIER_AGE)
    {
        if (role == nullptr)
        {
            chetirka* func = new chetirka(-1, 0);
            role = new Nurse;
            return func;
        }
        else
        {
            chetirka* func = new chetirka(-1, -1);
            return func;
        }

    }
    if (ages >= SOLDIER_AGE && ages < COLLECTOR_AGE)
    {
        if (role->get_number() == 1 || role->get_number() == 2)
        {
            chetirka* func = new chetirka(-1, -1);
            return func;
        }
        else
        {
            if (health <= 50)
            {
                chetirka* func = new chetirka(role->get_number(), 2);
                delete role;
                role = new Shepherd;
                return func;
            }
            else
            {
                chetirka* func = new chetirka(role->get_number(), 1);
                delete role;
                role = new Soldier;
                damage = 6;
                return func;
            }
        }
    }
    if (ages >= COLLECTOR_AGE && ages < CLEANER_AGE)
    {
        if (role->get_number() == 3 || role->get_number() == 4)
        {
            chetirka* func = new chetirka(-1, -1);
            return func;
        }
        else
        {
            int random_choice = std::rand() % 100;
            if (random_choice < 50)
            {
                chetirka* func = new chetirka(role->get_number(), 3);
                delete role;
                role = new Collector;
                return func;
            }
            chetirka* func = new chetirka(role->get_number(), 4);
            delete role;
            role = new Builder;
            return func;
        }

    }
    if (role->get_number() == 5)
    {
        chetirka* func = new chetirka(-1, -1);
        return func;
    }
    chetirka* func = new chetirka(role->get_number(), 5);
    delete role;
    role = new Cleaner;
    return func;
}

