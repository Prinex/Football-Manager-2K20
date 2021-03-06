#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include "include/gameFunc.h"

// clrscr function declared
void clrscr()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

/**
 *  Game window class defined
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
        {"Liverpool F.C.", "Manchester United F.C.", "Arsenal F.C.", "Chelsea F.C.", "Tottenham Hotspur F.C.", "Crystal Palace F.C.", "Everton F.C.", "Manchester City F.C.", "Leicester City F.C."},
        {"Paris-Saint-Germain F.C.", "FC Nantes", "As Monaco", "OGC Nice", "Toulouse FC"},
        {"Le Havre", "AS Nancy", "FC Lorient", "RC Lens"}
    }
{
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
            strcpy_s(effect, ".");
            std::cout << effect;
        } 
        clrscr();
    }
    std::string firstname, lastname;
    std::cout << "Enter manager's first and last name : ";
    std::cin >> firstname >> lastname;
    initUser->SetUsername(firstname, lastname);

    InitSquad();
}


void GameWindow::InitSquad()
{
    int pointer = -1;
    while(true)
    {
        clrscr();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "Choose a country: " << "\n\n";
        for(auto it = select_country.begin(); it < select_country.end(); it = std::next(it))
        {
            if (std::distance(select_country.begin(), it) == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << '\t';
                std::cout << ">";
                std::cout << *it << "\n\n";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << ">";
                std::cout << '\t';
                std::cout << *it << "\n\n";
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

                if (pointer == select_country.size())
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
                        initUser->SetCountry(select_country[pointer]);
                        Italy();
                    }
                    case int(CountryOption::SPAIN):
                    {
                        initUser->SetCountry(select_country[pointer]);
                        Spain();
                    }
                    case int(CountryOption::GERMANY):
                    {
                        initUser->SetCountry(select_country[pointer]);
                        Germany();
                    }
                    case int(CountryOption::ENGLAND):
                    {
                        initUser->SetCountry(select_country[pointer]);
                        England();
                    }
                    case int(CountryOption::FRANCE):
                    {
                        initUser->SetCountry(select_country[pointer]);
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

        clrscr();
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

        clrscr();
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

        clrscr();
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

        clrscr();
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
                        initUser->SetLeague(select_league[int(CountryOption::ENGLAND)][pointer]);
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

        clrscr();
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
        clrscr();
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
        clrscr();
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
        clrscr();
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
        clrscr();
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
        clrscr();
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
        clrscr();
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
    int pointer = -1;
    while(true)
    {
        clrscr();
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
                        initUser->SetSquad(select_squad[int(CountryOption::ENGLAND)+3][pointer]);
                        mainWin->MainMenu();
                    }
                    case int(PremierLgList::ManchesterU):
                    {
                        initUser->SetSquad(select_squad[int(CountryOption::ENGLAND)+3][pointer]);
                        mainWin->MainMenu();
                    }

                    case int(PremierLgList::Arsenal):
                    {
                        initUser->SetSquad(select_squad[int(CountryOption::ENGLAND)+3][pointer]);
                        mainWin->MainMenu();
                    }
                    case int(PremierLgList::Chelsea):
                    {
                        initUser->SetSquad(select_squad[int(CountryOption::ENGLAND)+3][pointer]);
                        mainWin->MainMenu();
                    }
                    case int(PremierLgList::Tottenham):
                    {
                        initUser->SetSquad(select_squad[int(CountryOption::ENGLAND)+3][pointer]);
                        mainWin->MainMenu();
                    }
                    case int(PremierLgList::CrystalPalace):
                    {
                        initUser->SetSquad(select_squad[int(CountryOption::ENGLAND)+3][pointer]);
                        mainWin->MainMenu();
                    }
                    case int(PremierLgList::Everton):
                    {
                        initUser->SetSquad(select_squad[int(CountryOption::ENGLAND)+3][pointer]);
                        mainWin->MainMenu();
                    }
                    case int(PremierLgList::ManchesterC):
                    {
                        initUser->SetSquad(select_squad[int(CountryOption::ENGLAND)+3][pointer]);
                        mainWin->MainMenu();
                    }
                    case int(PremierLgList::Leicester):
                    {
                        initUser->SetSquad(select_squad[int(CountryOption::ENGLAND)+3][pointer]);
                        mainWin->MainMenu();
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
        clrscr();
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
        clrscr();
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

std::shared_ptr<GameWindow> gameWin = std::make_shared<GameWindow>();
