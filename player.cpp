#include <iostream>
#include "player.h"
using namespace std;

std::ostream &operator<<(std::ostream &os, const player &out)
{
    cout << "Player coin: " << out.Coin() << " Enter your choice (4 to give up, default: 4): ";

    return os;
}