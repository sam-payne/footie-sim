#include "side.hpp"
using namespace std;
#define COMMENTS 0

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


int Side::GoalScored(){
    goals++;
    if(comments)
        cout << "GOAL to " << name << "  ";
    
}

void Side::RedCard(){
    red_cards++;
    //Reduce scoring chance by 0.8
    ModifyBaseline(0.7);
    if(comments)
        cout << "RED CARD to " << name;
    
}