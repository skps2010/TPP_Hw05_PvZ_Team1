#ifndef land__
#define land__
#include <iostream>

class land
{
public:
    void SetPlant(int type);
    int Plant() const { return plant_; }
    int PlantHP() const { return 30; }
    int PlantDP() const { return 15; }
    void PlantHurt(const int hp);
    void PlantClear(); // when it's dead

private:
    int plant_ = -1; //default: Empty
    //plant
};

std::ostream &operator<<(std::ostream &os, const land &out);

#endif