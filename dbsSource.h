#ifndef DBS_H_INCLUDED
#define DBS_H_INCLUDED

#include <iostream>
#include <vector>



class Players
{
private:
    //PLAYER BIO
    const std::string name;
    int age;
    const std::string nationality;
    int height;
    double weight;
    int number;
    std::string position;
    const std::string morale;
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

    Players(const std::string &name,int age, const std::string &nationality, int height, double weight, int number, std::string position,
            std::string morale, int value, int pace, int shooting, int passing, int dribbling, int defending, int physical, int reflexes,
            int diving, int handling, int skill_position, int overall_points);

    static void InitPlayers(std::vector<Players> &source, std::vector<Players> &dest);

    static void PrintPlayers(std::vector<Players> &players);

};


class Squad
{
public:
    std::string squad_name, league, manager;
    const int noInField, noSub;

public:
    Squad(const std::string &squad_name, const std::string &league, const std::string &manager, const int noInField, const int noSub);


};














#endif // DBS_H_INCLUDED
