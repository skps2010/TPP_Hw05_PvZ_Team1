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
    if (!land_[player_.Position()].isEmpty())
    {
        int tmp = land_[player_.Position()].PlantVisit();
        PlantUpdate(player_.Position());
        if (tmp == 1) // Coin
        {
            if (land_[player_.Position()].PlantisReady())
            {
                Cost(-land_[player_.Position()].PlantGet());
            }
        }
        if (tmp == 2) // Heal
        {
            for (int i = 0; i < row_; i++)
            {
                land_[i].PlantHeal();
            }
        }
        return tmp;
    }
    else
        return -1;
}

int map::PlayerPosition()
{
    return player_.Position();
}

void map::PAttackZ(int row, int zid)
{
    int tmp = land_[row].PlantDP();
    if (!zombie_[zid].isDead())
        zombie_[zid].Hurt(tmp);
    land_[row].CheckAlive();
}

void map::ZAttackP(int row, int zid)
{
    int tmp = zombie_[zid].DamagePoint();
    if (!land_[row].isEmpty())
    {
        land_[row].PlantHurt(tmp);
    }
}

int map::Plantcnt() const
{
    int tmp;
    for (int i = 0; i < row_; ++i)
    {
        if (!land_[i].isEmpty())
            tmp++;
    }
    return tmp;
}

void map::PlantHeal()
{
    for (int i = 0; i < row_; ++i)
        if (!land_[i].isEmpty())
            land_[i].PlantHeal();
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
