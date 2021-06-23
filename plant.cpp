#include<string>
#include<iostream>
#include"plant.h"

using namespace std;

int plant::healpoint_ = 20;

string Hornflower::name_ = "Hornflower";

int Hornflower::cost_ = 50;

int Hornflower::maxhp_ = 50;

int Hornflower::atk_ = 10;

string Bombflower::name_ = "Bombflower";

int Bombflower::cost_ = 50;

int Bombflower::maxhp_ = 30;

int Bombflower::used_ = 0;

string Mushroom::name_ = "Mushroom";

int Mushroom::cost_ = 25;

int Mushroom::maxhp_ = 50;

int Mushroom::maxtime_ = 2;

int Mushroom::reward_ = 25;

string Healflower::name_ = "Healflower";

int Healflower::cost_ = 25;

int Healflower::maxhp_ = 50;

plant::plant(string name,int cost,int maxhp,int atk) :name_(name), cost_(cost), maxhp_(maxhp), remainhp_(maxhp), atk_(atk)
{

}

plant::~plant()
{

}

string plant::showname() const
{
    return name_;
}

int plant::showcost() const
{
    return cost_;
}

int plant::showmaxhp() const
{
    return maxhp_;
}

int plant::showhp() const
{
    return remainhp_;
}

int plant::showatk() const
{
    return atk_;
}

void plant::visit()  {cout << "a" << endl;}

void plant::attacked(int atk)
{
    remainhp_ -= atk;
}

void plant::healed()
{
    remainhp_ += healpoint_;
    if(remainhp_>maxhp_)
    {
        remainhp_ = maxhp_;
    }
}

void plant::sethealpoint(int healpoint)
{
    healpoint_ = healpoint;
}

void Hornflower::set(string name, int cost, int hp, int atk)
{
    name_ = name;
    cost_ = cost;
    maxhp_ = hp;
    atk_ = atk;
}

Hornflower::Hornflower(): plant(name_,cost_,maxhp_,atk_)
{

}


void Bombflower::set(string name,int cost, int hp)
{
    name_ = name;
    cost_ = cost;
    maxhp_ = hp;
}

Bombflower::Bombflower(): plant(name_,cost_,maxhp_,maxhp_)
{

}

Bombflower::~Bombflower()
{
    used_+=1;
}

int Bombflower::showused()
{
    return used_;
}

void Mushroom::set(string name, int cost, int hp, int time, int coin)
{
    name_ = name;
    cost_ = cost;
    maxhp_ = hp;
    maxtime_ = time;
    reward_ = coin;
}

Mushroom::Mushroom() : plant(name_,cost_,maxhp_,0)
{

}

void Healflower::set(string name, int cost, int hp, int healpoint)
{
    name_ = name;
    cost_ = cost;
    maxhp_ = hp;
    sethealpoint(healpoint);
}

Healflower::Healflower() : plant(name_,cost_,maxhp_,0)
{

}


plant* create(char c)
{
    plant* temp = nullptr;
    switch(c)
    {
    case 'S':
        temp = new Hornflower;
        break;
    case 'B':
        temp = new Bombflower;
        break;
    case 'C':
        temp = new Mushroom;
        break;
    case 'H':
        temp = new Healflower;
        break;
    }
    return temp;
}

bool alive (plant* pl)
{
    if(pl->showhp()<=0)
    {
        return false;
    }
    return true;
}


std::ostream & operator << (std::ostream &os, const plant *rhs)
{
    os << rhs->showname() << " HP: " << rhs->showhp();
    return os;
}


