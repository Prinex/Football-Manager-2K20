#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>

#include "gameFunc.h"
#include "dbsSource.h"
#include "dbsCreation.h"

/**
*       Player class definiton
*/


User::User() :
    fullname(""),
    country(""),
    league(""),
    squad("")
{
}


std::string User::GetUsername()
{
    return fullname;
}
void User::SetUserName(std::string &fn, std::string &ln)
{
    fullname = fn + " " + ln;
}
std::string User::GetCountry()
{
    return country;
}
void User::SetCountry(std::string &setCountry)
{
    country = setCountry;
}

std::string User::GetLeague()
{
    return league;
}
void User::SetLeague(std::string &setLeague)
{
    league = setLeague;
}
std::string User::GetSquad()
{
    return squad;
}
void User::SetSquad(std::string &setSquad)
{
    squad = setSquad;
}

// Default user
User initUser;


/**
*       Game class defined
*/
Game::Game():
    time1(0),
    time2(0),
    total_time(0),
    your_score(0),
    opponent_score(0),
    status(GameStatus::NONE)
{
}



/**
*       Game class defined
*/

GameWindow::GameWindow() :
    select_country
    {
        "ITALY",
        "SPAIN",
        "GERMANY",
        "ENGLAND",
        "FRANCE"
    },
    select_league
    {
        {"SERIE A", "SERIE B"},
        {"LaLiga", "SegundaDivision"},
        {"Bundesliga", "Bundesliga 2"},
        {"Premier League"},
        {"Ligue 1", "Ligue 2"}
    },
    select_squad
    {
        {"Juventus F.C.", "Inter Milan", "S.S.C. Napoli", "Atalanta B.C.", "A.C. Milan", "A.S. Roma", "ACF Fiorentina"},
        {"SS Lazio", "Benevento Calcio", "S.S.D. Palermo", "Delfino Pescara", "F.C. Crotone", "Torino F.C."},
        {"FC Barcelona", "Atletico Bilbao", "Valencia CF", "Sevilla FC", "Real Sociedad", "Real Betis", "Atletico Madrid", "Real Madrid"},
        {"Girona FC", "Granada CF", "Malaga CF"},
        {"FC Bayern Munich", "Borussia Dortmund", "FC Schalke", "FC Koln", "RB Leipzig"},
        {"VfB Stuttgart", "Hamburger SV", "FC Nurnberg", "Holstein Kiel"},
        {"Liverpool F.C.", "Manchester United F.C.", "Arsenal F.C.", "Chelsea F.C.", "Tottenham Hotspur F.C.", "Crystal Palace F.C.", "Everton F.C.", "Manchester City", "Leicester City"},
        {"Paris-Saint-Germain F.C.", "FC Nantes", "As Monaco", "OGC Nice", "Toulouse FC"},
        {"Le Havre", "AS Nancy", "FC Lorient", "RC Lens"}
    }

{
}

void GameWindow::InitWindow()
{
    /**
    *       Initializing the teams within players
    *
    Players::InitPlayers(LiverpoolSubs, InitLiverpoolSubs);
    Players::PrintPlayers(LiverpoolSubs);
    */


    int countBuffer = 0;

    MainWindow init;
    SetConsoleTitleA("Soccer Manager 2k20.exe");
    ShowConsoleCursor(false);
    char effect[10];

    for(int tick1 = 3; tick1 > 0; tick1--)
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << std::setw(65);
        std::cout << "SM 2K20";

        for(int tick2 = 4; tick2 > 0; tick2--)
        {
            Sleep(550);
            strcpy(effect, ".");
            std::cout << effect;
        }
        system("CLS");
    }


    std::string firstname, lastname;

    std::cout << "Enter manager's first name : ";
    std::cin >> firstname;
    std::cout << '\n';
    std::cout << "Enter manager's last name : ";
    std::cin >> lastname;

    initUser.SetUserName(firstname, lastname);


    InitSquad();


}


void GameWindow::InitSquad()
{
    int pointer = 0;
    int countBuffer = 0;
    while(true)
    {

        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a country: " << "\n\n";
        for(int i = 0; i < SIZE1; i++)
        {

            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_country[i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_country[i] << "\n\n";
            }
        }

        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 4;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == SIZE1)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                InitSquad();
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch(pointer)
                {
                    case int(CountryOption::ITALY):
                    {
                        clearBuffer = 0;
                        Italy();
                    }
                    case int(CountryOption::SPAIN):
                    {

                        clearBuffer = 0;
                        Spain();
                    }
                    case int(CountryOption::GERMANY):
                    {

                        clearBuffer = 0;
                        Germany();
                    }
                    case int(CountryOption::ENGLAND):
                    {
                        std::string setCountry = "England";
                        initUser.SetCountry(setCountry);
                        clearBuffer = 0;
                        England();
                    }
                    case int(CountryOption::FRANCE):
                    {

                        clearBuffer = 0;
                        France();
                    }
                }
            }

        }
        Sleep(150);
    }

}

void GameWindow::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}


/**
*       Country options defined
*/

void GameWindow::Italy()
{
    int pointer = 0;
    int countBuffer = 0;
    while(true)
    {

        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        std::cout << "Choose a league: " << "\n\n";
        for (int i = 0; i < 2; i++)
        {

            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_league[int(CountryOption::ITALY)][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_league[int(CountryOption::ITALY)][i] << "\n\n";
            }
        }
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 1;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 2)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                Italy();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }

            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch(pointer)
                {
                    case int(LeagueOption::SERIE_A):
                    {
                        SerieA();
                    }
                    case int(LeagueOption::SERIE_B):
                    {
                        SerieB();
                    }
                }
            }
        }
        Sleep(150);
    }
}

void GameWindow::Spain()
{
    int pointer = 0;
    int countBuffer = 0;
    while(true)
    {

        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a league: " << "\n\n";

        for (int i = 0; i < 2; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_league[int(CountryOption::SPAIN)][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_league[int(CountryOption::SPAIN)][i] << "\n\n";
            }
        }

        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 1;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 2)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                Spain();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch(pointer)
                {
                    case int(LeagueOption::LaLiga):
                    {
                        Laliga();
                    }
                    case int(LeagueOption::SegundaDivision):
                    {
                        SegundaDiv();
                    }
                }
            }
        }
        Sleep(150);
    }

}

void GameWindow::Germany()
{
    int pointer = 0;
    int countBuffer = 0;
    while(true)
    {

        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a league: " << "\n\n";

        for (int i = 0; i < 2; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_league[int(CountryOption::GERMANY)][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_league[int(CountryOption::GERMANY)][i] << "\n\n";
            }
        }

        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 1;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 2)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                Germany();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch(pointer)
                {
                    case int(LeagueOption::Bundesliga):
                    {
                        BL();
                    }
                    case int(LeagueOption::Bundesliga2):
                    {
                        BL2();
                    }
                }
            }
        }
        Sleep(150);
    }
}

void GameWindow::England()
{
    int pointer = 0;
    int countBuffer = 0;
    while(true)
    {

        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a league: " << "\n\n";

        for (int i = 0; i < 1; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_league[int(CountryOption::ENGLAND)][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_league[int(CountryOption::ENGLAND)][i] << "\n\n";
            }
        }

        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 1;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 2)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                England();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch(pointer)
                {
                    case int(LeagueOption::Premier_League):
                    {
                        std::string setLeague = "Premier League";
                        initUser.SetLeague(setLeague);
                        PremierL();
                    }
                }
            }
        }
        Sleep(150);
    }
}

void GameWindow::France()
{
    int pointer = 0;
    int countBuffer = 0;
    while(true)
    {

        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a league: " << "\n\n";

        for (int i = 0; i < 2; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_league[int(CountryOption::FRANCE)][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_league[int(CountryOption::FRANCE)][i] << "\n\n";
            }
        }

        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 1;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 2)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                France();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch(pointer)
                {
                    case int(LeagueOption::Ligue1):
                    {
                        Lig1();
                    }
                    case int(LeagueOption::Ligue2):
                    {
                        Lig2();
                    }
                }
            }
        }
        Sleep(150);
    }
}

/**
*       League options defined
*/
void GameWindow::SerieA()
{
    int pointer = 0;
    int countBuffer = 0;

    while(true)
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a squad: " << "\n\n";

        for (int i = 0; i < 7; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_squad[int(CountryOption::ITALY)][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_squad[int(CountryOption::ITALY)][i] << "\n\n";
            }
        }
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 6;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 7)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                SerieA();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
        }
        Sleep(150);
    }

}

void GameWindow::SerieB()
{
    int pointer = 0;
    int countBuffer = 0;

    while(true)
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a squad: " << "\n\n";

        for (int i = 0; i < 6; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_squad[int(CountryOption::ITALY)+1][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_squad[int(CountryOption::ITALY)+1][i] << "\n\n";
            }
        }
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 5;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 6)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                SerieB();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
        }
        Sleep(150);
    }

}


void GameWindow::Laliga()
{
    int pointer = 0;
    int countBuffer = 0;

    while(true)
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a squad: " << "\n\n";

        for (int i = 0; i < 8; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_squad[int(CountryOption::SPAIN)+1][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_squad[int(CountryOption::SPAIN)+1][i] << "\n\n";
            }
        }
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 7;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 8)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                Laliga();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
        }
        Sleep(150);
    }

}

void GameWindow::SegundaDiv()
{
    int pointer = 0;
    int countBuffer = 0;

    while(true)
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a squad: " << "\n\n";

        for (int i = 0; i < 3; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_squad[int(CountryOption::SPAIN)+2][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_squad[int(CountryOption::SPAIN)+2][i] << "\n\n";
            }
        }
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 2;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 3)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                SegundaDiv();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
        }
        Sleep(150);
    }

}

void GameWindow::BL()
{
    int pointer = 0;
    int countBuffer = 0;

    while(true)
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a squad: " << "\n\n";

        for (int i = 0; i < 5; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_squad[int(CountryOption::GERMANY)+2][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_squad[int(CountryOption::GERMANY)+2][i] << "\n\n";
            }
        }
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 4;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 5)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                BL();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
        }
        Sleep(150);
    }

}

void GameWindow::BL2()
{
    int pointer = 0;
    int countBuffer = 0;

    while(true)
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a squad: " << "\n\n";

        for (int i = 0; i < 4; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_squad[int(CountryOption::GERMANY)+3][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_squad[int(CountryOption::GERMANY)+3][i] << "\n\n";
            }
        }
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 3;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 4)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                BL2();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
        }
        Sleep(150);
    }

}

void GameWindow::PremierL()
{
    int pointer = 0;
    int countBuffer = 0;

    while(true)
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a squad: " << "\n\n";

        for (int i = 0; i < 9; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_squad[int(CountryOption::ENGLAND)+3][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_squad[int(CountryOption::ENGLAND)+3][i] << "\n\n";
            }
        }
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 8;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 9)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                PremierL();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch(pointer)
                {
                    case int(PremierLgList::ManchesterU):
                    {
                        std::string setSquad = "F.C. Manchester United";
                        initUser.SetSquad(setSquad);
                        MainWindow init;
                        init.MainMenu();
                    }
                }
            }
        }
        Sleep(150);
    }

}

void GameWindow::Lig1()
{
    int pointer = 0;
    int countBuffer = 0;

    while(true)
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a squad: " << "\n\n";

        for (int i = 0; i < 5; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_squad[int(CountryOption::FRANCE)+3][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_squad[int(CountryOption::FRANCE)+3][i] << "\n\n";
            }
        }
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 4;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 5)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                Lig1();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
        }
        Sleep(150);
    }

}

void GameWindow::Lig2()
{
    int pointer = 0;
    int countBuffer = 0;

    while(true)
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a squad: " << "\n\n";

        for (int i = 0; i < 4; i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << select_squad[int(CountryOption::FRANCE)+4][i] << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << select_squad[int(CountryOption::FRANCE)+4][i] << "\n\n";
            }
        }
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 3;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == 4)
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                Lig2();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
        }
        Sleep(150);
    }

}




/**
*       MainWindow class definitions
*/

MainWindow::MainWindow() :
    pressed(false),
    Options
    {
        "Status",
        "UEFA",
        "Kick Off",
        "Buy Player",
        "Sell Player",
        "View Squad",
        "Switch Players",
        "Exit"
    }
{
}


void MainWindow::MainMenu()
{

    int pointer = 0;
    int countBuffer = 0;

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
            if (GetAsyncKeyState(VK_LEFT) != 0)
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
            else if (GetAsyncKeyState(VK_RETURN) != 0 && clearBuffer == 0)
            {
                std::cout << std::boolalpha;
                clearBuffer = 1;
                countBuffer++;
                MainMenu();
            }
            else if (countBuffer == 1)
            {
                clearBuffer = 0;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {

                switch(pointer)
                {
                    case int(MenuOptions::STATUS):
                    {
                        system("cls");
                        pressed = true;

                        std::cout << std::setw(10) << "SQUAD: " << " " << std::setw(10) << initUser.GetSquad()  << "\n\n";
                        std::cout << std::setw(10) << "LEAGUE: " << " " << std::setw(10) << initUser.GetLeague()  << "\n\n";
                        std::cout << std::setw(10) << "COUNTRY: " << " " << std::setw(10) << initUser.GetCountry() << "\n\n";
                        std::cout << std::setw(10) << "MANAGER: " << " " << std::setw(10) << initUser.GetUsername()  << "\n\n";

                        while(true)
                        {

                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

                            if(GetAsyncKeyState(VK_ESCAPE) != 0)
                            {
                                MainMenu();
                            }
                        }
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
                        while(true)
                        {


                            if(GetAsyncKeyState(VK_ESCAPE) != 0)
                            {
                                MainMenu();
                            }
                        }
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
        Players::InitPlayers(ManchesterInfield, InitManchesterInfield);
        Players::PrintPlayers(InitManchesterInfield);

        std::cout << '\n';

        Players::InitPlayers(ManchesterUSubs, InitManchesterSubs);
        Players::PrintPlayers(InitManchesterSubs);
         while(true)
        {



            if(GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                MainMenu();
            }
        }
    }

}
