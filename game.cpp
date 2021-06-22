#include <iostream>
#include "game.h"

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