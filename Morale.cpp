#include <iostream>
using namespace std;

//Class for Fan Morale and Team play
class FanTeamPlay{
    protected: // Protected variables (for encapsulation) - NEED TO MAKE CALCULATED WHEN MATCH OPPORTUNITIES COMPLETE
        int fanMorale;
        int capacity;
        int weatherMult;
        int adMult;
        int leagueID;
        int attempts;
        int goals;

        int teamPlay;
        int teamRating;
        int score;

    public:
        void updateFanMorale(){
            fanMorale = (capacity / 1000) * (1 + adMult) * (weatherMult) + 100 * (leagueID + 1) + 10 * (score + attempts)
        }
        int getFanMorale(){
            return fanMorale
        }

        void updateTeamPlay(){
            teamPlay = (goals - lossses) * 100 + teamRating
        }

        int getTeamPlay(){
            return teamPlay
        }

}
// Morale class inherits Fan TeamPlay class
class Morale: public FanTeamPlay{
    protected:
        int morale;
        
    public:
        void updateMorale(){
            updateFanMorale();
            updateTeamPlay();
            morale = (getTeamPlay + getFanMorale) / 2;

        }
        int getMorale(){
            return morale;
        }
}
