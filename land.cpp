#include <iostream>
#include "land.h"
#include "plant.h"
using namespace std;

void land::PlantHurt(const int hp)
{
    p->attacked(hp);
    CheckAlive();
}

void land::CheckAlive()
{
    if (!alive(*p))
    {
        delete p;
        p = nullptr;
    }
}

std::ostream &operator<<(std::ostream &os, const land &out)
{
    if (out.isEmpty())
    {
        cout << "Empty";
    }
    else
    {
        out.PrintPlant(); //print plant
    }
    return os;
}