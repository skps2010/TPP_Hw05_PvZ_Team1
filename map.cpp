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
    cout << '<' << (player_.Posotion() == i ? '*' : ' ');
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

std::ostream &operator<<(std::ostream &os, const map &out)
{
    for (int i = 0; i < out.Row(); i++)
        out.PrintRow(i);
    cout << string(50, '-') << "\n"
         << "Zombie information:\n";
    for (int i = 0; i < out.Zombiecnt(); i++)
        out.PrintZombie(i);
    return os;
}
