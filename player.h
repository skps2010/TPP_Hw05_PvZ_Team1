#ifndef player__
#define player__
#include <iostream>

class player
{
public:
    int Coin() const { return coin_; }
    int Posotion() const { return position_; }

private:
    int coin_ = 150;
    int position_ = 0;
};

std::ostream &operator<<(std::ostream &os, const player &out);

#endif