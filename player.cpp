#include <iostream>
#include "player.h"
using namespace std;

std::ostream &operator<<(std::ostream &os, const player &out)
{
    cout << "Player coin: " << out.Coin() << "    ";

    return os;
}