#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "map.h"
#include "land.h"
#include "zombie.h"

Game::Game() : DEFAULTLAND(8), MAXLAND(10), DEFAULTZOMBIE(3), MAXZOMBIE(10)
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
    // std::ifstream file;
    // file.open("plants.txt");
    // char input = 0;
    // while (file >> input)
    // {
    //     /* code */
    // }
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
    // show plant
    // print coin and decision
    return;
}