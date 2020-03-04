#include "dbsSource.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "gameFunc.h"



/**
*       Players class definiton
*/
Players::Players(std::string name, int age, std::string nationality, int height, double weight, int number,  std::string position,
                 std::string morale, int value, int pace, int shooting, int passing, int dribbling, int defending, int physical, int reflexes,
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




/**
*       Squad class definitions
*/
Squad::Squad(std::string squad_name, std::string league, std::string manager, std::vector<Players> &inField, std::vector<Players> &subs, int noInField, int noSub) :
    squad_name{squad_name},
    league{league},
    manager{manager},
    inField{inField},
    subs{subs},
    noInField(noInField),
    noSub(noSub)
{
}



std::string Squad::GetName() const
{
    return squad_name;
}

std::string Squad::GetLeague() const
{

    return league;
}

std::string Squad::GetManager() const
{
    return manager;
}



bool Squad::GetPlayers()
{

    std::vector<std::string> allPlayers;
    for(unsigned int i = 0; i < inField.size(); i++)
    {
        allPlayers.push_back(inField[i].name);
    }
    for(unsigned int i = 0; i < subs.size(); i++)
    {
        allPlayers.push_back(subs[i].name);
    }

    int pointer = -1;

    while(true)
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        std::cout << initUser.GetSquad() << " players" << "\n\n\n";
        std::cout << std::setw(30) << "Name :" << "\n\n\n";

        for(signed int i = 0; i < signed(allPlayers.size()); i++)
        {
            if (i == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << std::setw(30) << allPlayers[i] << '\n';
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << std::setw(30) << allPlayers[i] << '\n';
            }
        }
        while(true)
        {
            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = allPlayers.size()-1;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == signed(allPlayers.size()))
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                for(signed int i = 0; i < signed(allPlayers.size()); i++)
                {
                    if (pointer == i)
                    {
                        viewPlayer(allPlayers[i]);
                    }
                }
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                MainWindow goTo;
                return goTo.MainMenu();
            }
        }
        Sleep(150);
    }
}

bool Squad::viewPlayer(std::string &player)
{
    system("cls");
    for (unsigned int i = 0; i < inField.size(); i++)
    {
        if(player == inField[i].name || player == subs[i].name)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            std::cout << "Bio" << "\n\n";

            std::cout << std::setw(17) << "Name : " << " " << std::setw(22) << inField[i].name
                      << std::setw(30) << "Age : "   << " " << std::setw(22) << inField[i].age << '\n'
                      << std::setw(17) << "Nationality : " << " " << std::setw(22) << inField[i].nationality
                      << std::setw(30) << "Height : " << " " << std::setw(22) << inField[i].height << '\n'
                      << std::setw(17) << "Weight : " << " " << std::setw(22) << inField[i].weight
                      << std::setw(30) << "Number : " << " " << std::setw(22) << inField[i].number << '\n'
                      << std::setw(17) << "Position : " << " " << std::setw(22) << inField[i].position
                      << std::setw(30) << "Morale : " << " " << std::setw(22) << inField[i].morale << '\n'
                      << std::setw(17) << "Weight : " << " " << std::setw(22) << inField[i].weight
                      << std::setw(30) << "Number : " << " " << std::setw(22) << inField[i].number << '\n'
                      << std::setw(17) << "Value : " << " " << std::setw(22) << inField[i].value << "\n\n\n";


            std::cout << "Skills" << "\n\n";

            std::cout << std::setw(17) << "Pace : " << " " << std::setw(22) << inField[i].pace
                      << std::setw(30) << "Shooting : " << " " << std::setw(22) << inField[i].shooting << '\n'
                      << std::setw(17) << "Passing : " << " " << std::setw(22) << inField[i].dribbling
                      << std::setw(30) << "Dribbling : " << " " << std::setw(22) << inField[i].dribbling << '\n'
                      << std::setw(17) << "Defending : " << " " << std::setw(22) << inField[i].defending
                      << std::setw(30) << "Physical : " << " " << std::setw(22) << inField[i].physical << '\n'
                      << std::setw(17) << "Reflexes : " << " " << std::setw(22) << inField[i].reflexes
                      << std::setw(30) << "Diving : " << " " << std::setw(22) << inField[i].diving << '\n'
                      << std::setw(17) << "Handling : " << " " << std::setw(22) << inField[i].weight
                      << std::setw(30) << "Skill position : " << " " << std::setw(22) << inField[i].skill_position << '\n'
                      << std::setw(17) << "Overall points : " << " " << std::setw(22) << inField[i].overall_points << '\n';
        }
    }
    while(true)
    {
        if(GetAsyncKeyState(VK_BACK) != 0)
        {
            MainWindow goTo;
            return goTo.ViewSquad();
        }
    }
}
