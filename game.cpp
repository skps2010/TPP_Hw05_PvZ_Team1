#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.h"
#include "map.h"
#include "land.h"
#include "zombie.h"

Game::Game() : DEFAULTLAND(8), MAXLAND(10), DEFAULTZOMBIE(3), MAXZOMBIE(10), lastDecision(0)
{
    srand(time(NULL));
    // init the map
    logo();
    m = new map(setNumberOfLand(), setNumberOfZombie());
    rule();
    m->PlayerMove(rolldice(1, m->Landcnt()));
    for (size_t i = 0; i < m->Zombiecnt(); i++)
    {
        m->ZombieMove(i, rolldice(1, m->Landcnt()));
    }
    // read file
    std::ifstream ifs;
    ifs.open("plants.txt");
    char input = 0;
    while (ifs >> input)
    {
        dictionary.push_back(input);
        std::string name;
        ifs >> name;
        char dollarsign = 0;
        ifs >> dollarsign;
        if (input == 'B')
        {
            int cost = 0, hp = 0;
            ifs >> cost >> hp;
            m->B_Init(name, cost, hp);
        }
        else if (input == 'C')
        {
            int cost = 0, hp = 0, times = 0, coin = 0;
            ifs >> cost >> hp >> times >> coin;
            m->C_Init(name, cost, hp, times, coin);
        }
        else if (input == 'H')
        {
            int cost = 0, hp = 0, healpoint = 0;
            ifs >> cost >> hp >> healpoint;
            m->H_Init(name, cost, hp, healpoint);
        }
        else if (input == 'S')
        {
            int cost = 0, hp = 0, atk = 0;
            ifs >> cost >> hp >> atk;
            m->S_Init(name, cost, hp, atk);
        }
    }
    ifs.close();
    lastDecision = dictionary.size();
}

Game::~Game()
{
    delete m;
}

void Game::logo(void)
{
    std::cout << "┌─────────────────────────────────────────┐" << std::endl;
    std::cout << "│ TPP_2021 Hw05 Group1 Plants vs. Zombies │" << std::endl;
    std::cout << "└─────────────────────────────────────────┘" << std::endl;
    return;
}

void Game::rule(void)
{
    std::cout << "=============================================================================" << std::endl;
    std::cout << "Plants vs. Zombies Rule:" << std::endl;
    std::cout << "\nHow to win:\n\t(1) All zombies are dead.\n\t(2) At least one plant is live.\n\t(3) The number of dead bomb plants cannot exceed the number of zombies." << std::endl;
    std::cout << "\nHow to lose:\n\tAll plants are dead." << std::endl;
    std::cout << "=============================================================================" << std::endl;
    return;
}

void Game::showMap(void)
{
    std::cout << *m;
    return;
}

void Game::showPlants(void)
{
    for (size_t i = 0; i < dictionary.size(); i++)
    {
        std::cout << "[" << i << "]";
        m->PrintPlant(dictionary[i]);
        std::cout << std::endl;
    }
    return;
}

const int Game::setNumberOfLand(void)
{
    int NumOfLand = 0;
    std::cout << "Number of lands on the map (1-" << MAXLAND << ", default: " << DEFAULTLAND << ")...>";
    std::cin >> NumOfLand;
    if (NumOfLand > MAXLAND || NumOfLand <= 0)
    {
        NumOfLand = DEFAULTLAND;
    }
    return NumOfLand;
}

const int Game::setNumberOfZombie(void)
{
    int NumOfZombie = 0;
    std::cout << "Number of zombies on the map (1-" << MAXZOMBIE << ", default: " << DEFAULTZOMBIE << ")...>";
    std::cin >> NumOfZombie;
    if (NumOfZombie > MAXZOMBIE || NumOfZombie <= 0)
    {
        NumOfZombie = DEFAULTZOMBIE;
    }
    return NumOfZombie;
}

const int Game::rolldice(const int minimum, const int maximum)
{
    return (rand() % (maximum - minimum + 1)) + minimum;
}

void Game::gameloop(void)
{
    showMap();
    showPlants();
    std::cout << std::endl;
    m->PrintPlayer();
    std::cout << "Enter your choice (" << dictionary.size() << " to give up, default: " << lastDecision << ")...>";
    int decision = 0;
    std::cin >> decision;
    if (decision > dictionary.size() || decision < 0)
    {
        decision = lastDecision;
    }
    else
    {
        lastDecision = decision;
    }
    if (decision != dictionary.size())
    {
        std::cout << "You have planted " << dictionary.at(decision) << " at land " << m->PlayerPosition() << " !" << std::endl;
        m->SetPlant(m->PlayerPosition(), dictionary.at(decision));
    }
    else
    {
        std::cout << "You give up!" << std::endl;
    }
    // print coin and decision
    showMap();
    return;
}