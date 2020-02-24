#ifndef GAMEFUNC_H_INCLUDED
#define GAMEFUNC_H_INCLUDED

#include <string>
#include <array>
#include <vector>




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

enum class LeagueOption{SERIE_A, SERIE_B, LaLiga = 0, SegundaDivision = 1, Bundesliga = 0, Bundesliga2 = 1, Premier_League = 0, Ligue1 = 0, Ligue2 = 1};

enum class PremierLgList{Liverpool, ManchesterU, Arsenal, Chelsea, Tottenham, CrystalPalace, Everton, ManchesterC, Leicester};


const int SIZE1 = 5;


class GameWindow
{
    std::string firstname, lastname, fullName;
    std::string country, league, squad;
    std::array<std::string, SIZE1> select_country;
    std::vector<std::vector<std::string>> select_league;
    std::vector<std::vector<std::string>> select_squad;

public:
    GameWindow();
    bool clearBuffer = false;


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

    std::string GetUsername();
    void SetUsername(std::string &firstname, std::string &lastname);

    std::string GetSelectedCountry();
    void SetSelectedCountry(std::string &country);

    std::string GetSelectedLeague();
    void SetSelectedLeague(std::string &league);

    std::string GetSelectedtSquad();
    void SetSelectedSquad(std::string &squad);



};


enum class MenuOptions{UEFA, KickOff, BuyPlayer, SellPlayer, ViewSquad, SwitchPlayers, Exit};


const int COUNT = 7;


class MainWindow : public GameWindow
{
    bool pressed;
    std::array<std::string, COUNT> Options;

public:
    MainWindow();

    int clearBuffer = false;
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
