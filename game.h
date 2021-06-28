#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include "map.h"
#include "land.h"
#include "zombie.h"

class Game
{
private:
    const int DEFAULTLAND = 8;
    const int MAXLAND = 10;
    const int DEFAULTZOMBIE = 3;
    const int MAXZOMBIE = 10;
    int lastDecision = 0;
    int gamestatus = 0;
    int plantUnderthePlayer = -1;
    std::vector<char> dictionary;
    map *m = nullptr;
    void logo(void);
    void rule(void);
    void showMap(void);
    void showPlants(void);
    void makeDecision(void);
    const int setNumberOfLand(void);
    const int setNumberOfZombie(void);
    const int rolldice(const int minimum, const int maximum);

public:
    Game();
    ~Game();
    void gameloop(void);
};

#endif