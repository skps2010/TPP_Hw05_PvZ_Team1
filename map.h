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
    int Landcnt() const { return row_; }
    int Zombiecnt() const { return zombiecnt_; }
    bool ZombieisDead(const int id) const { return zombie_[id].isDead(); }
    int Plantcnt() const { return 0; } // not done yet
    void PrintPlayer() const;
    void PrintRow(const int i) const;
    void PrintZombie(const int id) const;
    int ZombieMove(const int id, const int step);
    int ZombiePosition(const int id);
    int PlayerMove(const int step);
    int PlayerPosition();
    void PAttackZ(int row, int zid);
    void ZAttackP(int row, int zid);
    int PlayerCoin() const { return player_.Coin(); }
    int Cost(const int m);

private:
    int row_ = 8;
    int zombiecnt_ = 3;
    player player_;
    zombie *zombie_;
    land *land_;
};

std::ostream &operator<<(std::ostream &os, const map &out);

#endif