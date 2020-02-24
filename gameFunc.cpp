#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <iomanip>
#include "gameFunc.h"
#include <stdlib.h>


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
*       GameWindow class declarations
*/

GameWindow::GameWindow() :
    firstname(""),
    lastname(""),
    fullName(""),
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

    std::string fn, ln;
    std::cout << "Choose manager's first and last name: ";
    std::cin >> fn >> ln;
    SetUsername(fn, ln);

    system("cls");

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
                        SetSelectedCountry(select_country[int(CountryOption::ITALY)]);
                        clearBuffer = 0;
                        Italy();
                    }
                    case int(CountryOption::SPAIN):
                    {
                        SetSelectedCountry(select_country[int(CountryOption::SPAIN)]);
                        clearBuffer = 0;
                        Spain();
                    }
                    case int(CountryOption::GERMANY):
                    {
                        SetSelectedCountry(select_country[int(CountryOption::GERMANY)]);
                        clearBuffer = 0;
                        Germany();
                    }
                    case int(CountryOption::ENGLAND):
                    {
                        SetSelectedCountry(select_country[int(CountryOption::ENGLAND)]);
                        clearBuffer = 0;
                        England();
                    }
                    case int(CountryOption::FRANCE):
                    {
                        SetSelectedCountry(select_country[int(CountryOption::FRANCE)]);
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
                        SetSelectedLeague(select_league[0][int(LeagueOption::SERIE_A)]);

                        SerieA();
                    }
                    case int(LeagueOption::SERIE_B):
                    {

                        SetSelectedLeague(select_league[0][int(LeagueOption::SERIE_B)]);

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
                        SetSelectedLeague(select_league[1][int(LeagueOption::LaLiga)]);
                        Laliga();
                    }
                    case int(LeagueOption::SegundaDivision):
                    {

                        SetSelectedLeague(select_league[1][int(LeagueOption::SegundaDivision)]);
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
                        SetSelectedLeague(select_league[2][int(LeagueOption::Bundesliga)]);
                        BL();
                    }
                    case int(LeagueOption::Bundesliga2):
                    {
                        SetSelectedLeague(select_league[2][int(LeagueOption::Bundesliga2)]);
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
                        SetSelectedLeague(select_league[3][int(LeagueOption::Premier_League)]);
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
                        SetSelectedLeague(select_league[4][int(LeagueOption::Ligue1)]);
                        Lig1();
                    }
                    case int(LeagueOption::Ligue2):
                    {
                        SetSelectedLeague(select_league[4][int(LeagueOption::Ligue2)]);
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
                        SetSelectedSquad(select_league[3][int(PremierLgList::ManchesterU)]);
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
*       Setters and getters methods defined
*/

std::string GameWindow::GetUsername()
{
    return fullName;
}

void GameWindow::SetUsername(std::string &firstname, std::string &lastname)
{
    fullName = "Mr. " + firstname + " " + lastname;
}


std::string GameWindow::GetSelectedCountry()
{
    return country;
}


void GameWindow::SetSelectedCountry(std::string &country)
{
    country = country;
}


std::string GameWindow::GetSelectedLeague()
{
    return league;
}


void GameWindow::SetSelectedLeague(std::string &league)
{
    league = league;
}


std::string GameWindow::GetSelectedtSquad()
{
    return squad;
}


void GameWindow::SetSelectedSquad(std::string &squad)
{
    squad = squad;
}


/**
*       MainWindow class definitions
*/

MainWindow::MainWindow() :
    pressed(false),
    Options
    {
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
                std::cout << Options[i] << '\t';
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << Options[i] << '\t';
            }
        }

        while(true)
        {
            if (GetAsyncKeyState(VK_LEFT) != 0)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = 6;
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
