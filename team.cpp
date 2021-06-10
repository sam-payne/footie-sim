#include "team.hpp"

Team::Team(std::string name, int rank){
    team_name = name; 
    ranking = rank; 
    total_points=0; 
    total_goals_for=0;
    total_goals_against=0;
    finishing_place = 0;
}

int Team::EndOfSeason(){
    all_time_points += total_points;
    if(finishing_place < best_finish)
        best_finish = finishing_place;
    if(finishing_place > worst_finish)
        worst_finish = finishing_place;
    total_points = 0;
    total_goals_for = 0;
    total_goals_against = 0;
}