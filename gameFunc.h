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
