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
