#include <iostream>
#include "zombie.h"
using namespace std;

std::ostream &operator<<(std::ostream &os, const zombie &out)
{
    cout << "[" << out.ID() << "] Damage: " << out.DamagePoint()
         << " HP:" << string("*", out.LifePoint());
    return os;
}