#ifndef zombie__
#define zombie__
#include <iostream>

class zombie
{
public:
    zombie()
    {
        count_ += 1;
        idcount_ += 1;
        id_ = idcount_;
    }
    ~zombie() { count_ -= 1; }
    static int TotalNum() { return count_; }
    int ID() const { return id_; }
    int DamagePoint() const { return damage_point_; }
    int LifePoint() const { return life_point_; }

private:
    static int count_;
    static int idcount_;
    int id_;
    const int damage_point_ = 15;
    int life_point_ = 40;
};

std::ostream &operator<<(std::ostream &os, const zombie &out);

#endif