#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>


#include "gameFunc.h"


/**
*       Game window class defined
*/
GameWindow::GameWindow()
{
    select_country =
    {
        "ITALY",
        "SPAIN",
        "GERMANY",
        "ENGLAND",
        "FRANCE"
    };
    select_league =
    {
        {"SERIE A", "SERIE B"},
        {"LaLiga", "SegundaDivision"},
        {"Bundesliga", "Bundesliga 2"},
        {"Premier League"},
        {"Ligue 1", "Ligue 2"}
    };
    select_squad =
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
    };
}

std::string GameWindow::generateSquad()
{
    std::string squad;
    while(true)
    {
        int col = rand() % 8 + 0;
        squad = select_squad[6][col];

        if (squad != initUser.GetSquad())
        {
            break;
        }
    }
    return squad;
}


void GameWindow::InitWindow()
{
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
    std::cout << "Enter manager's first and last name : ";
    std::cin >> firstname >> lastname;
    initUser.SetUserName(firstname, lastname);

    InitSquad();
}


void GameWindow::InitSquad()
{
    int pointer = -1;
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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

            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch(pointer)
                {
                    case int(CountryOption::ITALY):
                    {
                        Italy();
                    }
                    case int(CountryOption::SPAIN):
                    {
                        Spain();
                    }
                    case int(CountryOption::GERMANY):
                    {
                        Germany();
                    }
                    case int(CountryOption::ENGLAND):
                    {
                        std::string setCountry = "England";
                        initUser.SetCountry(setCountry);
                        England();
                    }
                    case int(CountryOption::FRANCE):
                    {
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
    int pointer = -1;
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
    int pointer = -1;
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
    int pointer = -1;
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
    int pointer = -1;
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
    int pointer = -1;
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
    int pointer = -1;
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
    MainWindow init;
    std::string squad;
    int pointer = -1;
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                switch(pointer)
                {
                    case int(PremierLgList::Liverpool):
                    {
                        squad = "Liverpool F.C.";
                        initUser.SetSquad(squad);
                        init.MainMenu();
                    }
                    case int(PremierLgList::ManchesterU):
                    {
                        squad = "Manchester United F.C.";
                        initUser.SetSquad(squad);
                        init.MainMenu();
                    }

                    case int(PremierLgList::Arsenal):
                    {
                        squad = "Arsenal F.C.";
                        initUser.SetSquad(squad);
                        init.MainMenu();
                    }
                    case int(PremierLgList::Chelsea):
                    {
                        squad = "Chelsea F.C.";
                        initUser.SetSquad(squad);
                        init.MainMenu();
                    }
                    case int(PremierLgList::Tottenham):
                    {
                        squad = "Tottenham Hotspur F.C.";
                        initUser.SetSquad(squad);
                        init.MainMenu();
                    }
                    case int(PremierLgList::CrystalPalace):
                    {
                        squad = "Crystal Palace F.C.";
                        initUser.SetSquad(squad);
                        init.MainMenu();
                    }
                    case int(PremierLgList::Everton):
                    {
                        squad = "Everton F.C.";
                        initUser.SetSquad(squad);
                        init.MainMenu();
                    }
                    case int(PremierLgList::ManchesterC):
                    {
                        squad = "Manchester City F.C.";
                        initUser.SetSquad(squad);
                        init.MainMenu();
                    }
                    case int(PremierLgList::Leicester):
                    {
                        squad = "Leicester City F.C.";
                        initUser.SetSquad(squad);
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
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
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                InitSquad();
            }
        }
        Sleep(150);
    }

}
