#ifndef land__
#define land__
#include <iostream>

class land
{
public:
    void SetPlant(int type);
    int Plant() const { return plant_; }

private:
    int plant_ = -1; //default: Empty
    //plant
};

std::ostream &operator<<(std::ostream &os, const land &out);

#endif