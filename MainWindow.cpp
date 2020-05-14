#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>

#include "gameFunc.h"
#include "dbsCreation.h"


/**
*       MainWindow class defined
*/
MainWindow::MainWindow()
{
    Options =
    {
        "Status",
        "Kick Off",
        "View Squad",
        "Switch Players",
        "Exit"
    };
   
    allSquads = { Manchester, Arsenal, Liverpool, Chelsea, Tottenham, CrystalPalace, Everton, ManchesterCity, Leicester };

    std::copy(ManchesterInfield.begin(), ManchesterInfield.end(), std::back_inserter(allPlayers));
    std::copy(ManchesterUSubs.begin(), ManchesterUSubs.end(), std::back_inserter(allPlayers));
    std::copy(ArsenalInfield.begin(), ArsenalInfield.end(), std::back_inserter(allPlayers));
    std::copy(ArsenalSubs.begin(), ArsenalSubs.end(), std::back_inserter(allPlayers));
    std::copy(LiverpoolInfield.begin(), LiverpoolInfield.end(), std::back_inserter(allPlayers));
    std::copy(LiverpoolSubs.begin(), LiverpoolSubs.end(), std::back_inserter(allPlayers));
    std::copy(ChelseaInfield.begin(), ChelseaInfield.end(), std::back_inserter(allPlayers));
    std::copy(ChelseaSubs.begin(), ChelseaSubs.end(), std::back_inserter(allPlayers));
    std::copy(TottenhamInfield.begin(), TottenhamInfield.end(), std::back_inserter(allPlayers));
    std::copy(TottenhamSubs.begin(), TottenhamSubs.end(), std::back_inserter(allPlayers));
    std::copy(CrystalInfield.begin(), CrystalInfield.end(), std::back_inserter(allPlayers));
    std::copy(CrystalSubs.begin(), CrystalSubs.end(), std::back_inserter(allPlayers));
    std::copy(EvertonInfield.begin(), EvertonInfield.end(), std::back_inserter(allPlayers));
    std::copy(EvertonSubs.begin(), EvertonSubs.end(), std::back_inserter(allPlayers));
    std::copy(ManchesterCInfield.begin(), ManchesterCInfield.end(), std::back_inserter(allPlayers));
    std::copy(ManchesterCSubs.begin(), ManchesterCSubs.end(), std::back_inserter(allPlayers));
    std::copy(LeicesterInfield.begin(), LeicesterInfield.end(), std::back_inserter(allPlayers));
    std::copy(LeicesterSubs.begin(), LeicesterSubs.end(), std::back_inserter(allPlayers));   
}

bool MainWindow::MainMenu()
{
    int pointer = -1;
    while(true)
    {
        clrscr();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        for(int i = 0; i < COUNT; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << std::setw(5) << Options[i] << std::setw(5) << " ";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << std::setw(5) << Options[i] << std::setw(5) << " ";
            }
        }

        while(true)
        {

            if (GetAsyncKeyState(VK_LEFT) != 0 && pointer > -1)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 4;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_RIGHT) != 0)
            {
                pointer += 1;

                if (pointer == COUNT)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch(pointer)
                {
                    case int(MenuOptions::STATUS):
                    {
                        clrscr();
                        return Status();
                    }
                    case int(MenuOptions::KickOff):
                    {
                        clrscr();
                        game->SetStatus(GameStatus::PLAYING);
                        return KickOff();
                    }
                    case int(MenuOptions::ViewSquad):
                    {
                        clrscr();
                        return ViewSquad();
                    }
                    case int(MenuOptions::SwitchPlayers):
                    {
                        clrscr();
                        return SwitchPlayer();
                    }
                    case int(MenuOptions::Exit):
                    {
                        exit(0);
                    }
                }
            }
        }
        Sleep(150);
    }
}

bool MainWindow::Status()
{
    std::cout << std::setw(10) << "SQUAD : " << " " << std::setw(10) << initUser->GetSquad()  << "\n\n";
    std::cout << std::setw(10) << "LEAGUE : " << " " << std::setw(10) << initUser->GetLeague()  << "\n\n";
    std::cout << std::setw(10) << "COUNTRY : " << " " << std::setw(10) << initUser->GetCountry() << "\n\n";
    std::cout << std::setw(10) << "MANAGER : " << " " << std::setw(10) << initUser->GetUsername()  << "\n\n";

    while(true)
    {
        if(GetAsyncKeyState(VK_ESCAPE) != 0)
        {
            return MainMenu();
        }
    }
}

bool MainWindow::KickOff()
{
    while (game->GetStatus() == GameStatus::PLAYING)
    {
        break;
    }


    while(true)
    {
        if(GetAsyncKeyState(VK_ESCAPE) != 0)
        {
            game->SetStatus(GameStatus::EXIT);
            if(game->GetStatus() == GameStatus::EXIT)
            {
                return MainMenu();
            }
        }
    }
}

bool MainWindow::ViewSquad()
{
    for (auto it = allSquads.begin(); it != allSquads.end(); it = std::next(it))
    {
        if (initUser->GetSquad() == (*it)->GetName())
        {
            (*it)->GetPlayers();
        }
    }
    while(true)
    {
        if(GetAsyncKeyState(VK_ESCAPE) != 0)
        {
            return MainMenu();
        }
    }
}

bool MainWindow::SwitchPlayer()
{
    for (auto it = allSquads.begin(); it != allSquads.end(); it = std::next(it))
    {
        if (initUser->GetSquad() == (*it)->GetName())
        {
            (*it)->SelectInfield();
        }
    }
    while (true)
    {
        if (GetAsyncKeyState(VK_ESCAPE) != 0)
        {
            return MainMenu();
        }
    }
}

std::shared_ptr<MainWindow> mainWin = std::make_shared<MainWindow>();