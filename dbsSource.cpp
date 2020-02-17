#include "dbsSource.h"
#include <iostream>
#include <iomanip>


Players::Players(const std::string &name, int age, const std::string &nationality, int height, double weight, int number, const std::string &position,
                 const std::string &morale, int value, int pace, int shooting, int passing, int dribbling, int defending, int physical, int reflexes,
                 int diving, int handling, int skill_position, int overall_points) :
                     name(name),
                     age(age),
                     nationality(nationality),
                     height(height),
                     weight(weight),
                     number(number),
                     position(position),
                     morale(morale),
                     value(value),
                     pace(pace),
                     shooting(shooting),
                     passing(passing),
                     dribbling(dribbling),
                     defending(defending),
                     physical(physical),
                     reflexes(reflexes),
                     diving(diving),
                     handling(handling),
                     skill_position(skill_position),
                     overall_points(overall_points)
{
}


void Players::InitPlayers(std::vector<Players> &source, std::vector<Players> &dest)
{
    for(unsigned int i = 0; i < source.size(); i++)
    {
        dest.push_back(Players(source[i].name, source[i].age, source[i].nationality, source[i].height, source[i].weight, source[i].number, source[i].position, source[i].morale,
                               source[i].value, source[i].pace, source[i].shooting, source[i].passing, source[i].dribbling, source[i].defending, source[i].physical, source[i].reflexes,
                               source[i].diving, source[i].handling, source[i].skill_position, source[i].overall_points));
    }
}

void Players::PrintPlayers(std::vector<Players> &players)
{
    std::cout << std::setw(22) << "Name :" << std::setw(22) << "Position :" << "\n\n";
    for(unsigned int i = 0; i < players.size(); i++)
    {
        std::cout<< std::setw(22) << players[i].name << std::setw(22) << players[i].position << '\n';
    }
}




Squad::Squad(const std::string &squad_name, const std::string &league, const std::string &manager, const int noInField, const int noSub) :
    squad_name{squad_name},
    league{league},
    manager(manager),
    noInField{noInField},
    noSub{noSub}
{
}
