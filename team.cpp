#include "team.hpp"
using namespace std;


Team::Team(){
    scoring_chance = 0.015;
    name = "name_input";
}

bool Team::CalculateGoal(){
    
    float rand_val = (double)rand() / (double)RAND_MAX;
     
    if (rand_val <= scoring_chance){
        GoalScored();
        return true;
    }
    else
        return false;
}