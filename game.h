#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

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
    map *m = nullptr;
    void logo(void);
    void rule(void);
    const int setNumberOfLand(void);
    const int setNumberOfZombie(void);

public:
    Game();
    ~Game();
};

#endif