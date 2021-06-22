#ifndef player__
#define player__
#include <iostream>

class player
{
public:
    player() : coin_(100){};
    player(int const coin) : coin_(coin){};
    ~player();

private:
    int coin_;
};

#endif