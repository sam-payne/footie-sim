#include "game.hpp"
#include "team.hpp"
#include "utils.hpp"
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main (int argc, char* argv[]){
    srand(time(NULL));
    if (argc == 2){
        string in = argv[1];
        if(in == "season")
            RunSeason();
    } else if (argc == 5){
        RunGame(argv[1],atoi(argv[2]),argv[3],atoi(argv[4]));
    }
    else{
        cerr << "Enter either 'sim season' or 'sim [TEAM] [RANK] [TEAM] [RANK]'";
        return 1;
    }
    return 0;

    
    // vector<Team> SortedTeams, FreshTeams, Result;
    // while(1){
        
    //     Result = RunSeason();
    //     SortedTeams = SortTable(Result);
        
    //     if(SortedTeams[0].GetName() == "Burnley")
    //         break;
    //     counter++;    
        
    // }
    // cout << counter;
    
    
}

