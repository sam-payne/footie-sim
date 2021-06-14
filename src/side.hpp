#ifndef __SIDE_HPP__
#define __SIDE_HPP__

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "player.hpp"
#include <time.h>
#include <iostream>

class Side {    
    public:        
        Side();
        std::vector <Player> VectorPlayers;
        float GetChance(){return scoring_chance;};
        int ModifyBaseline(float modifier){baseline_chance = baseline_chance * modifier;};
        std::string GetName(){return name;};
        int ChangeName(std::string new_name){name = new_name;};
        int GetGoals(){return goals;};
        int GoalScored();
        void RedCard();
        void VaryChanceOverTime(int t);
        void GetPlayers(std::string teamname);
        Player GetGoalscorer();
        bool comments;
    private:
        float scoring_chance;
        float baseline_chance;
        int red_cards;
        int player_mood;
        int goals;
        std::string name;
        
};

#endif