#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

#include "gameFunc.h"


int main()
{
    srand((unsigned int)time(nullptr));

    try
    {
        Game game;

        if (game.GetStatus() == GameStatus::NONE)
        {
            game.Run();
        }
        else
        {
            throw std::runtime_error("Whilst trying to start the game.");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "RUNTIME ERROR : " << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "System error" << '\n';
    }
    return 0;
}

