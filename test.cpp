#include <iostream>
using namespace std;


int main()
{
    const int SIZE = 8;
    string Options[SIZE] = {"UEFA", "Kick Off", "Transfers", "Buy Player", "Sell Player", "Squad", "View Squad", "Switch Players"};


    for(int i = 0; i < SIZE; i++)
    {
        cout << Options[i] << " ";
    }

    return 0;
}
