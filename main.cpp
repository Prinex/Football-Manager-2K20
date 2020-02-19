#include <iostream>
#include <windows.h>

#include "gameFunc.h"
#include "dbsSource.h"
#include "dbsCreation.h"






int main()
{
<<<<<<< HEAD

    GameWindow init;
    init.InitWindow();




=======
    /*
    GameWindow init;
    init.InitWindow();
    */

    Players::InitPlayers(LiverpoolSubs, InitLiverpoolSubs);
    Players::PrintPlayers(LiverpoolSubs);

>>>>>>> 61621e567c5dbc5ffbac9bb4008c6db8632d0af7


    return 0;
}
