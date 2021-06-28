#include<string>
#include<iostream>
#include"plant.h"

using namespace std;

//static*************************************************************************

int plant::healpoint_ = 20;

string ShootPlant::name_ = "Hornflower";

int ShootPlant::cost_ = 50;

int ShootPlant::maxhp_ = 50;

int ShootPlant::atk_ = 10;

string BombPlant::name_ = "Bombflower";

int BombPlant::cost_ = 50;

int BombPlant::maxhp_ = 30;

int BombPlant::used_ = 0;

string CoinPlant::name_ = "Mushroom";

int CoinPlant::cost_ = 25;

int CoinPlant::maxhp_ = 50;

int CoinPlant::maxtime_ = 2;

int CoinPlant::reward_ = 25;

string HealPlant::name_ = "Healflower";

int HealPlant::cost_ = 25;

int HealPlant::maxhp_ = 50;

int HealPlant::healpoint_ = 20;

//plant************************************************************************************************************************

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


void plant::showskill() const
{

}

int plant::visit()
{
    return 0;
}

bool plant::isready() const
{
    return false;
}

int plant::get()
{
    return -1;
}

int plant::attack()
{
    atk_impl();
    return plant::showatk();
}

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

void  plant::atk_impl()
{

}

//Shoot***************************************************************************

void ShootPlant::set(string name, int cost, int hp, int atk)
{
    name_ = name;
    cost_ = cost;
    maxhp_ = hp;
    atk_ = atk;
}

ShootPlant::ShootPlant(): plant(name_,cost_,maxhp_,atk_)
{

}

void ShootPlant::print()
{
    cout << name_  << " $"<< cost_ << " HP: " << maxhp_ << " - gives " << atk_ << " damage points" ;
}

//Bomb*************************************************************************************************

void BombPlant::set(string name,int cost, int hp)
{
    name_ = name;
    cost_ = cost;
    maxhp_ = hp;
}

BombPlant::BombPlant(): plant(name_,cost_,maxhp_,maxhp_)
{

}

BombPlant::~BombPlant()
{
    used_+=1;
}

int BombPlant::showused()
{
    return used_;
}

void BombPlant::print()
{
    cout << name_  << " $"<< cost_ << " HP: " << maxhp_ << " - gives " << maxhp_ << " damage points" ;
}

void BombPlant::atk_impl()
{
    this->attacked(this->showhp());
}

//Coin*****************************************************************************************************

void CoinPlant::set(string name, int cost, int hp, int time, int coin)
{
    name_ = name;
    cost_ = cost;
    maxhp_ = hp;
    maxtime_ = time;
    reward_ = coin;
}

CoinPlant::CoinPlant() : plant(name_,cost_,maxhp_,0)
{
    time_ = maxtime_;
}

int CoinPlant::visit()
{
    time_-=1;
    return 1;
}

bool CoinPlant::isready() const
{
    return !time_;
}

int CoinPlant::get()
{
    if(time_)
    {
        return time_;
    }
    time_ = maxtime_;
    return reward_;
}
void CoinPlant::showskill() const
{
    cout << " (" << time_ << " more visits)";
}

void CoinPlant::print()
{
    cout << name_  << " $"<< cost_ << " HP: " << maxhp_ << " - gives $" << reward_ << " every " << maxtime_ << " rounds";
}

//Heal**********************************************************************************************************************

void HealPlant::set(string name, int cost, int hp, int healpoint)
{
    name_ = name;
    cost_ = cost;
    maxhp_ = hp;
    healpoint_ = healpoint;
    sethealpoint(healpoint);
}

HealPlant::HealPlant() : plant(name_,cost_,maxhp_,0)
{

}

int HealPlant::visit()
{
    return 2;
}

void HealPlant::print()
{
    cout << name_  << " $"<< cost_ << " HP: " << maxhp_ << " - gives all your plants " << healpoint_ << " HP back";
}

//non-class**************************************************************************************************************

plant* create_p(char type)
{
    plant* temp = nullptr;
    switch(type)
    {
    case 'S':
        temp = new ShootPlant;
        break;
    case 'B':
        temp = new BombPlant;
        break;
    case 'C':
        temp = new CoinPlant;
        break;
    case 'H':
        temp = new HealPlant;
        break;
    }
    return temp;
}

plant& create_r(char type)
{
    plant* temp = nullptr;
    switch(type)
    {
    case 'S':
        temp = new ShootPlant;
        break;
    case 'B':
        temp = new BombPlant;
        break;
    case 'C':
        temp = new CoinPlant;
        break;
    case 'H':
        temp = new HealPlant;
        break;
    }
    return *temp;
}

bool alive (const plant& pl)
{
    if(pl.showhp()<=0)
    {
        return false;
    }
    return true;
}

ostream & operator << (ostream &os, const plant &rhs)
{
    os << rhs.showname() << " HP: " << rhs.showhp() ;
    rhs.showskill();
    return os;
}

void show(char type)
{
    switch(type)
    {
    case 'S':
        ShootPlant::print();
        break;
    case 'B':
        BombPlant::print();
        break;
    case 'C':
        CoinPlant::print();
        break;
    case 'H':
        HealPlant::print();
        break;
    }
}
