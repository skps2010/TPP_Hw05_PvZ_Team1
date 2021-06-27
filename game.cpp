#include <iostream>
#include "game.h"
#include "map.h"
#include "land.h"
#include "zombie.h"

Game::Game() : DEFAULTLAND(8), MAXLAND(10), DEFAULTZOMBIE(3), MAXZOMBIE(10)
{
    logo();
    int NumOfLand = setNumberOfLand();
    int NumOfZombie = setNumberOfZombie();
    m = new map(NumOfLand, NumOfZombie);
    rule();
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