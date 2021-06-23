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
    virtual void visit();   //test
    void attacked(int atk);
    void healed();
protected:
    static void sethealpoint(int healpoint);
private:
    std::string name_;
    int cost_;
    int maxhp_;
    int remainhp_;
    int atk_;
    static int healpoint_;
};

class Hornflower : public plant
{
public:
    static void set(std::string name, int cost, int hp, int atk);
    Hornflower();
    //virtual void visit() override ;
    virtual void visit() override {std::cout << "b" << std::endl;} //test
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
    static int atk_;
};

class Bombflower : public plant
{
public:
    static void set(std::string name,int cost, int hp);
    Bombflower();
    ~Bombflower() ;
    static int showused() ;
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
    static int used_;
};

class Mushroom : public plant
{
public:
    static void set(std::string name, int cost, int hp, int time, int coin);
    Mushroom();
    //virtual void visit() override {std::cout << "c" << std::endl;}
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
    static int maxtime_;
    static int reward_;
    int time = 0;
};

class Healflower : public plant
{
public:
    static void set(std::string name, int cost, int hp, int healpoint);
    Healflower();
    //virtual void visit() override {std::cout << "c" << std::endl;}
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
};

plant* create(char c);

bool alive (plant* pl);

std::ostream & operator << (std::ostream &os, const plant *rhs);


