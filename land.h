#ifndef land__
#define land__
#include <iostream>
#include "plant.h"

class land
{
public:
    void PrintPlant() const { std::cout << *p; }

    //void S_Init(std::string name, int cost, int hp, int atk) { ShootPlant::set(name, cost, hp, atk); }
    //void B_Init(std::string name, int cost, int hp) { BombPlant::set(name, cost, hp); };
    //void C_Init(std::string name, int cost, int hp, int time, int coin) { CoinPlant::set(name, cost, hp, time, coin); };
    //void H_Init(std::string name, int cost, int hp, int healpoint) { HealPlant::set(name, cost, hp, healpoint); }
    void SetPlant(const char T) { p = create_p(T); }
    bool isEmpty() const { return (p == nullptr); }
    int PlantCost() const { return p->showcost(); }
    int PlantMHP() const { return p->showmaxhp(); }
    int PlantHP() const { return p->showhp(); }
    int PlantDP() { return p->attack(); }
    void PlantHeal() { p->healed(); }
    void PlantHurt(int hp);
    void CheckAlive();
    std::string PlantName() { return p->showname(); }
    int PlantVisit() { return p->visit(); } //1: Coin 2: Heal
    bool PlantisReady() const { return p->isready(); }
    int PlantGet() { return p->get(); } //1:
    bool isOffensive() const { return p->isoffensive(); }

private:
    plant *p = nullptr;
    //plant
};

std::ostream &operator<<(std::ostream &os, const land &out);

#endif