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
    virtual void showskill() const;
    virtual int visit();
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
    static void print();
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
    static void print();
protected:
    virtual void  atk_impl() override;
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
    virtual int visit() override;
    bool isready() const;
    int get() ;
    virtual void showskill() const override;
    static void print();
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
    static int maxtime_;
    static int reward_;
    int time_ = -1;
};

class HealPlant : public plant
{
public:
    static void set(std::string name, int cost, int hp, int healpoint);
    HealPlant();
    virtual int visit() override;
    static void print();
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
    static int healpoint_;
};

plant* create_p(char type);

plant& create_r(char type);

bool alive (const plant& pl);

std::ostream & operator << (std::ostream &os, const plant &rhs);

void show(char type);


#endif
