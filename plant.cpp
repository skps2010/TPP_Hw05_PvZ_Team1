#include"plant.h"
using namespace std;

plant::plant(string name,int cost,int maxhp,int atk) :name_(name), cost_(cost), maxhp_(maxhp), remainhp_(maxhp), atk_(atk){}

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
    /*case 'C':

        break;
    case 'H':

        break;*/
    }
    return temp;
}

ostream & operator << (ostream &os, const plant *rhs)
{
    os << rhs->showname() << " HP: " << rhs->showhp();
    return os;
}
