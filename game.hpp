#include "team.hpp"
#include <iostream>
#include <string>

class Game {
    public: 
        
        Game(std::string home, std::string away);
        int Cycle();
        bool game_active;
    private:
        std::string home_team_name;
        std::string away_team_name;
        Team home_team;
        Team away_team;
        void EndOfGame();
        int time = 0;
        void IncrementTime();

};