
#include <iostream>
#include <windows.h>
#include <string>

#include "gameFunc.h"

/**
*       User class definiton
*/
User::User()
{
}

std::string User::GetUsername() const
{
    return fullname;
}

void User::SetUserName(std::string &fn, std::string &ln)
{
    fullname = fn + " " + ln;
}

std::string User::GetCountry() const
{
    return country;
}

void User::SetCountry(std::string &setCountry)
{
    country = setCountry;
}

std::string User::GetLeague() const
{
    return league;
}

void User::SetLeague(std::string &setLeague)
{
    league = setLeague;
}

std::string User::GetSquad() const
{
    return squad;
}

void User::SetSquad(std::string &setSquad)
{
    squad = setSquad;
}

// deined user object
User initUser;
