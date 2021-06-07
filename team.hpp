#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

class Team {
    public:
        
        Team();
        float GetChance(){return scoring_chance;};
        int ModifyBaseline(float modifier){baseline_chance = baseline_chance * modifier;};
        std::string GetName(){return name;};
        int ChangeName(std::string new_name){name = new_name;};
        int GetGoals(){return goals;};
        int GoalScored(){goals++;};
        bool CalculateGoal();
        void VaryChanceOverTime(int t);
    private:
        float scoring_chance;
        float baseline_chance;
        int players;
        int player_mood;
        int goals;
        std::string name;
};