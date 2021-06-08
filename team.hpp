#include <string>

class Team {
    public:
        Team(std::string name, int rank){team_name = name; ranking = rank; total_points=0; total_goals_for=0;total_goals_against=0;};
        int GetTotalPoints(){return total_points;};
        int GetGoalsFor(){return total_goals_for;};
        std::string GetName(){return team_name;};
        int GetGoalsAgainst(){return total_goals_against;};
        void AddPoints(int points){total_points += points;};
        void AddGoalsFor(int goals_for){total_goals_for += goals_for;};
        void AddGoalsAgainst(int goals_against){total_goals_against += goals_against;};
        int GetRank(){return ranking;};
        
    private:
        std::string team_name;
        int ranking;
        int total_points;
        int total_goals_for;
        int total_goals_against;
};