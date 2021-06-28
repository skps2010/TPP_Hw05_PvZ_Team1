#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.h"
#include "map.h"
#include "land.h"
#include "zombie.h"

Game::Game() : DEFAULTLAND(8), MAXLAND(10), DEFAULTZOMBIE(3), MAXZOMBIE(10), lastDecision(0), gamestatus(0)
{
    srand(time(NULL));
    // init the map
    // logo();
    m = new map(setNumberOfLand(), setNumberOfZombie());
    rule();
    m->PlayerMove(rolldice(1, m->Landcnt()));
    for (size_t i = 0; i < m->Zombiecnt(); ++i)
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
    for (size_t i = 0; i < dictionary.size(); ++i)
    {
        std::cout << "[" << i << "]";
        m->PrintPlant(dictionary[i]);
        std::cout << std::endl;
    }
    return;
}

void Game::makeDecision(void)
{
    std::cout << "Enter your choice (" << dictionary.size() << " to give up, default: " << lastDecision << ")...>";
    int decision = 0;
    std::cin >> decision;
    if (decision > dictionary.size() || decision < 0)
    {
        std::cout << "Wrong input! Set your decision as default!" << std::endl;
        decision = lastDecision;
    }
    else
    {
        lastDecision = decision;
    }
    if (decision != dictionary.size())
    {
        m->SetPlant(m->PlayerPosition(), dictionary.at(decision));
        std::cout << "You have planted " << m->PlantName(m->PlayerPosition()) << " at land " << m->PlayerPosition() << " !" << std::endl;
    }
    else
    {
        std::cout << "You give up!" << std::endl;
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
    while (1)
    {
        showMap();
        showPlants();
        std::cout << std::endl;
        if (m->LandisEmpty(m->PlayerPosition()))
        {
            if (m->PlayerCoin() > 0)
            {
                m->PrintPlayer();
                makeDecision();
            }
            else
            {
                std::cout << "You do not have enough money to plant anything!" << std::endl;
            }
        }
        else
        {
            if (m->PlantisReady(m->PlayerPosition()))
            {
                std::cout << "You have earned $" << m->PlantStatus(m->PlayerPosition()) << "! Now you have $" << m->PlayerCoin() << "." << std::endl;
            }
            // else
            // {
            //     m->
            // }
        }

        // zombie move
        int deadzombie = 0;
        for (size_t i = 0; i < m->Zombiecnt(); ++i)
        {
            if (!(m->ZombieisDead(i)))
            {
                m->ZombieMove(i, rolldice(1, 3));
                std::cout << "Zombie [" << i << "] moves to land " << m->ZombiePosition(i) << "." << std::endl;
                if (!(m->LandisEmpty(m->ZombiePosition(i))))
                {
                    std::string NowPlantName = m->PlantName(m->ZombiePosition(i));
                    if (m->PlantDP(m->ZombiePosition(i)) > 0)
                    {
                        std::cout << m->PlantName(m->ZombiePosition(i)) << " gives " << m->PlantDP(m->ZombiePosition(i)) << " damage to the zombie!" << std::endl;
                        m->PAttackZ(m->ZombiePosition(i), i);
                    }
                    if (!(m->ZombieisDead(i)))
                    {
                        if (!(m->LandisEmpty(m->ZombiePosition(i))))
                        {
                            std::cout << "Zombie eats plant " << m->PlantName(m->ZombiePosition(i)) << " and causes damage 15." << std::endl;
                            m->ZAttackP(m->ZombiePosition(i), i);
                        }
                        else if (m->B_Used() >= m->Zombiecnt())
                        {
                            gamestatus = 2;
                            break;
                        }
                    }
                    else
                    {
                        std::cout << "Zombie is killed!" << std::endl;
                    }

                    if (m->LandisEmpty(m->ZombiePosition(i)))
                    {
                        std::cout << "Plant " << NowPlantName << " is dead!" << std::endl;
                        if (m->Plantcnt() == 0)
                        {
                            gamestatus = 1;
                            break;
                        }
                    }
                }
            }
            else
            {
                ++deadzombie;
            }
        }

        if (gamestatus == 1)
        {
            std::cout << "Oh no... You have no plant on the map ...." << std::endl;
            break;
        }
        else if (gamestatus == 2)
        {
            std::cout << "You lose the game since you cannot use that many bomb plants!" << std::endl;
            break;
        }

        if (deadzombie == m->Zombiecnt())
        {
            std::cout << "Congratulations! You have killed all zombies!" << std::endl;
            break;
        }
        m->PlayerMove(rolldice(1, 6));
    }
    return;
}
