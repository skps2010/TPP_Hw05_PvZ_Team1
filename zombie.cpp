#include <iostream>
#include "zombie.h"
using namespace std;

int zombie::count_ = 0;
int zombie::idcount_ = 0;

void zombie::Hurt(const int hp)
{
    life_point_ -= hp;
    if (life_point_ < 0)
        life_point_ = 0;
}

std::ostream &operator<<(std::ostream &os, const zombie &out)
{
    cout << "[" << out.ID() << "] Damage:" << out.DamagePoint()
         << " HP:"
         << string(out.LifePoint(), '*');
    return os;
}