#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
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
        "UEFA",
        "Kick Off",
        "Buy Player",
        "Sell Player",
        "View Squad",
        "Switch Players",
        "Exit"
    };
   
    allSquads = { Manchester, Arsenal, Liverpool, Chelsea, Tottenham, CrystalPalace, Everton, ManchesterCity, Leicester };
   
}

std::string MainWindow::generatePlayer(std::string squad)
{
    /**
    *       Premier league
    */
    std::string player;
    int random;

    if(squad == "Liverpool F.C.")
    {
        random = rand() % LiverpoolInfield.size();
        player = LiverpoolInfield[random].name;
    }
    else if (squad == "Manchester United F.C.")
    {
        random = rand() % ManchesterInfield.size();
        player = ManchesterInfield[random].name;
    }
    else if(squad == "Arsenal F.C.")
    {
        random = rand() % ArsenalInfield.size();
        player = ArsenalInfield[random].name;
    }
    else if(squad == "Chelsea F.C.")
    {
        random = rand() % ChelseaInfield.size();
        player = ChelseaInfield[random].name;
    }
    else if(squad == "Tottenham Hotspur F.C.")
    {
        random = rand() % TottenhamInfield.size();
        player = TottenhamInfield[random].name;
    }
    else if(squad == "Crystal Palace F.C.")
    {
        random = rand() % CrystalInfield.size();
        player = CrystalInfield[random].name;
    }
    else if(squad == "Manchester City F.C.")
    {
        random = rand() % ManchesterCInfield.size();
        player = ManchesterCInfield[random].name;
    }
    if(squad == "Leicester City F.C.")
    {
        random = rand() % LeicesterInfield.size();
        player = LeicesterInfield[random].name;
    }
    if(squad == "Everton F.C.")
    {
        random = rand() % EvertonInfield.size();
        player = EvertonInfield[random].name;
    }
    return player;

}

bool MainWindow::MainMenu()
{
    int pointer = -1;
    while(true)
    {
        system("CLS");
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
                    pointer = 7;
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
                        system("cls");
                        return Status();
                    }

                    case int(MenuOptions::UEFA):
                    {
                        system("cls");
                        while(true)
                        {
                            if(GetAsyncKeyState(VK_ESCAPE) != 0)
                            {
                                MainMenu();
                            }
                        }
                    }
                    case int(MenuOptions::KickOff):
                    {
                        system("cls");
                        return KickOff();
                    }
                    case int(MenuOptions::BuyPlayer):
                    {
                        system("cls");
                        while(true)
                        {
                            if(GetAsyncKeyState(VK_ESCAPE) != 0)
                            {
                                MainMenu();
                            }
                        }
                    }
                    case int(MenuOptions::SellPlayer):
                    {
                        system("cls");
                        while(true)
                        {
                            if(GetAsyncKeyState(VK_ESCAPE) != 0)
                            {
                                MainMenu();
                            }
                        }
                    }
                    case int(MenuOptions::ViewSquad):
                    {
                        system("cls");
                        return ViewSquad();
                    }
                    case int(MenuOptions::SwitchPlayers):
                    {
                        system("cls");
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
    game->SetStatus(GameStatus::PLAYING);

    std::string randSquadB = generateSquad();
    std::string randPlayerA = generatePlayer(initUser->GetSquad());
    std::string randPlayerB = generatePlayer(randSquadB);

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