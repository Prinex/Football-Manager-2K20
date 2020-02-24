#ifndef DBS2_H_INCLUDED
#define DBS2_H_INCLUDED

#include "dbsSource.h"

/**
*       For printing squad objects
*/
std::ostream &operator<<(std::ostream &os, Squad const& squad)
{
    os << "Squad name: " << squad.squad_name << '\n'
       << "League: " << squad.league << '\n'
       << "Manager: " << squad.manager << '\n';

    return os;
}



/**
*       Manchester United
*       In this file we create the teams and players
*       Vincent here we've just created a 2 vectors like above (are similar to before): one is empty(which must be initialized with the second) and one contains the infield players
*       Create another empty vector (which I already did it for you) and a one with data filled in it
*       Now to initialize the vector go to main and do the exact same thing like there
*       Just follow my steps
*       And do this only here
*       And update the data
*/

// Step 1 to create a team;
Squad Manchester("Manchester United F.C.", "Premier League", "Ole Gunnar Solskjær", 11, 7);


// Step 2
std::vector<Players> InitManchesterInfield;
std::vector<Players> InitManchesterSubs;

// Step 3 then go to main
std::vector<Players> ManchesterInfield
{
    {"P.Aubameyang", 30, "Gabonese", 187, 80, 14, "LM", "GOOD", 57000000, 94, 85, 75, 80, 37, 88, 85, 75, 80, 37, 88 },
    {"A.Lacazette", 28, "French", 175, 73, 9, "ST", "GOOD",  46000000, 82, 85, 75, 86, 40, 86, 85, 75, 80, 37, 88 },
    {"B.Leno", 27, "German", 190, 83, 1, "GK", "GOOD", 26000000, 56, 78, 81, 84, 83, 84, 85, 75, 80, 37, 88 }, //Goalkeeper uses GK Speed, GK Kicking, GK Handling, GK Positioning and GK Diving: ATM (can change)
    {"Sokratis", 31, "Greek", 186, 85, 5, "RCB", "GOOD", 23000000, 72, 51, 52, 60, 84, 84, 85, 75, 80, 37, 88 },
    {"M.Ozil", 30, "German", 180, 76, 10, "CAM", "GOOD", 29500000, 70, 72, 86, 84, 24, 84, 85, 75, 80, 37, 88 },
    {"N.Pepe", 24, "Ivorian", 183, 73, 19, "RM", "GOOD", 34500000, 91, 81, 75, 85, 33, 83, 85, 75, 80, 37, 88 },
    {"David Luiz", 32, "Brazilian", 189, 86, 23, "LCB", "GOOD", 16500000, 61, 65, 74, 70, 82, 8, 85, 75, 80, 37, 883 },
    {"L.Torreira", 23, "Uruguayan", 168, 64, 11, "RDM", "GOOD", 27000000, 75, 67, 77, 80, 81, 82, 85, 75, 80, 37, 88 },
    {"G.Xhaka", 26, "Swiss", 185, 82, 34, "LDM", "GOOD", 21500000, 51, 67, 81, 71, 69, 81, 85, 75, 80, 37, 88},
    {"Nacho Monreal", 33, "Spanish", 180, 77, 18, "LB", "GOOD", 5500000, 63, 61, 71, 74, 80, 79, 85, 75, 80, 37, 88 },
    {"A.Maitland-Niles", 21, "British", 177, 71, 15, "RB", "GOOD", 9500000, 85, 59, 70, 76, 68, 75, 85, 75, 80, 37, 88}
};






#endif // DBS2_H_INCLUDED
