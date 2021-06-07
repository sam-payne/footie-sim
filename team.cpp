#include "team.hpp"
using namespace std;


Team::Team(){
    baseline_chance = 0.015;
    name = "defaut_name";
    goals = 0;
}

void Team::VaryChanceOverTime(int t){
    double a = baseline_chance*0.9;
    double b = baseline_chance*1.1;
    double step = ((b-a)/90);
    scoring_chance = a + t*step;
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