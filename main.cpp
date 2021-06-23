#include <iostream>
#include <algorithm>
#include "map.h"
#include "player.h"
#include "zombie.h"
#include "land.h"
using namespace std;

int main()
{
    map m(8, 3); //land, zombie
    cout << m;
    for (int i = 0; i < 2; i++)
    {
        m.PlayerMove(5);
        cout << m;
        for (int j = 0; j < m.Zombiecnt(); j++)
        {
            if (!m.ZombieisDead(j))
            {
                m.ZombieMove(j, 3);
                cout << m;
            }
        }
    }
    int tmp = m.ZombiePosition(0);
    m.PAttackZ(tmp, 0);
    m.PAttackZ(tmp, 0);
    m.PAttackZ(tmp, 0);
    m.PAttackZ(tmp, 0);
    cout << m;
}