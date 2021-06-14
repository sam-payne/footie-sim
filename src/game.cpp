#include "game.hpp"
#include <iostream>
#include <iomanip>

#define COMMENTS 0
using namespace std;

Game::Game(string home, int homerank, string away, int awayrank, bool enable_comments){
    game_active = true;
    home_team_name = home;
    away_team_name = away;
    home_team.ChangeName(home_team_name);
    away_team.ChangeName(away_team_name);
    home_team.GetPlayers(home_team_name);
    away_team.GetPlayers(away_team_name);
    time = 0;
    home_rankout10 = homerank;
    away_rankout10 = awayrank;
    comments = enable_comments;
    home_team.comments = enable_comments;
    away_team.comments = enable_comments;
}

int Game :: SimGame(){
    if (comments)
        cout << "Simulating " << home_team_name << " v " << away_team_name << "\n";
    
    ApplySkillMod(home_rankout10,away_rankout10); //Using rank differentials
    home_team.ModifyBaseline(1.2); //Home advantage
    while(game_active){
        Cycle();
    }
    return 0;
}

int Game :: Cycle(){
    home_team.VaryChanceOverTime(time);
    away_team.VaryChanceOverTime(time);

    
    if (comments){
        if (CalculateGoal())
            cout << " (" << time << "min)\n";
    }
    else
        CalculateGoal();
    

    IncrementTime();
}

void Game::IncrementTime(){
    if(time == 89)
        EndOfGame();
    else
        time++;
}

void Game::EndOfGame(){
    CalculatePoints();
    if(comments){    cout 
        << "Final Score:     " << home_team.GetName() << "   " << home_team.GetGoals() << "  -  " << away_team.GetGoals() << "   " << away_team.GetName(); 
        
    }
    game_active = false;
}

void Game::ApplySkillMod(int home_rank, int away_rank){
    int diff = home_rank - away_rank; //19 possible
    float mod = 0.1111111 * diff;
    // Here mod is between -1 and 1 depending on rank differential
    // Transform to between 0.5 and 2 (centrered about 1)
    // So the worst rank diff punishes by 1/2 scoing chance and the best increases 2x scoring chance
    
    if(mod <= 0){
        mod = mod*0.5 + 1;}
    else{
        mod = mod + 1;
    }
    home_team.ModifyBaseline(mod);
    // Now same for away (inverse diff)
    diff = -diff;
    mod = 0.1111111 * diff;
    if(mod <= 0){
        mod = mod*0.5 + 1;}
    else{
        mod = mod + 1;
    }
    away_team.ModifyBaseline(mod);

}

bool Game::CalculateGoal(){
    
    float rand_val = (double)rand() / (double)RAND_MAX;
    bool event = false;

    if(rand_val <= 0.0005556){
        home_team.RedCard();
        event = true;
    } 
    rand_val = (double)rand() / (double)RAND_MAX;    
    if (rand_val <= home_team.GetChance()){
        home_team.GoalScored();
        event = true;
    }
    
    rand_val = (double)rand() / (double)RAND_MAX;

    if(rand_val <= 0.0005556){
        away_team.RedCard();
        event = true;
    } 

    rand_val = (double)rand() / (double)RAND_MAX;
    if (rand_val <= away_team.GetChance()){
        away_team.GoalScored();
        event = true;
    }
return event;
}

void Game::CalculatePoints(){
    int homegoals = home_team.GetGoals();
    int awaygoals = away_team.GetGoals();
    home_team_points = 0;
    away_team_points = 0;
    if(homegoals > awaygoals)
        home_team_points = 3;
    else if (homegoals < awaygoals)
        away_team_points = 3;
    else{
        home_team_points = 1;
        away_team_points = 1;
    }
}