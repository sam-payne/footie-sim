#include "game.hpp"

using namespace std;

Game::Game(string home, string away){
    game_active = true;
    home_team_name = home;
    away_team_name = away;
    home_team.ChangeName(home_team_name);
    away_team.ChangeName(away_team_name);
}

int Game :: Cycle(){
    
    if (home_team.CalculateGoal()){
        cout << "Time: '" << time << " -->  ";
        cout << "Goal to " << home_team.GetName() << "\n";
    }
    if (away_team.CalculateGoal()){
        cout << "Time: '" << time << " -->  ";
        cout << "Goal to " << away_team.GetName() << "\n";
    }

    IncrementTime();
}

void Game::IncrementTime(){
    if(time == 89)
        EndOfGame();
    else
        time++;
}

void Game::EndOfGame(){
    cout << "Final Score --> " << home_team.GetName() << " " << home_team.GetGoals() << " || " << away_team.GetName() << " " << away_team.GetGoals() << "\n";
    
    game_active = false;
}