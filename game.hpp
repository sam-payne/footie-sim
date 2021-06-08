#include "side.hpp"
#include <iostream>
#include <string>

class Game {
    public:         
        Game(std::string home, int homerank, std::string away, int awayrank);
        int Cycle();
        bool game_active;
        int SimGame();
        int home_rankout10;
        int away_rankout10;
    private:
        void CalculatePoints();
        int GetHomePoints(){return home_team_points;};
        int GetAwayPoint(){return away_team_points;};
        std::string home_team_name;
        bool CalculateGoal();
        std::string away_team_name;
        Side home_team;
        Side away_team;
        int home_team_points;
        int away_team_points;
        void EndOfGame();
        int time;
        void IncrementTime();
        void CalculateSkillMod(int home_rank, int away_rank); //Rank out of 10

};