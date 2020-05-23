#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

#include "gameFunc.h"


int main()
{
    srand((unsigned int)time(nullptr));

    try
    {
        if (game->GetStatus() == GameStatus::NONE)
        {
            gameWin->InitWindow();
        }
        else
        {
            throw std::runtime_error("Whilst trying to start the game.");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "RUNTIME ERROR : " << e.what() << std::endl;
        
    }
    catch (...)
    {
        std::cerr << "System error" << std::endl;
    }
    std::cout << "Press any key to continue...  ";
    std::cin.get();
    return 0;
}

