#include <iostream>
#include <windows.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>


#include <time.h>
#include <chrono>

#include "gameFunc.h"
#include "dbsSource.h"
#include "dbsCreation.h"

/**
*       User class definiton
*/

User::User()
{
}


std::string User::GetUsername() const
{
    return fullname;
}

void User::SetUserName(std::string &fn, std::string &ln)
{
    fullname = fn + " " + ln;
}
std::string User::GetCountry() const
{
    return country;
}

void User::SetCountry(std::string &setCountry)
{
    country = setCountry;
}

std::string User::GetLeague() const
{
    return league;
}

void User::SetLeague(std::string &setLeague)
{
    league = setLeague;
}

std::string User::GetSquad() const
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
    total_time(0)
{
    time1 = 0;
    time2 = 0;
    your_score = 0;
    opponent_score = 0;
    status = GameStatus::NONE;

    // game runs
    Run();
}

void Game::Run()
{
    GameWindow init;

}
int Game::GetTime1() const
{
    return time1;
}

void Game::SetTime2(int setTime2)
{
    time2 = setTime2;
}

int Game::GetTime2() const
{
    return time2;
}

void Game::SetTotalTime(int setTotalTime)
{
    total_time = setTotalTime;
}

int Game::GetTotalTime() const
{
    return total_time;
}

int Game::GetYourScore() const
{
    return your_score;
}

void Game::SetYourScore(int setYourScore)
{
    your_score = setYourScore;
}

int Game::GetOpponentScore() const
{
    return opponent_score;
}

void Game::SetOpponentScore(int setOpponentScore)
{
    opponent_score = setOpponentScore;
}

GameStatus Game::GetStatus() const
{
    return status;
}

void Game::SetStatus(GameStatus &setStatus)
{
    status = setStatus;
}



/**
*       Match stats class defined
*/
int Match_Stats::A_penalty = 0;
int Match_Stats::A_cornerkick = 0;
int Match_Stats::A_offside = 0;
int Match_Stats::A_out = 0;
int Match_Stats::A_attempt = 0;
int Match_Stats::A_shotongoal = 0;
int Match_Stats::A_injury = 0;
int Match_Stats::A_goal = 0;
int Match_Stats::A_foul = 0;
int Match_Stats::A_yellow = 0;
int Match_Stats::A_red = 0;

int Match_Stats::B_penalty = 0;
int Match_Stats::B_cornerkick = 0;
int Match_Stats::B_offside = 0;
int Match_Stats::B_out = 0;
int Match_Stats::B_attempt = 0;
int Match_Stats::B_shotongoal = 0;
int Match_Stats::B_injury = 0;
int Match_Stats::B_goal = 0;
int Match_Stats::B_foul = 0;
int Match_Stats::B_yellow = 0;
int Match_Stats::B_red = 0;

void Match_Stats::stats_get()
{
    std::cout << "Player A:"
    "  penalty: "    << A_penalty <<
    ", cornerkick: " << A_cornerkick <<
    ", offside: "    << A_offside <<
    ", out: "        << A_out <<
    ", attempt: "    << A_attempt <<
    ", shotongoal: " << A_shotongoal <<
    ", injury: "     << A_injury <<
    ", foul: "       << A_foul <<
    ", yellow: "     << A_yellow <<
    ", red: "        << A_red <<
    ", goal: "       << A_goal <<
    std::endl;

    std::cout << "Player B:"
    "  penalty: "    << B_penalty <<
    ", cornerkick: " << B_cornerkick <<
    ", offside: "    << B_offside <<
    ", out: "        << B_out <<
    ", attempt: "    << B_attempt <<
    ", shotongoal: " << B_shotongoal <<
    ", injury: "     << B_injury <<
    ", foul: "       << B_foul <<
    ", yellow: "     << B_yellow <<
    ", red: "        << B_red <<
    ", goal: "       << B_goal <<
    std::endl;
}

void Match_Stats::stats_upload(std::string event, std::string team)
{
    //ADD LINE: pass event,team to comment class or pass it from Simulation class
    if (event=="penalty" && team=="A")
    A_penalty+= 1;
    else if (event=="cornerkick" && team=="A")
    A_cornerkick+= 1;
    else if (event=="offside" && team=="A")
    A_offside+= 1;
    else if (event=="out" && team=="A")
    A_out+= 1;
    else if (event=="attempt" && team=="A")
    A_attempt+= 1;
    else if (event=="shotongoal" && team=="A")
    A_shotongoal+= 1;
    else if (event=="injury" && team=="A")
    A_injury+= 1;
    else if (event=="goal" && team=="A")
    A_goal+= 1;
    else if (event=="foul" && team=="A")
    A_foul++;
    else if (event=="yellow" && team=="A")
    A_yellow++;
    else if (event=="red" && team=="A")
    A_red++;

    else if (event=="penalty" && team=="B")
    B_penalty++;
    else if (event=="cornerkick" && team=="B")
    B_cornerkick++;
    else if (event=="offside" && team=="B")
    B_offside++;
    else if (event=="out" && team=="B")
    B_out++;
    else if (event=="attempt" && team=="B")
    B_attempt++;
    else if (event=="shotongoal" && team=="B")
    B_shotongoal++;
    else if (event=="injury" && team=="B")
    B_injury++;
    else if (event=="goal" && team=="B")
    B_goal++;
    else if (event=="foul" && team=="B")
    B_foul++;
    else if (event=="yellow" && team=="B")
    B_yellow++;
    else if (event=="red" && team=="B")
    B_red++;
}


void Match_Stats::stats_reset()
{
    A_penalty = 0;
    A_cornerkick = 0;
    A_offside = 0;
    A_out = 0;
    A_attempt = 0;
    A_shotongoal = 0;
    A_injury = 0;
    A_goal = 0;
    A_foul = 0;
    A_yellow = 0;
    A_red = 0;

    B_penalty = 0;
    B_cornerkick = 0;
    B_offside = 0;
    B_out = 0;
    B_attempt = 0;
    B_shotongoal = 0;
    B_injury = 0;
    B_goal = 0;
    B_foul = 0;
    B_yellow = 0;
    B_red = 0;

}

//     SERIOUS_INJURY
//     TEMPORARY_INJURY
//     LIGHT_INJURY
//     PENALTY_AT
//     PENALTY_DEFF
//     GOAL_AT
//     CORNERKICK_AT
//     ATTEMPT_DEFF_PENALTY
//     ATTEMPT_DEFF
//     ATTEMPT_AT
//     ATTEMPT_DEFF_CORNERKICK
//     CORNERKICK_DEFF_PENALTY
//     CORNERKICK_DEFF
//     SHOTONGOAL_AT
//     SHOTONGOAL_DEFF_CORNERKICK
//     SHOTONGOAL_DEFF



/**
*       Game simulation class defined
*/
bool Simulation::event_foul(int bonus_foul,std::string team)
{

    int random = rand() % 101 ;
    int foul = 5 + bonus_foul;

    if (random <= 101 * foul / 100)
    {
        Stats.stats_upload("foul",team);
        if (random <= 101 * 70 / 100)
        {
            //ADD LINE: name = get random name from team
            //ADD LINE: pass name to Match_Stats class
            return true;
        }
        else if(random <= 101 * 90 / 100)
        {
            Stats.stats_upload("yellow",team);
            //ADD LINE: name = get random name from team
            //ADD LINE: pass name to Match_Stats class
            return true;
        }
        else
        {
            Stats.stats_upload("red",team);
            //ADD LINE: name = get random name from team
            //ADD LINE: pass name to Match_Stats class
            return true;
        }
    }
    else
        return false;
}

void Simulation::event_injury(int serious_injury, int temporary_injury, std::string team)
{
    int random = rand() % 101 ;
    int injury_3 = 5 + serious_injury;

    if (random <= 101 * injury_3 / 100)
    {
        Stats.stats_upload("injury",team);
        // ADD LINE: suspend player for whole match
        // ADD LINE: update class for current match stats, VALUE: SERIOUS_INJURY
        std::cout << "SERIOUS_INJURY" << std::endl;
    }
    else
    {
        int injury_2 = 15 + temporary_injury;
        if (random <= 101 * injury_2 / 100)
        {
            Stats.stats_upload("injury",team);
            // ADD LINE: suspend player for some time in match, add some penalty for injured player
            // ADD LINE: update class for current match stats, VALUE: TEMPORARY_INJURY
            std::cout << "TEMPORARY_INJURY" << std::endl;
        }
        else
        {
            Stats.stats_upload("injury",team);
            // ADD LINE: add some penalty for injured player
            // ADD LINE: update class for current match stats, VALUE: LIGHT_INJURY
            std::cout << "LIGHT_INJURY" << std::endl;
        }
    }
}

void Simulation::event_penalty(int attackers_effectivity, int goalkeepers_effectivity, std::string team)
{
    int A_Number = attackers_effectivity + 500;
    int G_Number = goalkeepers_effectivity + 500;
    int random = rand() % (A_Number + G_Number);

    if (random <= A_Number)
    {
        Stats.stats_upload("penalty",team);
        Stats.stats_upload("goal",team);
        // ADD LINE: update class for current match stats, VALUE: PENALTY_AT, GOAL_AT
        std::cout << "PENALTY_AT, GOAL_AT" << std::endl;
    }
    else
    {
        Stats.stats_upload("penalty",team);
        // ADD LINE: update class for current match stats, VALUE: PENALTY_DEFF
        std::cout << "PENALTY_DEFF" << std::endl;
    }
}

void Simulation::event_cornerkick(int attackers_effectivity, int deffenders_effectivity, int goalkeepers_effectivity,
                                  std::string team)
{
    int A_Number = attackers_effectivity + 500;
    int D_Number = deffenders_effectivity + 500;
    int random = rand() % (A_Number + D_Number);

    if (random <= A_Number)
    {
        int shotongoal = A_Number * 20 / 100;
        if (random <= shotongoal)
        {
            Stats.stats_upload("cornerkick",team);
            // ADD LINE: update class for current match stats, VALUE: CORNERKICK_AT
            std::cout << "CORNERKICK_AT, event_shotongoal" << std::endl;
            event_shotongoal(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity, team);
        }
        else
        {
            Stats.stats_upload("cornerkick",team);
            Stats.stats_upload("attempt",team);
            // ADD LINE: update class for current match stats, VALUE: CORNERKICK_AT, ATTEMPT_AT
            std::cout << "CORNERKICK_AT, ATTEMPT_AT" << std::endl;
        }
    }
    else
    {
        int penalty = D_Number * 1 / 100 + D_Number;
        if (random <= penalty)
        {
            Stats.stats_upload("cornerkick",team);
            // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF_PENALTY
            std::cout << "CORNERKICK_DEFF_PENALTY, event_penalty" << std::endl;
            event_penalty(attackers_effectivity, goalkeepers_effectivity, team);
        }
        else
        {
          Stats.stats_upload("cornerkick",team);
          // ADD LINE: update class for current match stats, VALUE: CORNERKICK_DEFF
          std::cout << "CORNERKICK_DEFF" << std::endl;
        }
    }
}

void Simulation::event_shotongoal(int attackers_effectivity, int deffenders_effectivity, int goalkeepers_effectivity,
                                  std::string team)
{
    int A_Number = attackers_effectivity + 500;
    int G_Number = goalkeepers_effectivity + 500;
    int random = rand() % (A_Number + G_Number + 1);

    if (random <= A_Number)
    {
        int goal = A_Number * 25 / 100;
        if (random <= goal)
        {
            Stats.stats_upload("shotongoal",team);
            Stats.stats_upload("goal",team);
            // ADD LINE: update class for current match stats, VALUE: ?SHOTONGOAL_AT, GOAL_AT
            std::cout << "SHOTONGOAL_AT, GOAL_AT" << std::endl;
        }
        else
        {
            Stats.stats_upload("shotongoal",team);
            // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_AT
            std::cout << "SHOTONGOAL_AT" << std::endl;
        }
    }
    else
    {
        int cornerkick = G_Number * 10 / 100 + G_Number;
        if (random <= cornerkick )
        {
            Stats.stats_upload("shotongoal",team);
            // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_DEFF_CORNERKICK
            std::cout << "SHOTONGOAL_DEFF_CORNERKICK, event_cornerkick" << std::endl;
            event_cornerkick(attackers_effectivity, deffenders_effectivity, goalkeepers_effectivity, team);
        }
        else
        {
            Stats.stats_upload("shotongoal",team);
            // ADD LINE: update class for current match stats, VALUE: SHOTONGOAL_DEFF
            std::cout << "SHOTONGOAL_DEFF" << std::endl;
        }
    }
}


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

    std::cout << "Enter manager's first name : ";
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
                        init.MainMenu();
                    }
                    case int(PremierLgList::Liverpool):
                    {
                        std::string setSquad = "Liverpool F.C.";
                        initUser.SetSquad(setSquad);
                        init.MainMenu();
                    }
                    case int(PremierLgList::Arsenal):
                    {
                        std::string setSquad = "Arsenal F.C.";
                        initUser.SetSquad(setSquad);
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
    while(true)
    {
        if(GetAsyncKeyState(VK_ESCAPE) != 0)
        {
            MainMenu();
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        if(GetAsyncKeyState(VK_ESCAPE) != 0)
        {
            MainMenu();
        }
    }
}
