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
    void PrintPlayer() const;
    void PrintRow(const int i) const;
    void PrintZombie(const int id) const;
    void PrintPlant(const char T) const { show(T); }

    int Landcnt() const { return row_; }
    int Zombiecnt() const { return zombiecnt_; }

    bool ZombieisDead(const int id) const { return zombie_[id].isDead(); }
    int ZombieMove(const int id, const int step);
    int ZombiePosition(const int id);

    int PlayerMove(const int step);
    int PlayerPosition();
    int PlayerCoin() const { return player_.Coin(); }
    void Cost(const int m) { player_.Cost(m); }

    void S_Print() const {};
    void B_Print() const {};
    void C_Print() const {};
    void H_Print() const {};

    void S_Init(std::string name, int cost, int hp, int atk) { ShootPlant::set(name, cost, hp, atk); }
    void B_Init(std::string name, int cost, int hp) { BombPlant::set(name, cost, hp); };
    void C_Init(std::string name, int cost, int hp, int time, int coin) { CoinPlant::set(name, cost, hp, time, coin); };
    void H_Init(std::string name, int cost, int hp, int healpoint) { HealPlant::set(name, cost, hp, healpoint); }
    int B_Used() { return BombPlant::showused(); } //炸彈炸過幾次

    std::string SetPlant(int row, const char T)
    {
        land_[row].SetPlant(T);
        return land_[row].PlantName();
    }
    bool LandisEmpty(int row) const { return land_[row].isEmpty(); }
    std::string PlantName(int row) const { return land_[row].PlantName(); }
    char PlantType(int row) const { return land_[row].PlantName()[0]; }
    int PlantCost(int row) const { return land_[row].PlantCost(); }
    int PlantMHP(int row) const { return land_[row].PlantMHP(); }
    int PlantHP(int row) const { return land_[row].PlantHP(); }
    int PlantDP(int row) const { return land_[row].PlantDP(); }
    void PlantHurt(int row, int hp) { land_[row].PlantHurt(hp); }
    bool PlantisReady(int row) { return land_[row].PlantisReady(); }
    int PlantVisit(int row) { return land_[row].PlantVisit(); }
    int PlantStatus(int row) { return land_[row].PlantGet(); }
    // HealPlant: Heal point
    // CoinPlant: 剩餘回合(NotReady) or 拿到的錢(isReady)
    bool PlantisOffensive(int row) const { return land_[row].isOffensive(); }

    void PAttackZ(int row, int zid);
    void ZAttackP(int row, int zid);
    void PlantHeal();
    int Plantcnt() const;

private:
    int row_ = 8;
    int zombiecnt_ = 3;
    player player_;
    zombie *zombie_;
    land *land_;
};

std::ostream &operator<<(std::ostream &os, const map &out);

#endif