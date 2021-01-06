#ifndef GAMEFUNC_H_INCLUDED
#define GAMEFUNC_H_INCLUDED

// #define clrscr() std::cout << "\033[2J\033[1;1H"

#include <iostream>
#include <memory>
#include <string>
#include <array>
#include <vector>



// singleton pattern for all classes (initialized only once)


void clrscr();

class User
{
private:
    std::string fullname;
    std::string country, league, squad;

public:
    User();
    void SetUsername(const std::string& fname, const std::string& lname);
    std::string GetUsername() const;

    std::string GetCountry() const;
    void SetCountry(const std::string &setCountry);

    std::string GetLeague() const;
    void SetLeague(const std::string &setLeague);

    std::string GetSquad() const;
    void SetSquad(const std::string &setSquad);
};

extern std::shared_ptr<User> initUser;

enum class GameStatus{NONE, PLAYING, WIN, LOSE, EXIT};



class Game
{
private:
    GameStatus status;
    int gameTime, penalty, cornerkick, offside, out, attempt, injury, foul, yellow, red, goal;
    int penalty1, cornerkick1, offside1, out1, attempt1, injury1, foul1, yellow1, red1, goal1;

public:
    Game();

    GameStatus GetStatus() const;
    void SetStatus(GameStatus setStatus);
        
    void Simulate();
    void ResetGame();
    void gotoxy(short x, short y);
    int GenerateSquad();
    int GeneratePlayer();
};

extern std::shared_ptr<Game> game;



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

extern std::shared_ptr<GameWindow> gameWin;


enum class MenuOptions{STATUS, KickOff, ViewSquad, SwitchPlayers, Exit};


const int COUNT = 5;

class MainWindow : protected GameWindow
{
private:
    std::array<std::string, COUNT> Options;

public:
    MainWindow();

    void MainMenu();
    void Status();

    void KickOff();

    void ViewSquad();
    void SwitchPlayer();
};

extern std::shared_ptr<MainWindow> mainWin;



#endif // GAMEFUNC_H_INCLUDED
