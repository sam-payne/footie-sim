#include "game.hpp"

using namespace std;

Game::Game(string home, int homerank, string away, int awayrank){
    game_active = true;
    home_team_name = home;
    away_team_name = away;
    home_team.ChangeName(home_team_name);
    away_team.ChangeName(away_team_name);
    time = 0;
    home_rankout10 = homerank;
    away_rankout10 = awayrank;
}

int Game :: SimGame(){
    cout << "Simulating " << home_team_name << " v " << away_team_name << "\n";
    CalculateSkillMod(home_rankout10,away_rankout10);
    while(game_active){
        Cycle();
    }
    return 0;
}

int Game :: Cycle(){
    home_team.VaryChanceOverTime(time);
    away_team.VaryChanceOverTime(time);

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
    cout << "Final Score: " << home_team.GetName() << " " << home_team.GetGoals() << " || " << away_team.GetName() << " " << away_team.GetGoals() << "\n";
    game_active = false;
}

void Game::CalculateSkillMod(int home_rank, int away_rank){
    int diff = home_rank - away_rank; //19 possible
    float mod = 0.1111111 * diff;
    // Here mod between -1 and 1 depending on rank differential
    // Transform to between 0.333 and 3 (centrered about 1)
    // So the worst rank diff punishes by 1/3 scoing chance and the best increases 3x scoring chance
    if(mod <= 0){
        mod = mod*0.666666 + 1;}
    else{
        mod = 2*mod + 1;
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