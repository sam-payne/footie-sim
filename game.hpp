#include "team.hpp"
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
        std::string home_team_name;
        std::string away_team_name;
        Team home_team;
        Team away_team;
        void EndOfGame();
        int time;
        void IncrementTime();
        void CalculateSkillMod(int home_rank, int away_rank); //Rank out of 10

};