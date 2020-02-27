#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>


#include <time.h>
#include <chrono>


#include "gameFunc.h"
#include "dbsCreation.h"


/**
*       MainWindow class definitions
*/
MainWindow::MainWindow()
{
    pressed = false;
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
}

void MainWindow::MainMenu()
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
                        Status();
                    }

                    case int(MenuOptions::UEFA):
                    {
                        system("cls");
                        pressed = true;
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
                        pressed = true;
                        while(true)
                        {
                            if(GetAsyncKeyState(VK_ESCAPE) != 0)
                            {
                                MainMenu();
                            }
                        }
                    }
                    case int(MenuOptions::BuyPlayer):
                    {
                        system("cls");
                        pressed = true;

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
                        pressed = true;
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
                        pressed = true;
                        ViewSquad();
                    }
                    case int(MenuOptions::SwitchPlayers):
                    {
                        system("cls");
                        pressed = true;
                        while(true)
                        {
                            if(GetAsyncKeyState(VK_ESCAPE) != 0)
                            {
                                MainMenu();
                            }
                        }
                    }
                    case int(MenuOptions::Exit):
                    {
                        pressed = true;
                        exit(0);
                    }
                }
            }
        }
        Sleep(150);
    }
}

void MainWindow::ViewSquad()
{
    if (initUser.GetSquad() == "F.C. Manchester United")
    {
        Manchester.GetPlayers();
        std::cout << '\n';
    }
    else if(initUser.GetSquad() == "Liverpool F.C.")
    {
        Liverpool.GetPlayers();
        std::cout << '\n';
    }
    else if(initUser.GetSquad() == "Arsenal F.C.")
    {
        Arsenal.GetPlayers();
        std::cout << '\n';
    }
    else
    {
        while(true)
        {
            if(GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                MainMenu();
            }
        }
    }
}

void MainWindow::Status()
{

    std::cout << std::setw(10) << "SQUAD : " << " " << std::setw(10) << initUser.GetSquad()  << "\n\n";
    std::cout << std::setw(10) << "LEAGUE : " << " " << std::setw(10) << initUser.GetLeague()  << "\n\n";
    std::cout << std::setw(10) << "COUNTRY : " << " " << std::setw(10) << initUser.GetCountry() << "\n\n";
    std::cout << std::setw(10) << "MANAGER : " << " " << std::setw(10) << initUser.GetUsername()  << "\n\n";

    while(true)
    {
        if(GetAsyncKeyState(VK_ESCAPE) != 0)
        {
            MainMenu();
        }
    }
}
