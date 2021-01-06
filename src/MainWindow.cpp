#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <conio.h>
#include <consoleapi.h>

#include "include/dbsSource.h"
#include "include/gameFunc.h"
#include "include/dbsCreation.h"


/**
 *       MainWindow class defined
 */
MainWindow::MainWindow() : 
    Options 
    {
        "Status",
        "Kick Off",
        "View Squad",
        "Switch Players",
        "Exit"
    }
{
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

void MainWindow::MainMenu()
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
                        Status();
                    }
                    case int(MenuOptions::KickOff):
                    {
                        clrscr();
                        game->SetStatus(GameStatus::PLAYING);
                        KickOff();
                    }
                    case int(MenuOptions::ViewSquad):
                    {
                        clrscr();
                        ViewSquad();
                    }
                    case int(MenuOptions::SwitchPlayers):
                    {
                        clrscr();
                        SwitchPlayer();
                    }
                    case int(MenuOptions::Exit):
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        clrscr();
                        exit(0);
                    }
                }
            }
        }
        Sleep(150);
    }
}

void MainWindow::Status()
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

void MainWindow::KickOff()
{
    if (game->GetStatus() == GameStatus::PLAYING)
    {
        game->Simulate();
    }
}

void MainWindow::ViewSquad()
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

void MainWindow::SwitchPlayer()
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



/**
*       Game class defined
*/
Game::Game() : 
    status(GameStatus::NONE),
    gameTime(0),
    penalty(0),
    cornerkick(0),
    offside(0),
    out(0),
    attempt(0),
    injury(0),
    foul(0),
    yellow(0),
    red(0),
    goal(0),
    penalty1(0), 
    cornerkick1(0), 
    offside1(0), 
    out1(0), 
    attempt1(0), 
    injury1(0), 
    foul1(0), 
    yellow1(0), 
    red1(0), 
    goal1(0)
{
}


GameStatus Game::GetStatus() const
{
    return status;
}

void Game::SetStatus(GameStatus setStatus)
{
    status = setStatus;
}


void Game::Simulate()
{   
    // getting our squad object
    std::shared_ptr<Squad> mySquad;
    for (auto it = allSquads.begin(); it != allSquads.end(); it = std::next(it))
    {
        if (initUser->GetSquad() == (*it)->GetName())
        {
            mySquad = *it;
        }
    }
    // random squad
    std::shared_ptr<Squad> opponentSquad = allSquads[GenerateSquad()];
    
    std::cout << std::setw(29.5) << mySquad->GetName() << std::setw(14.5) << " VS " << std::setw(29.5) << opponentSquad->GetName() << std::endl << std::endl;
    Sleep(1000);
   
    do 
    {
        int myPlayer = GeneratePlayer();
        int opponentPlayer = GeneratePlayer();

        if (gameTime == 46)
        {
            Sleep(3000);
        }
        else if (((mySquad->inField[myPlayer].shooting * 60 + mySquad->inField[myPlayer].passing * 20 + mySquad->inField[myPlayer].dribbling * 20) / 100 < 50) && 
            ((opponentSquad->inField[opponentPlayer].defending * 40 + opponentSquad->inField[opponentPlayer].diving * 60) / 100 >= 50))
        {
            penalty += 1;

            if ((mySquad->inField[myPlayer].shooting * 45 + mySquad->inField[myPlayer].dribbling * 20 + mySquad->inField[myPlayer].handling * 25 + mySquad->inField[myPlayer].physical * 10) / 100 < 55 &&
                (opponentSquad->inField[opponentPlayer].defending * 55 + opponentSquad->inField[opponentPlayer].diving * 25 + opponentSquad->inField[opponentPlayer].physical * 20) / 100 >= 50)
            {
                goal += 1;
            }
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if (((opponentSquad->inField[opponentPlayer].shooting * 60 + opponentSquad->inField[opponentPlayer].passing * 20 + opponentSquad->inField[opponentPlayer].dribbling * 20) / 100 < 50) && 
            ((mySquad->inField[myPlayer].defending * 40 + mySquad->inField[myPlayer].diving * 60) / 100 >= 50))
        {
            penalty1 += 1;

            if ((opponentSquad->inField[opponentPlayer].shooting * 45 + opponentSquad->inField[opponentPlayer].dribbling * 20 + opponentSquad->inField[opponentPlayer].handling * 25 + opponentSquad->inField[opponentPlayer].physical * 10) / 100 < 55 &&
                (mySquad->inField[myPlayer].defending * 55 + mySquad->inField[myPlayer].diving * 25 + mySquad->inField[myPlayer].physical * 20) / 100 >= 50)
            {
                goal1 += 1;
            }
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((mySquad->inField[myPlayer].passing * 10 + mySquad->inField[myPlayer].physical * 65 + mySquad->inField[myPlayer].shooting * 25) / 100 < 30 && 
            (opponentSquad->inField[opponentPlayer].defending * 75 + opponentSquad->inField[opponentPlayer].reflexes * 15 + opponentSquad->inField[opponentPlayer].passing * 10) / 100 >= 50)
        {
            cornerkick += 1;
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((opponentSquad->inField[opponentPlayer].passing * 10 + opponentSquad->inField[opponentPlayer].physical * 65 + opponentSquad->inField[opponentPlayer].shooting * 25) / 100 < 30 &&
            (mySquad->inField[myPlayer].defending * 75 + mySquad->inField[myPlayer].reflexes * 15 + mySquad->inField[myPlayer].passing * 10) / 100 >= 50)
        {
            cornerkick1 += 1;
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((mySquad->inField[myPlayer].pace * 65 + mySquad->inField[myPlayer].dribbling * 20 + mySquad->inField[myPlayer].passing * 15) / 100 < 45 && 
            (opponentSquad->inField[opponentPlayer].physical * 70 + opponentSquad->inField[opponentPlayer].pace * 20 + opponentSquad->inField[opponentPlayer].passing * 10) / 100 >= 50)
        {
            offside += 1;
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((opponentSquad->inField[opponentPlayer].pace * 65 + opponentSquad->inField[opponentPlayer].dribbling * 20 + opponentSquad->inField[opponentPlayer].passing * 15) / 100 < 45 &&
            (mySquad->inField[myPlayer].physical * 70 + mySquad->inField[myPlayer].pace * 20 + mySquad->inField[myPlayer].passing * 10) / 100 >= 50)
        {
            offside1 += 1;
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((mySquad->inField[myPlayer].passing * 45 + mySquad->inField[myPlayer].handling * 25 + mySquad->inField[myPlayer].dribbling * 15) / 100 < 50 && 
            (opponentSquad->inField[opponentPlayer].passing * 45 + opponentSquad->inField[opponentPlayer].handling * 25 + opponentSquad->inField[opponentPlayer].dribbling * 15) / 100 >= 50)
        {
            out += 1;
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((opponentSquad->inField[opponentPlayer].passing * 50 + opponentSquad->inField[opponentPlayer].handling * 30 + opponentSquad->inField[opponentPlayer].dribbling * 20) / 100 < 50 &&
            (mySquad->inField[myPlayer].passing * 45 + mySquad->inField[myPlayer].handling * 25 + mySquad->inField[myPlayer].dribbling * 15) / 100 >= 50)
        {
            out1 += 1;
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((mySquad->inField[myPlayer].shooting * 45 + mySquad->inField[myPlayer].dribbling * 15 + mySquad->inField[myPlayer].physical * 10 + mySquad->inField[myPlayer].reflexes * 10 + mySquad->inField[myPlayer].handling * 20) / 100 < 45 && 
            (opponentSquad->inField[opponentPlayer].defending * 55 + opponentSquad->inField[opponentPlayer].diving * 30 + opponentSquad->inField[opponentPlayer].reflexes * 15) / 100 >= 50)
        {
            attempt += 1;
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((opponentSquad->inField[opponentPlayer].shooting * 45 + opponentSquad->inField[opponentPlayer].dribbling * 15 + opponentSquad->inField[opponentPlayer].physical * 10 + 
            opponentSquad->inField[opponentPlayer].reflexes * 10 + opponentSquad->inField[opponentPlayer].handling * 20) / 100 < 45 &&
            (mySquad->inField[myPlayer].defending * 55 + mySquad->inField[myPlayer].diving * 30 + mySquad->inField[myPlayer].reflexes * 15) / 100 >= 50)
        {
            attempt1 += 1;
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((mySquad->inField[myPlayer].diving * 45 + mySquad->inField[myPlayer].passing * 20 + mySquad->inField[myPlayer].physical * 35) / 100 < 50 &&
            (opponentSquad->inField[opponentPlayer].passing * 25 + opponentSquad->inField[opponentPlayer].dribbling * 30 + opponentSquad->inField[opponentPlayer].handling * 45) / 100 >= 45)
        {
            foul += 1;

            if ((mySquad->inField[myPlayer].diving * 45 + mySquad->inField[myPlayer].passing * 20 + mySquad->inField[myPlayer].physical * 35) / 100 < 48 &&
                (opponentSquad->inField[opponentPlayer].passing * 25 + opponentSquad->inField[opponentPlayer].dribbling * 30 + opponentSquad->inField[opponentPlayer].handling * 45) / 100 >= 50)
            {
                yellow += 1;
            }
            else if ((mySquad->inField[myPlayer].diving * 45 + mySquad->inField[myPlayer].passing * 20 + mySquad->inField[myPlayer].physical * 35) / 100 < 46 &&
                (opponentSquad->inField[opponentPlayer].passing * 25 + opponentSquad->inField[opponentPlayer].dribbling * 30 + opponentSquad->inField[opponentPlayer].handling * 45) / 100 >= 50)
            {
                red += 1;
                injury += 1;
            }
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((opponentSquad->inField[opponentPlayer].diving * 45 + opponentSquad->inField[opponentPlayer].passing * 20 + opponentSquad->inField[opponentPlayer].physical * 35) / 100 < 50 &&
            (mySquad->inField[myPlayer].passing * 25 + mySquad->inField[myPlayer].dribbling * 30 + mySquad->inField[myPlayer].handling * 45) / 100 >= 45)
        {
            foul1 += 1;

            if ((opponentSquad->inField[opponentPlayer].diving * 45 + opponentSquad->inField[opponentPlayer].passing * 20 + opponentSquad->inField[opponentPlayer].physical * 35) / 100 < 48 &&
                (mySquad->inField[myPlayer].passing * 25 + mySquad->inField[myPlayer].dribbling * 30 + mySquad->inField[myPlayer].handling * 45) / 100 >= 50)
            {
                yellow1 += 1;
            }
            else if ((opponentSquad->inField[opponentPlayer].diving * 45 + opponentSquad->inField[opponentPlayer].passing * 20 + opponentSquad->inField[opponentPlayer].physical * 35) / 100 < 46 &&
                (mySquad->inField[myPlayer].passing * 25 + mySquad->inField[myPlayer].dribbling * 30 + mySquad->inField[myPlayer].handling * 45) / 100 >= 50)
            {
                red1 += 1;
                injury1 += 1;
            }
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((mySquad->inField[myPlayer].shooting * 45 + mySquad->inField[myPlayer].dribbling * 20 + mySquad->inField[myPlayer].handling * 25 + mySquad->inField[myPlayer].physical * 10) / 100 < 55 &&
            (opponentSquad->inField[opponentPlayer].defending * 55 + opponentSquad->inField[opponentPlayer].diving * 25 + opponentSquad->inField[opponentPlayer].physical * 20) / 100 >= 50)
        {
            goal += 1;
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else if ((opponentSquad->inField[opponentPlayer].shooting * 45 + opponentSquad->inField[opponentPlayer].dribbling * 20 + opponentSquad->inField[opponentPlayer].handling * 25 + opponentSquad->inField[opponentPlayer].physical * 10) / 100 < 50 &&
            (mySquad->inField[myPlayer].defending * 55 + mySquad->inField[myPlayer].diving * 25 + mySquad->inField[myPlayer].physical * 20) / 100 >= 50)
        {
            goal1 += 1;
            myPlayer = GeneratePlayer();
            opponentPlayer = GeneratePlayer();
        }
        else
        {
            continue;
        }
        

        
        // my team
        gotoxy(40, 2);
        printf("%d'", gameTime);
        gotoxy(25, 4);
        std::cout << penalty;
        gotoxy(38, 4);
        std::cout << "PENALTY";
        gotoxy(25, 6);
        std::cout << cornerkick;
        gotoxy(38, 6);
        std::cout << "CORNERKICK";
        gotoxy(25, 8);
        std::cout << offside;
        gotoxy(38, 8);
        std::cout << "OFFSIDE";
        gotoxy(25, 10);
        std::cout << out;
        gotoxy(38, 10);
        std::cout << "OUT";
        gotoxy(25, 12);
        std::cout << attempt;
        gotoxy(38, 12);
        std::cout << "ATTEMPT";
        gotoxy(25, 14);
        std::cout << injury;
        gotoxy(38, 14);
        std::cout << "INJURY";
        gotoxy(25, 16);
        std::cout << foul;
        gotoxy(38, 16);
        std::cout << "FOUL";
        gotoxy(25, 18);
        std::cout << yellow;
        gotoxy(38, 18);
        std::cout << "YELLOW";
        gotoxy(25, 20);
        std::cout << red;
        gotoxy(38, 20);
        std::cout << "RED";
        gotoxy(25, 22);
        std::cout << goal;
        gotoxy(38, 22);
        std::cout << "GOAL";

        // Opponent team
        gotoxy(60, 4);
        std::cout << penalty1;
        gotoxy(60, 6);
        std::cout << cornerkick1;
        gotoxy(60, 8);
        std::cout << offside1;
        gotoxy(60, 10);
        std::cout << out1;
        gotoxy(60, 12);
        std::cout << attempt1;
        gotoxy(60, 14);
        std::cout << injury1;
        gotoxy(60, 16);
        std::cout << foul1;
        gotoxy(60, 18);
        std::cout << yellow1;
        gotoxy(60, 20);
        std::cout << red1;
        gotoxy(60, 22);
        std::cout << goal1;


        

        Sleep(500);
        gameTime++;
        
        

        
    } while (gameTime <= 90);

    while (game->GetStatus() == GameStatus::PLAYING)
    {
        if (GetAsyncKeyState(VK_ESCAPE) != 0)
        {
            game->SetStatus(GameStatus::EXIT);
            if (game->GetStatus() == GameStatus::EXIT)
            {
                game->ResetGame();
                mainWin->MainMenu();
            }
        }
    }
}

void Game::ResetGame()
{
    status = GameStatus::NONE;
    gameTime = 0;
    penalty = 0;
    cornerkick = 0;
    offside = 0;
    out = 0;
    attempt = 0;
    injury = 0;
    foul = 0;
    yellow = 0;
    red = 0;
    goal = 0;
    penalty1 = 0;
    cornerkick1 = 0;
    offside1 = 0;
    out1 = 0;
    attempt1 = 0;
    injury1 = 0;
    foul1 = 0;
    yellow1 = 0;
    red1 = 0;
    goal1 = 0;
}

void Game::gotoxy(short x, short y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };

    SetConsoleCursorPosition(hStdout, position);
}


int Game::GenerateSquad()
{
    std::shared_ptr<std::string> squad = std::make_shared<std::string>();
    std::shared_ptr<std::string> compareTo = std::make_shared<std::string>();
    *compareTo = initUser->GetSquad();

    int i;
    while (true)
    {
        i = rand() % 8 + 0;
        *squad = allSquads[i]->GetName();

        if (*squad != *compareTo)
        {
            break;
        }
    }
    return i;
}

int Game::GeneratePlayer()
{
    int i = rand() % 10 + 0;
    return i;
}

std::shared_ptr<Game> game = std::make_shared<Game>();
