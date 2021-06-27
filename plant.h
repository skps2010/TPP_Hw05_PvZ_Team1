#ifndef plant__
#define plant__
#include<iostream>
class plant
{
public:
    plant(std::string name,int cost,int maxhp,int atk);
    virtual ~plant();
    std::string showname() const;
    int showcost() const;
    int showmaxhp() const;
    int showhp() const;
    int showatk() const;
    virtual void showskill() const;   //test
    int attack();
    void attacked(int atk);
    void healed();
protected:
    static void sethealpoint(int healpoint);
    virtual void  atk_impl();

private:
    std::string name_;
    int cost_;
    int maxhp_;
    int remainhp_;
    int atk_;
    static int healpoint_;
};

class ShootPlant : public plant
{
public:
    static void set(std::string name, int cost, int hp, int atk);
    ShootPlant();
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
    static int atk_;
};

class BombPlant : public plant
{
public:
    static void set(std::string name,int cost, int hp);
    BombPlant();
    ~BombPlant() ;
    static int showused() ;
protected:
    virtual void  atk_impl() override ;
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
    static int used_;
};

class CoinPlant : public plant
{
public:
    static void set(std::string name, int cost, int hp, int time, int coin);
    CoinPlant();
    virtual void showskill() const override ;
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
    static int maxtime_;
    static int reward_;
    int time_ = 0;
};

class HealPlant : public plant
{
public:
    static void set(std::string name, int cost, int hp, int healpoint);
    HealPlant();
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
};

plant* create_p(char type);

plant& create_r(char type);

bool alive (const plant& pl);

std::ostream & operator << (std::ostream &os, const plant &rhs);


#endif
