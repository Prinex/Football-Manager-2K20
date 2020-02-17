#include <iostream>
#include <windows.h>
#include "gameFunc.h"
#include "dbsSource.h"
#include "dbsCreation.h"


using namespace std;

int main()
{
    /*
    GameWindow init;
    init.InitWindow();
    */

    Players::InitPlayers(LiverpoolSubs, InitLiverpoolSubs);
    Players::PrintPlayers(LiverpoolSubs);



    return 0;
}
