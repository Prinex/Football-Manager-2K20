#ifndef GAMEFUNC_H_INCLUDED
#define GAMEFUNC_H_INCLUDED

#include <string>
#include <array>
#include <vector>


const int SIZE1 = 5;
const int SIZE2 = 9;

enum class GameStatus{NONE, PLAYING, WIN, LOSE, PAUSE, ABANDON, EXIT};



class Game
{
    int time1, time2, total_time;
    int your_score, opponent_score;
    GameStatus status;

public:
    Game();
    void Run();

    int GetTime();
    void SetTime1(int time);

    int GetTotalTime();
    void SetTotalTime(int total_time);

    int GetYourScore();
    void SetYourScore(int your_score);

    int GetOpponentScore();
    void SetOpponentScore(int opponent_score);

    GameStatus GetStatus();
    void SetStatus(GameStatus status);

};



enum class CountryOption{ITALY, SPAIN, GERMANY, ENGLAND, FRANCE};

enum class LeagueOption{SERIE_A, SERIE_B, LaLiga, SegundaDivision, Bundesliga, Bundesliga2, Premier_League, Ligue1, Ligue2};



class GameWindow
{
    std::string firstname, lastname, fullName;
    std::array<std::string, SIZE1> select_country;
    std::array<std::string, SIZE2> select_league;
    std::vector<std::vector<std::string>> select_squad;

public:
    GameWindow();

    void ShowConsoleCursor(bool showFlag);
    void InitWindow();

    std::string GetUsername();
    void SetUsername(std::string username);

    std::string GetSelectCountry();
    void SetSelectCountry(std::string select_country);

    std::string GetSelectLeague();
    void SetSelectLeague(std::string select_league);

    std::string GetSelectTeam();
    void SetSelect_team(std::string select_team);



};


enum class MenuOptions{UEFA, KickOff, Transfers, Squad = 3, BuyPlayer = 0, SellPlayer = 1, ViewSquad = 0, SwitchPlayers = 1, Exit = 4};


const int COUNT = 5;
const int COUNT2 = 2;
const int COUNT3 = 2;


class MainWindow : public GameWindow
{
    bool pressed;
    std::array<std::string, COUNT> Options;
    std::array<std::string, COUNT2> SubOptions1;
    std::array<std::string, COUNT3> SubOptions2;

public:
    MainWindow();

    void MainMenu();

    void KickOff();

    void UEFA();

    void Transfers(std::string buy_option, std::string sell_option);
    bool BuyPlayer(std::string search_name);
    bool SellPlayer(std::string search_name, int amount);

    void Squad(std::string view_option, std::string switch_option);
    void ViewSquad();
    bool SwitchPlayer(std::string name);

    void Status();
};





#endif // GAMEFUNC_H_INCLUDED
