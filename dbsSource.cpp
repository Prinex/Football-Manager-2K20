#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <algorithm>
#include <vector>
#include "gameFunc.h"
#include "dbsSource.h"



/**
*       Players class defined
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
Squad::Squad(std::string squad_name, std::string league, std::string manager, std::vector<Players> &inField, std::vector<Players> &subs) :
    squad_name{squad_name},
    league{league},
    manager{manager},
    inField{inField},
    subs{subs}
{
}

Squad::Squad()
{}


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
    std::vector<Players> allPlayers;
    allPlayers.reserve(inField.size() + subs.size());

    std::copy(inField.begin(), inField.end(), std::back_inserter(allPlayers));
    std::copy(subs.begin(), subs.end(), std::back_inserter(allPlayers));


    int pointer = -1;

    while(true)
    {
        clrscr();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        std::cout << std::setw(30) << initUser->GetSquad() << " players" << "\n\n\n";
        std::cout << "Infield :" << "\n\n\n";

        for(std::vector<Players>::iterator it = allPlayers.begin(); it != allPlayers.end(); it = next(it))
        {
            if (std::distance(allPlayers.begin(), it) == 11)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << "\nSubstitutes :\n" << std::endl;
            }

            if (std::distance(allPlayers.begin(), it) == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << std::setw(30) << (*it).name << '\n';
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << std::setw(30) << (*it).name << '\n';
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

                if (pointer == allPlayers.size())
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                for(std::vector<Players>::iterator it = allPlayers.begin(); it != allPlayers.end(); it = std::next(it))
                {
                    if (pointer == std::distance(allPlayers.begin(), it))
                    {
                        viewPlayer((*it).name, allPlayers);
                    }
                }
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                return mainWin->MainMenu();
            }
        }
        Sleep(150);
    }
}

bool Squad::viewPlayer(const std::string &player, std::vector<Players> &dst)
{
    clrscr();
    for (std::vector<Players>::iterator it = dst.begin(); it != dst.end(); it = std::next(it))
    {
        if(player == (*it).name)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            std::cout << "Bio" << "\n\n";

            std::cout << std::setw(17) << "Name : " << " " << std::setw(22) << (*it).name
                      << std::setw(30) << "Age : "   << " " << std::setw(22) << (*it).age << '\n'
                      << std::setw(17) << "Nationality : " << " " << std::setw(22) << (*it).nationality
                      << std::setw(30) << "Height : " << " " << std::setw(22) << (*it).height << '\n'
                      << std::setw(17) << "Weight : " << " " << std::setw(22) << (*it).weight
                      << std::setw(30) << "Number : " << " " << std::setw(22) << (*it).number << '\n'
                      << std::setw(17) << "Position : " << " " << std::setw(22) << (*it).position
                      << std::setw(30) << "Morale : " << " " << std::setw(22) << (*it).morale << '\n'
                      << std::setw(17) << "Weight : " << " " << std::setw(22) << (*it).weight
                      << std::setw(30) << "Number : " << " " << std::setw(22) << (*it).number << '\n'
                      << std::setw(17) << "Value : " << " " << std::setw(22) << (*it).value << "\n\n\n";

            std::cout << "Skills" << "\n\n";

            std::cout << std::setw(17) << "Pace : " << " " << std::setw(22) << (*it).pace
                      << std::setw(30) << "Shooting : " << " " << std::setw(22) << (*it).shooting << '\n'
                      << std::setw(17) << "Passing : " << " " << std::setw(22) << (*it).dribbling
                      << std::setw(30) << "Dribbling : " << " " << std::setw(22) << (*it).dribbling << '\n'
                      << std::setw(17) << "Defending : " << " " << std::setw(22) << (*it).defending
                      << std::setw(30) << "Physical : " << " " << std::setw(22) << (*it).physical << '\n'
                      << std::setw(17) << "Reflexes : " << " " << std::setw(22) << (*it).reflexes
                      << std::setw(30) << "Diving : " << " " << std::setw(22) << (*it).diving << '\n'
                      << std::setw(17) << "Handling : " << " " << std::setw(22) << (*it).weight
                      << std::setw(30) << "Skill position : " << " " << std::setw(22) << (*it).skill_position << '\n'
                      << std::setw(17) << "Overall points : " << " " << std::setw(22) << (*it).overall_points << '\n';
        }
    }
    while(true)
    {
        if(GetAsyncKeyState(VK_BACK) != 0)
        {
            return mainWin->ViewSquad();
        }
    }
}

bool Squad::SelectInfield()
{
    int pointer = -1;

    while (true)
    {
        clrscr();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        std::cout << "Select infield player for switching : " << "\n\n\n";
        

        for (std::vector<Players>::iterator it = inField.begin(); it != inField.end(); it = next(it))
        {
            if (std::distance(inField.begin(), it) == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << std::setw(30) << (*it).name << '\n';
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << std::setw(30) << (*it).name << '\n';
            }
        }
        while (true)
        {

            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = inField.size() - 1;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == inField.size())
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                for (std::vector<Players>::iterator it = inField.begin(); it != inField.end(); it = std::next(it))
                {
                    if (pointer == std::distance(inField.begin(), it))
                    {
                        SelectSubs(std::distance(inField.begin(), it));
                    }
                }
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                return mainWin->MainMenu();
            }
        }
        Sleep(150);
    }
}

bool Squad::SelectSubs(int inFieldPlayerIdx)
{
    int pointer = -1;

    while (true)
    {
        clrscr();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        std::cout << "Select substitute player for switching : " << "\n\n\n";


        for (std::vector<Players>::iterator it = subs.begin(); it != subs.end(); it = next(it))
        {
            if (std::distance(subs.begin(), it) == pointer)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << std::setw(30) << (*it).name << '\n';
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << std::setw(30) << (*it).name << '\n';
            }
        }
        while (true)
        {

            if (GetAsyncKeyState(VK_UP) != 0 && pointer > -1)
            {
                pointer -= 1;
                if (pointer == -1)
                {
                    pointer = subs.size() - 1;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_DOWN) != 0)
            {
                pointer += 1;

                if (pointer == subs.size())
                {
                    pointer = 0;
                }
                break;
            }
            else if (GetAsyncKeyState(VK_RETURN) != 0)
            {
                int subPlayerIdx = 0;
                for (std::vector<Players>::iterator it = subs.begin(); it != subs.end(); it = std::next(it))
                {
                    if (pointer == std::distance(subs.begin(), it))
                    {
                        subPlayerIdx = std::distance(subs.begin(), it);
                        SwapPlayer(inFieldPlayerIdx, subPlayerIdx);
                    }
                }
            }
            else if (GetAsyncKeyState(VK_ESCAPE) != 0)
            {
                return mainWin->MainMenu();
            }
        }
        Sleep(150);
    }
}

bool Squad::SwapPlayer(int inFieldPlayerIdx, int subPlayerIdx)
{
    clrscr();

    std::swap(inField[inFieldPlayerIdx].name, subs[subPlayerIdx].name);
    std::swap(inField[inFieldPlayerIdx].age, subs[subPlayerIdx].age);
    std::swap(inField[inFieldPlayerIdx].nationality, subs[subPlayerIdx].nationality);
    std::swap(inField[inFieldPlayerIdx].height, subs[subPlayerIdx].height);
    std::swap(inField[inFieldPlayerIdx].weight, subs[subPlayerIdx].weight);
    std::swap(inField[inFieldPlayerIdx].number, subs[subPlayerIdx].number);
    std::swap(inField[inFieldPlayerIdx].position, subs[subPlayerIdx].position);
    std::swap(inField[inFieldPlayerIdx].morale, subs[subPlayerIdx].morale);
    std::swap(inField[inFieldPlayerIdx].value, subs[subPlayerIdx].value);
    std::swap(inField[inFieldPlayerIdx].pace, subs[subPlayerIdx].pace);
    std::swap(inField[inFieldPlayerIdx].shooting, subs[subPlayerIdx].shooting);
    std::swap(inField[inFieldPlayerIdx].passing, subs[subPlayerIdx].passing);
    std::swap(inField[inFieldPlayerIdx].dribbling, subs[subPlayerIdx].dribbling);
    std::swap(inField[inFieldPlayerIdx].defending, subs[subPlayerIdx].defending);
    std::swap(inField[inFieldPlayerIdx].physical, subs[subPlayerIdx].physical);
    std::swap(inField[inFieldPlayerIdx].reflexes, subs[subPlayerIdx].reflexes);
    std::swap(inField[inFieldPlayerIdx].diving, subs[subPlayerIdx].diving);
    std::swap(inField[inFieldPlayerIdx].handling, subs[subPlayerIdx].handling);
    std::swap(inField[inFieldPlayerIdx].skill_position, subs[subPlayerIdx].skill_position);
    std::swap(inField[inFieldPlayerIdx].overall_points, subs[subPlayerIdx].overall_points);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << inField[inFieldPlayerIdx].name << " has been switched with " << subs[subPlayerIdx].name << " successfully" << std::endl;

    while (true)
    {
        if (GetAsyncKeyState(VK_BACK) != 0)
        {
            return mainWin->SwitchPlayer();
        }
    }
}
