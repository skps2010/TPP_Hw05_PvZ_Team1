#include <iostream>
#include "land.h"
using namespace std;

std::ostream &operator<<(std::ostream &os, const land &out)
{
    if (out.PlantId() == -1)
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