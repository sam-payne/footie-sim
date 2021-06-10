#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "side.hpp"
#include <iostream>
#include <string>

class Game {
    public:         
        Game(std::string home, int homerank, std::string away, int awayrank,bool enable_comments);
        int Cycle();
        bool game_active;
        int SimGame();
        int home_rankout10;
        int away_rankout10;
        int GetHomePoints(){return home_team_points;};
        int GetAwayPoint(){return away_team_points;};
        int GetHomeGoals(){return home_team.GetGoals();};
        int GetAwayGoals(){return away_team.GetGoals();};
     
    private:
        void CalculatePoints();        
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
        void ApplySkillMod(int home_rank, int away_rank); //Rank out of 10
        bool comments;

};

#endif