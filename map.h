#ifndef map__
#define map__
#include <iostream>
#include "land.h"
#include "zombie.h"
#include "player.h"

class map
{
public:
    map() : row_(8), zombiecnt_(3), land_(new land[row_]()), zombie_(new zombie[zombiecnt_]()){};
    map(const int row, const int zombiecnt) : row_(row), zombiecnt_(zombiecnt), land_(new land[row_]()), zombie_(new zombie[zombiecnt_]()) {}
    ~map()
    {
        delete[] land_;
        delete[] zombie_;
    }
    int Row() const { return row_; }
    int Zombiecnt() const { return zombiecnt_; }
    void PrintPlayer() const;
    void PrintRow(const int i) const;
    void PrintZombie(const int i) const;
    void EveryoneMove();

private:
    int row_ = 8;
    int zombiecnt_ = 3;
    player player_;
    zombie *zombie_;
    land *land_;
};

std::ostream &operator<<(std::ostream &os, const map &out);

#endif