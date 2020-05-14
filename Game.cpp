#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>



#include "gameFunc.h"



/**
*       Game class defined
*/
Game::Game()
{
    time1 = 0;
    time2 = 0;
    your_score = 0;
    opponent_score = 0;
    total_time = 0;
    status = GameStatus::NONE;
}

void Game::Run()
{
    gameWin->InitWindow();
}

int Game::GetTime1() const
{
    return time1;
}

void Game::SetTime2(int setTime2)
{
    time2 = setTime2;
}

int Game::GetTime2() const
{
    return time2;
}

void Game::SetTotalTime(int setTotalTime)
{
    total_time = setTotalTime;
}

int Game::GetTotalTime() const
{
    return total_time;
}

int Game::GetYourScore() const
{
    return your_score;
}

void Game::SetYourScore(int setYourScore)
{
    your_score = setYourScore;
}

int Game::GetOpponentScore() const
{
    return opponent_score;
}

void Game::SetOpponentScore(int setOpponentScore)
{
    opponent_score = setOpponentScore;
}

GameStatus Game::GetStatus() const
{
    return status;
}

void Game::SetStatus(GameStatus  setStatus)
{
    status = setStatus;
}

std::shared_ptr<Game> game = std::make_shared<Game>();


