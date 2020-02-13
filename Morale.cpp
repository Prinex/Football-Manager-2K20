#include <iostream>
using namespace std;

//Class for Fan Morale and Team play
class FanMorale{
    protected: // Protected variables (for encapsulation) - NEED TO MAKE CALCULATED WHEN MATCH OPPORTUNITIES COMPLETE
        int fanMorale;
        int capacity;
        int weatherMult;
        int adMult;
        int leagueID;
        int attempts;
        int goals;
    
    public:
        void updateFanMorale(){
            fanMorale = (capacity / 1000) * (1 + adMult) * (weatherMult) + 100 * (leagueID + 1) + 10 * (attempts + goals);
        }
        int getFanMorale(){
            return fanMorale;
        }
}

class TeamPlay{
    protected:
    int teamPlay;
        int teamRating;
        int score;

    public:
        void updateTeamPlay(){
            teamPlay = (score)*100 + teamRating;
        }

        int getTeamPlay(){
            return teamPlay;
        }
}

// Morale class inherits Fan TeamPlay class
class Morale: public FanMorale, public TeamPlay{
    protected:
        int morale;
        
    public:
        void updateMorale(){
            updateFanMorale();
            updateTeamPlay();
            morale = (getTeamPlay() + getFanMorale()) / 2;

        }
        int getMorale(){
            return morale;
        }
}
