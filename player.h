#ifndef player__
#define player__
#include <iostream>

class player
{
public:
    int Coin() const { return coin_; }
    void Cost(const int i) { coin_ -= i; }
    int Position() const { return position_; }
    void Step(const int i, const int row) { position_ = (position_ + i) % row; }
    void Cost(const int m) { coin_ -= m; }

private:
    int coin_ = 150;
    int position_ = 0;
};

std::ostream &operator<<(std::ostream &os, const player &out);

#endif