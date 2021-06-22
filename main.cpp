#include <iostream>
#include <algorithm>
#include "map.h"
#include "player.h"
#include "zombie.h"
#include "land.h"
using namespace std;

int main()
{
    map m;
    cout << m;
    for (int i = 0; i < 3; i++)
    {
        m.EveryoneMove();
        cout << m;
    }
}