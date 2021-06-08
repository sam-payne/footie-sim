#include "side.hpp"
using namespace std;


Side::Side(){
    baseline_chance = 0.015;
    name = "defaut_name";
    goals = 0;
}

void Side::VaryChanceOverTime(int t){
    double a = baseline_chance*0.9;
    double b = baseline_chance*1.1;
    double step = ((b-a)/90);
    scoring_chance = a + t*step;
}

bool Side::CalculateGoal(){
    
    float rand_val = (double)rand() / (double)RAND_MAX;

    if(rand_val <= 0.0005556)

     
    if (rand_val <= scoring_chance){
        GoalScored();
        return true;
    }
    else
        return false;
}

int Side::GoalScored(){
    goals++;
    cout << "GOAL to " << name << "  ";
}

void Side::RedCard(){
    red_cards++;
    //Reduce scoring chance by 0.8
    ModifyBaseline(0.7);
    cout << "RED CARD to " << name;
}