#ifndef GAMEFUNC_H_INCLUDED
#define GAMEFUNC_H_INCLUDED

#include <string>
#include <array>
#include <vector>

#include "gameFunc.h"



class User
{
    private:
    std::string firstname, lastname, fullname;
    std::string country, league, squad;

public:
    User();

    std::string GetUsername() const;
    void SetUserName(std::string &fn, std::string &ln);

    std::string GetCountry() const;
    void SetCountry(std::string &setCountry);

    std::string GetLeague() const;
    void SetLeague(std::string &setLeague);

    std::string GetSquad() const;
    void SetSquad(std::string &setSquad);


};

extern User initUser;



enum class GameStatus{NONE, PLAYING, WIN, LOSE, PAUSE, ABANDON, EXIT};



class Game
{
private:
    unsigned int total_time;
    unsigned int time1, time2;
    unsigned int your_score, opponent_score;
    GameStatus status;

public:
    Game();
    static void Run();

    int GetTime1() const;
    void SetTime1(int setTime1);

    void SetTime2(int setTime2);
    int GetTime2() const;

    void SetTotalTime(int setTotalTime);
    int GetTotalTime() const;

    int GetYourScore() const;
    void SetYourScore(int setYourScore);

    int GetOpponentScore() const;
    void SetOpponentScore(int setOpponentScore);

    GameStatus GetStatus() const;
    void SetStatus(GameStatus setStatus);
};


class Match_Stats
{
private:
    static int A_penalty;
    static int A_cornerkick;
    static int A_offside;
    static int A_out;
    static int A_attempt;
    static int A_shotongoal;
    static int A_injury;
    static int A_goal;
    static int A_foul;
    static int A_yellow;
    static int A_red;

    static int B_penalty;
    static int B_cornerkick;
    static int B_offside;
    static int B_out;
    static int B_attempt;
    static int B_shotongoal;
    static int B_injury;
    static int B_goal;
    static int B_foul;
    static int B_yellow;
    static int B_red;


public:
    void stats_get();

    void stats_upload(std::string event, std::string team);

    void stats_reset();

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
};


class Simulation
{
private:
    Match_Stats Stats;

    //     std::string event_player()
    //     {
    //         private:
    //         int random = rand() % 1;
    //         std::string text_header;
    //         std::array <std::string> options[3];

    //         public:

    //         std::string pl_event()
    //         {
    //             for (i,options,i++)
    //             return text_header
    //         }
    //     }

    bool event_foul(int bonus_foul,std::string team);

    // Create foul card system

    void event_injury(int serious_injury, int temporary_injury, std::string team);

    void event_penalty(int attackers_effectivity, int goalkeepers_effectivity, std::string team);

    void event_cornerkick(int attackers_effectivity,int deffenders_effectivity, int goalkeepers_effectivity,
                          std::string team);

    void event_shotongoal(int attackers_effectivity, int deffenders_effectivity, int goalkeepers_effectivity,
                          std::string team);

    void event_attempt(int attackers_effectivity, int deffenders_effectivity, int goalkeepers_effectivity,
                       std::string team);

    std::string event_type();

    std::string event_auto(int penalty_bonus = 0, int cornerkick_bonus = 0, int offside_bonus = 0,
                           int out_bonus = 0, int attempt_bonus = 0,int shotongoal_bonus = 0,
                           int injury_bonus = 0);

    std::string matchopportunity_player(int playerA_possesion, int playerB_possesion);

public:
    bool matchopportunity_mechanics(int playerA_possesion, int playerB_possesion); // Use for game loop

};



enum class CountryOption{ITALY, SPAIN, GERMANY, ENGLAND, FRANCE};

enum class LeagueOption{SERIE_A, SERIE_B, LaLiga = 0, SegundaDivision = 1, Bundesliga = 0, Bundesliga2 = 1, Premier_League = 0, Ligue1 = 0, Ligue2 = 1};

enum class PremierLgList{Liverpool, ManchesterU, Arsenal, Chelsea, Tottenham, CrystalPalace, Everton, ManchesterC, Leicester};



const int SIZE1 = 5;

class GameWindow
{
private:
    std::array<std::string, SIZE1> select_country;
    std::vector<std::vector<std::string>> select_league;
    std::vector<std::vector<std::string>> select_squad;

public:
    GameWindow();


    std::string generateSquad();


    void InitWindow();
    void InitSquad();
    void ShowConsoleCursor(bool showFlag);

    void Italy();
    void Spain();
    void Germany();
    void England();
    void France();

    void SerieA();
    void SerieB();
    void Laliga();
    void SegundaDiv();
    void BL();
    void BL2();
    void PremierL();
    void Lig1();
    void Lig2();
};


enum class MenuOptions{STATUS, UEFA, KickOff, BuyPlayer, SellPlayer, ViewSquad, SwitchPlayers, Exit};


const int COUNT = 8;



class MainWindow : public GameWindow
{
private:
    std::array<std::string, COUNT> Options;

public:
    MainWindow();

    std::string generatePlayer(std::string squad);

    bool MainMenu();
    bool Status();

    bool KickOff();
    bool UEFA();

    bool BuyPlayer(std::string search_name, int amount);
    bool SellPlayer(std::string search_name, int amount);

    bool ViewSquad();
    bool SwitchPlayer(std::string name);
};





#endif // GAMEFUNC_H_INCLUDED
