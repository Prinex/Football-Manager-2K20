#ifndef DBS_H_INCLUDED
#define DBS_H_INCLUDED

#include <iostream>
#include <vector>

struct Players
{
public:
    //PLAYER BIO
    std::string name;
    int age;
    std::string nationality;
    int height;
    double weight;
    int number;
    std::string position;
    std::string morale;
    int value;

    //PLAYER SKILLS
    int pace;
    int shooting;
    int passing;
    int dribbling;
    int defending;
    int physical;
    //GOALKEEPERS
    int reflexes;
    int diving;
    int handling;
    int skill_position;
    int overall_points;

public:
    Players(std::string name, int age, std::string nationality, int height, double weight, int number,  std::string position,
            std::string morale, int value, int pace, int shooting, int passing, int dribbling, int defending, int physical, int reflexes,
            int diving, int handling, int skill_position, int overall_points);
};


class Squad
{
private:
    std::string squad_name, league, manager;
    std::vector<Players> inField;
    std::vector<Players> subs;

public:
    Squad(std::string squad_name, std::string league, std::string manager, std::vector<Players> &inField, std::vector<Players> &subs);

    std::string GetName() const;
    std::string GetLeague() const;
    std::string GetManager() const;

    bool GetPlayers();
    bool viewPlayer(const std::string &player, std::vector<Players> &dst);
};











#endif // DBS_H_INCLUDED
