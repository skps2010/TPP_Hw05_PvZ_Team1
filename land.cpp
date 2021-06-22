#include <iostream>
#include "land.h"
using namespace std;

void land::PlantHurt(const int hp)
{
    //Not done yet
}

std::ostream &operator<<(std::ostream &os, const land &out)
{
    if (out.Plant() == -1)
    {
        cout << "Empty";
    }
    else
    {
        cout << "Print Plant (not done yet)";
        //print plant
    }
    return os;
}