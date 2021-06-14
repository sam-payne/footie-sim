#ifndef __TEAM_HPP__
#define __TEAM_HPP__

#include <string>

class Team {
    public:
        Team(std::string name, int rank);
        int GetTotalPoints(){return total_points;};
        int GetGoalsFor(){return total_goals_for;};
        std::string GetName(){return team_name;};
        void UpdateFinishingPlace(int place){finishing_place = place;};
        int GetFinishingPlace(){return finishing_place;};
        void UpdateRanking(int rank){ranking = rank;}
        int GetGoalsAgainst(){return total_goals_against;};
        void AddPoints(int points){total_points += points;};
        void AddGoalsFor(int goals_for){total_goals_for += goals_for;};
        void AddGoalsAgainst(int goals_against){total_goals_against += goals_against;};
        int GetRank(){return ranking;};
        int EndOfSeason();
        // Overload < operator for use in ranking teams
        friend bool operator<(const Team& lhs, const Team& rhs){
            if(lhs.total_points < rhs.total_points){
                return true;
            }
            if(lhs.total_points > rhs.total_points){
                return false;
            }
            if((lhs.total_goals_for - lhs.total_goals_against) < (rhs.total_goals_for - rhs.total_goals_against))
                return true;
            if((lhs.total_goals_for - lhs.total_goals_against) > (rhs.total_goals_for - rhs.total_goals_against))
                return false;
            if(lhs.total_goals_for < rhs.total_goals_for)
                return true;
            else
                return false;
        }
    private:
        std::string team_name;
        int ranking;
        int finishing_place;
        int total_points;
        int total_goals_for;
        int total_goals_against;
        int all_time_points;
        int best_finish;
        int worst_finish;
};

#endif