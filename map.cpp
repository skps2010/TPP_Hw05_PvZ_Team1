#include <iostream>
#include "map.h"
using namespace std;

void map::PrintPlayer() const
{
    cout << player_;
}

void map::PrintRow(const int i) const
{
    cout << '[' << i << ']';
    cout << '<' << (player_.Position() == i ? '*' : ' ');
    for (int j = 0; j < Zombiecnt(); j++)
    {
        if (!zombie_[j].isDead())
        {
            if (zombie_[j].Position() == i)
                cout << j;
            else
                cout << ' ';
        }
    }
    cout << '>';
    cout << land_[i] << "\n";
}

void map::PrintZombie(const int id) const
{
    if (!zombie_[id].isDead())
        cout << zombie_[id] << "\n";
}

int map::ZombieMove(const int id, const int step)
{
    zombie_[id].Step(step, row_);
    return zombie_[id].Position();
}

int map::ZombiePosition(const int id)
{
    return zombie_[id].Position();
}

int map::PlayerMove(const int step)
{
    player_.Step(step, row_);
    return player_.Position();
}

int map::PlayerPosition()
{
    return player_.Position();
}

void map::PAttackZ(int row, int zid)
{
    int tmp = land_[row].PlantDP();
    zombie_[zid].Hurt(tmp);
}

void map::ZAttackP(int row, int zid)
{
    int tmp = zombie_[zid].DamagePoint();
    land_[row].PlantHurt(tmp);
}

std::ostream &operator<<(std::ostream &os, const map &out)
{
    for (int i = 0; i < out.Landcnt(); i++)
        out.PrintRow(i);
    cout << string(50, '-') << "\n"
         << "Zombie information:\n";
    for (int i = 0; i < out.Zombiecnt(); i++)
        out.PrintZombie(i);
    cout << string(50, '=') << "\n";
    return os;
}
