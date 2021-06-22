#include <iostream>
#include <stdlib.h> // for rand
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
        if (zombie_[j].Position() == i)
            cout << j;
        else
            cout << ' ';
    }
    cout << '>';
    cout << land_[i] << "\n";
}

void map::PrintZombie(const int i) const
{
    cout << zombie_[i] << "\n";
}

void map::EveryoneMove()
{
    for (int i = 0; i < zombiecnt_; i++)
        zombie_[i].Step(rand() % 3 + 1, row_);
    player_.Step(rand() % 3 + 1, row_);
}

std::ostream &operator<<(std::ostream &os, const map &out)
{
    for (int i = 0; i < out.Row(); i++)
        out.PrintRow(i);
    cout << string(50, '-') << "\n"
         << "Zombie information:\n";
    for (int i = 0; i < out.Zombiecnt(); i++)
        out.PrintZombie(i);
    cout << string(50, '=') << "\n";
    //print plants
    out.PrintPlayer();
    return os;
}
