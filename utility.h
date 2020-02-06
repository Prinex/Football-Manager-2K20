#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include "gameFunc.h"


/**
 *      Using enumeration classes helps to work with switch statements
 *      As in the below scenario we'll have an interface
 */
enum class CountryOption{ITALY, SPAIN, GERMANY, ENGLAND, FRANCE};

enum class LeagueOption{SERIE_A, SERIE_B, LaLiga, SegundaDivision, Bundesliga, Bundesliga2, Premier_League, Ligue1, Ligue2};


/**
 *      Game Window will adds an effect of loading screen and will allow us to type in an username
 */
class GameWindow
{
    /**
     *      @attribute firstname, lastname, fullname - receive input
     *      @attribute show_countries, show_leagues, showt_squads - arrays for displaying the options as text
     *      @attriubte select_country, select_league, select_squad - initializes attributes with a given option
     */
    std::string firstname, lastname, fullName;

    std::string select_country;
    std::string select_league;
    std::string select_squad;

    std::array<std::string, SIZE1> show_countries;
    std::array<std::string, SIZE2> show_leagues;
    std::vector<std::vector<std::string>> show_squads;



public:
    GameWindow();
    /**
    *       GameWindow() - initialize object when creating it / method call
    */


    void ShowConsoleCursor(bool showFlag);
    /**
    *       ShowConsoleCursor() - disables window's flickering cursor
    *       @param showFlag - false(disables it)
    */

    void InitWindow();
    /**
    *       InitWindow() - Initializes the game window for initializing a profile
    */

    std::string GetUsername();
    /**
    *       GetUsername() - access private attriubte
    *       @return username
    */
    void SetUsername(std::string username);
    /**
    *       SetUsername() - sets the username according to a given input
    *       @param username where username = firstname + lastname
    */

    std::string GetSelectCountry();
    /**
    *       GetSelectCountry() - access attribute and returns it
    *       @return select_country attribute
    */
    void SetSelectCountry(std::string select_country);
    /**
    *       SetSelectCountry() - Sets private attribute to with a given option
    *       @param select_country
    */

    std::string GetSelectLeague();
    /**
    *       GetSelectLeague() - access attribute and returns it
    *       @return the league specified
    */
    void SetSelectLeague(std::string select_league);
    /**
    *       SetSelectLeague() - Sets private attribute to with a given option
    *       @param select_league a string containing an input
    */

    std::string GetSelectTeam();
    /**
    *       GetSelectTeam() - access attribute and returns it
    *       @return the team specified
    */
    void SetSelect_team(std::string select_team);



};

/**
*       Same as above
*/
enum class MenuOptions{UEFA, KickOff, Transfers, Squad = 3, BuyPlayer = 0, SellPlayer = 1, ViewSquad = 0, SwitchPlayers = 1, Exit = 4};

const int COUNT = 9;

class MainWindow : public GameWindow
{
    bool pressed;
    std::array<std::string, COUNT> Options;

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




#endif // UTILITY_H_INCLUDED
