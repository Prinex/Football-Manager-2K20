
#include <iostream>
#include <windows.h>
#include <string>

#include "gameFunc.h"

/**
*       User class definiton
*/
User::User()
{}

void User::SetUsername(const std::string& fname, const std::string& lname)
{
    fullname = fname + " " + lname;
}

std::string User::GetUsername() const
{
    return fullname;
}


std::string User::GetCountry() const
{
    return country;
}

void User::SetCountry(const std::string &setCountry)
{
    country = setCountry;
}

std::string User::GetLeague() const
{
    return league;
}

void User::SetLeague(const std::string &setLeague)
{
    league = setLeague;
}

std::string User::GetSquad() const
{
    return squad;
}

void User::SetSquad(const std::string &setSquad)
{
    squad = setSquad;
}

// deined user objects 
std::shared_ptr<User> initUser = std::make_shared<User>();