#include<string>
#include<iostream>

class plant
{
public:
    plant(std::string name,int cost,int maxhp,int atk);
    //plant(std::string name,int cost,int maxhp,int atk) :name_(name), cost_(cost), maxhp_(maxhp), remainhp_(maxhp), atk_(atk){}
    //plant(int cost,int maxhp,int atk) : cost_(cost), maxhp_(maxhp), remainhp_(maxhp), atk_(atk){}
    virtual ~plant() {}
    std::string showname() const {return name_;}
    int showcost() const {return cost_;}
    int showmaxhp() const {return maxhp_;}
    int showhp() const {return remainhp_;}
    int showatk() const {return atk_;}
    virtual void visit()  {std::cout << "a" << std::endl;}
    static constexpr int attacked = -15;
protected:

private:
    std::string name_;
    int cost_;
    int maxhp_;
    int remainhp_;
    int atk_;
};

class Hornflower : public plant
{
public:
    static void set(std::string name, int cost, int hp, int atk){name_ = name,cost_ = cost,maxhp_ = hp,atk_ = atk;};
    Hornflower(): plant(name_,cost_,maxhp_,atk_){}
    virtual void visit() override {std::cout << "b" << std::endl;}
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
    static int atk_;
};
std::string Hornflower::name_ = "Hornflower";
int Hornflower::cost_ = 50;
int Hornflower::maxhp_ = 50;
int Hornflower::atk_ = 10;



class Bombflower : public plant
{
public:
    static void set(std::string name,int cost, int hp){name_ = name,cost_ = cost,maxhp_ = hp;};
    Bombflower(): plant(name_,cost_,maxhp_,maxhp_){}
    ~Bombflower() {used_+=1;}
    static int showused() {return used_;};
private:
    static std::string name_;
    static int cost_;
    static int maxhp_;
    static int used_;
};
std::string Bombflower::name_ = "Bombflower";
int Bombflower::cost_ = 50;
int Bombflower::maxhp_ = 30;
int Bombflower::used_ = 0;


plant* create(char c);



std::ostream & operator << (std::ostream &os, const plant *rhs);

