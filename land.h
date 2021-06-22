#ifndef land__
#define land__
#include <iostream>

class land
{
public:
    void SetPlant(int type);
    int PlantId() const { return plantid_; }

private:
    int plantid_ = -1; //default: Empty
    //plant
};

std::ostream &operator<<(std::ostream &os, const land &out);

#endif