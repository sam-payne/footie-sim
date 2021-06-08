#include "game.hpp"
#include "team.hpp"
#include "utils.hpp"
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;


int main (void){
    srand(time(NULL));
    vector<Team> TeamVector;
    TeamVector.push_back(Team("Man_C",10));
    TeamVector.push_back(Team("Man_U",9));
    TeamVector.push_back(Team("Liverpool",10));
    TeamVector.push_back(Team("Chelsea",9));
    TeamVector.push_back(Team("Leicester",8));
    TeamVector.push_back(Team("West_Ham",3));
    TeamVector.push_back(Team("Spurs",8));
    TeamVector.push_back(Team("Arsenal",7));
    TeamVector.push_back(Team("Leeds",2));
    TeamVector.push_back(Team("Everton",5));
    TeamVector.push_back(Team("Aston_Villa",2));
    TeamVector.push_back(Team("Newcastle",4));
    TeamVector.push_back(Team("Wolves",7));
    TeamVector.push_back(Team("Crystal_Palace",4));
    TeamVector.push_back(Team("Southampton",5));
    TeamVector.push_back(Team("Brighton",3));
    TeamVector.push_back(Team("Burnley",6));
    TeamVector.push_back(Team("Fulham",1));
    TeamVector.push_back(Team("West_Brom",2));
    TeamVector.push_back(Team("Sheffield",6));  
    

    int gamenumber =0;
    int homeid,awayid;
    for (gamenumber=0;gamenumber<380;gamenumber++){
        homeid = GetFixtures(gamenumber,0);
        awayid = GetFixtures(gamenumber,1);
        RunGame(TeamVector[homeid],TeamVector[awayid]);
    }
    PrintTable(TeamVector);
       
    return 0;  
    
}

