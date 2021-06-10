#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include "game.hpp"
#include "team.hpp"
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

// Utils.hpp
void PrintTable(vector<Team> &data);
vector<Team> SortTable(vector<Team> &data);
int RunGameOfSeason(Team &home, Team &away);
int RunSeason(vector<Team> &teams);
int GetFixtures(int gamenumber,int homeaway);
int RunGame(Team home,Team away);
int ShowHelp();
int RankingsFromFinishingPlace(vector<Team> &sorted,vector<Team> &original);
void EndOfSeason(vector<Team> &teams);

void PrintTable(vector<Team> &data){
    
    int i,teamid,goalsfor,goalsag,goalsdiff;
    cout << "League Table: \n";
    
    cout
        << left
        << setw(5)
        << "   "
        << left
        << setw(15)
        << "Team"
        << right
        << setw(8)
        << "Points"
        << right
        << setw(8)
        << "GF"
        << right
        << setw(8)
        << "GA"
        << right
        << setw(8)
        << "GD"
        << right
        << setw(10)
        << "Prev Finish"
        << endl;

    for(i=0;i<20;i++){
        
        goalsfor = data[i].GetGoalsFor();
        goalsag = data[i].GetGoalsAgainst();
        goalsdiff = goalsfor - goalsag;
        cout 
            << left
            << setw(5)
            << i+1
            << left
            << setw(15)
            << data[i].GetName() 
            << right
            << setw(8)
            << data[i].GetTotalPoints() 
            << right 
            << setw(8)
            << goalsfor 
            << right
            << setw(8)
            << goalsag 
            << right
            << setw(8) 
            << goalsdiff 
            << right
            << setw(8) 
            << data[i].GetFinishingPlace()            
            << endl;
    }
}

vector<Team> SortTable(vector<Team> &data){
    sort(data.begin(),data.end());
    reverse(data.begin(),data.end());
    return data;
}

int RunGameOfSeason(Team &home, Team &away){
    Game game(home.GetName(),home.GetRank(),away.GetName(),away.GetRank(),false);
    game.SimGame();
    home.AddPoints(game.GetHomePoints());
    away.AddPoints(game.GetAwayPoint());
    home.AddGoalsFor(game.GetHomeGoals());
    home.AddGoalsAgainst(game.GetAwayGoals());
    away.AddGoalsFor(game.GetAwayGoals());
    away.AddGoalsAgainst(game.GetHomeGoals());
    return 0;
}

int HowManyToWin(string team){
    int gamenumber =0, counter=1;
    int homeid,awayid;
    vector<Team> TeamVector, SortedVector, NewVector;
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
    
    while(1){
        NewVector = TeamVector;
        for (gamenumber=0;gamenumber<380;gamenumber++){
            
            homeid = GetFixtures(gamenumber,0);
            awayid = GetFixtures(gamenumber,1);
            RunGameOfSeason(NewVector[homeid],NewVector[awayid]);
        }

        SortedVector = SortTable(NewVector);
        if(SortedVector[0].GetName() == team)
            break;
        counter++;
    }
    cout << "It took " << counter << " number of seasons for " << team << " to win the league.";
}

int RunGame(string homename, int homerank, string awayname, int awayrank){
    Game game(homename,homerank,awayname,awayrank,true);
    game.SimGame();
    
    return 0;
}

vector<Team> RunSeason(){
    int gamenumber =0;
    int homeid,awayid;
    vector<Team> TeamVector, SortedVector;
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

    int year = 2020;
    while(1){
        cout << "\n\n(" << year << "/" << (year+1)%100 << ") Season ";
        year++;
        for (gamenumber=0;gamenumber<380;gamenumber++){
            homeid = GetFixtures(gamenumber,0);
            awayid = GetFixtures(gamenumber,1);
            RunGameOfSeason(TeamVector[homeid],TeamVector[awayid]);
        }

        SortedVector = SortTable(TeamVector);
        
        PrintTable(SortedVector);

        RankingsFromFinishingPlace(SortedVector,TeamVector);
        EndOfSeason(TeamVector);
        
        cout << "\nAgain? Hit enter, or CTRL-C to escape\n";
        getchar();
    }
}

void EndOfSeason(vector<Team> &teams){
    int i;
    for(i=0;i<teams.size();i++)
        teams[i].EndOfSeason();
}

int RankingsFromFinishingPlace(vector<Team> &sorted,vector<Team> &original){
    int i,j,rank,val;
    for(i=0;i<20;i++){
        val = 20-i;
        rank = val/2 + 1;
        if(rank>10) rank=10;
        for(j=0;j<20;j++){
            if(original[j].GetName() == sorted[i].GetName()){
                original[j].UpdateFinishingPlace(j+1);
                original[j].UpdateRanking(rank);
            }
        }
    }

}

int GetFixtures(int gamenumber,int homeaway){
    static const int fixtures[380][2] = 
    {{0,19},
{1,18},
{2,17},
{3,16},
{4,15},
{5,14},
{6,13},
{7,12},
{8,11},
{9,10},
{19,0},
{18,1},
{17,2},
{16,3},
{15,4},
{14,5},
{13,6},
{12,7},
{11,8},
{10,9},
{0,18},
{19,17},
{1,16},
{2,15},
{3,14},
{4,13},
{5,12},
{6,11},
{7,10},
{8,9},
{18,0},
{17,19},
{16,1},
{15,2},
{14,3},
{13,4},
{12,5},
{11,6},
{10,7},
{9,8},
{0,17},
{18,16},
{19,15},
{1,14},
{2,13},
{3,12},
{4,11},
{5,10},
{6,9},
{7,8},
{17,0},
{16,18},
{15,19},
{14,1},
{13,2},
{12,3},
{11,4},
{10,5},
{9,6},
{8,7},
{0,16},
{17,15},
{18,14},
{19,13},
{1,12},
{2,11},
{3,10},
{4,9},
{5,8},
{6,7},
{16,0},
{15,17},
{14,18},
{13,19},
{12,1},
{11,2},
{10,3},
{9,4},
{8,5},
{7,6},
{0,15},
{16,14},
{17,13},
{18,12},
{19,11},
{1,10},
{2,9},
{3,8},
{4,7},
{5,6},
{15,0},
{14,16},
{13,17},
{12,18},
{11,19},
{10,1},
{9,2},
{8,3},
{7,4},
{6,5},
{0,1},
{2,19},
{3,18},
{4,17},
{5,16},
{6,15},
{7,14},
{8,13},
{9,12},
{10,11},
{0,2},
{3,1},
{4,19},
{5,18},
{6,17},
{7,16},
{8,15},
{9,14},
{10,13},
{11,12},
{0,3},
{4,2},
{5,1},
{6,19},
{7,18},
{8,17},
{9,16},
{10,15},
{11,14},
{12,13},
{0,4},
{5,3},
{6,2},
{7,1},
{8,19},
{9,18},
{10,17},
{11,16},
{12,15},
{13,14},
{0,5},
{6,4},
{7,3},
{8,2},
{9,1},
{10,19},
{11,18},
{12,17},
{13,16},
{14,15},
{0,6},
{7,5},
{8,4},
{9,3},
{10,2},
{11,1},
{12,19},
{13,18},
{14,17},
{15,16},
{0,7},
{8,6},
{9,5},
{10,4},
{11,3},
{12,2},
{13,1},
{14,19},
{15,18},
{16,17},
{0,8},
{9,7},
{10,6},
{11,5},
{12,4},
{13,3},
{14,2},
{15,1},
{16,19},
{17,18},
{0,9},
{10,8},
{11,7},
{12,6},
{13,5},
{14,4},
{15,3},
{16,2},
{17,1},
{18,19},
{0,10},
{11,9},
{12,8},
{13,7},
{14,6},
{15,5},
{16,4},
{17,3},
{18,2},
{19,1},
{0,11},
{12,10},
{13,9},
{14,8},
{15,7},
{16,6},
{17,5},
{18,4},
{19,3},
{1,2},
{0,12},
{13,11},
{14,10},
{15,9},
{16,8},
{17,7},
{18,6},
{19,5},
{1,4},
{2,3},
{0,13},
{14,12},
{15,11},
{16,10},
{17,9},
{18,8},
{19,7},
{1,6},
{2,5},
{3,4},
{0,14},
{15,13},
{16,12},
{17,11},
{18,10},
{19,9},
{1,8},
{2,7},
{3,6},
{4,5},
{14,0},
{13,15},
{12,16},
{11,17},
{10,18},
{9,19},
{8,1},
{7,2},
{6,3},
{5,4},
{13,0},
{12,14},
{11,15},
{10,16},
{9,17},
{8,18},
{7,19},
{6,1},
{5,2},
{4,3},
{12,0},
{11,13},
{10,14},
{9,15},
{8,16},
{7,17},
{6,18},
{5,19},
{4,1},
{3,2},
{11,0},
{10,12},
{9,13},
{8,14},
{7,15},
{6,16},
{5,17},
{4,18},
{3,19},
{2,1},
{10,0},
{9,11},
{8,12},
{7,13},
{6,14},
{5,15},
{4,16},
{3,17},
{2,18},
{1,19},
{9,0},
{8,10},
{7,11},
{6,12},
{5,13},
{4,14},
{3,15},
{2,16},
{1,17},
{19,18},
{8,0},
{7,9},
{6,10},
{5,11},
{4,12},
{3,13},
{2,14},
{1,15},
{19,16},
{18,17},
{7,0},
{6,8},
{5,9},
{4,10},
{3,11},
{2,12},
{1,13},
{19,14},
{18,15},
{17,16},
{6,0},
{5,7},
{4,8},
{3,9},
{2,10},
{1,11},
{19,12},
{18,13},
{17,14},
{16,15},
{5,0},
{4,6},
{3,7},
{2,8},
{1,9},
{19,10},
{18,11},
{17,12},
{16,13},
{15,14},
{4,0},
{3,5},
{2,6},
{1,7},
{19,8},
{18,9},
{17,10},
{16,11},
{15,12},
{14,13},
{3,0},
{2,4},
{1,5},
{19,6},
{18,7},
{17,8},
{16,9},
{15,10},
{14,11},
{13,12},
{2,0},
{1,3},
{19,4},
{18,5},
{17,6},
{16,7},
{15,8},
{14,9},
{13,10},
{12,11},
{1,0},
{19,2},
{18,3},
{17,4},
{16,5},
{15,6},
{14,7},
{13,8},
{12,9},
{11,10}};
return fixtures[gamenumber][homeaway];
}

int ShowHelp(){
    cout << 
    "'Footie-sim' by Sam Payne (github.com/sam-payne/footie-sim)\n"
<< "\n"
<<"Minute-by-minute football simulator for games and entire seasons\n"
<<"\n\n"
<< "Game class:\n"
<<"A Game object represents a single match, between two 'Side' objects\n"
<<"\n\n"
<<"Side class:\n"
<<"A class to represent a side of 11 player playing at one specific game. Used to track changes goal scoring chance over time. Not to be confused with Team class\n"
<<"\n\n"
<<"Team class:\n"
<<"Hold info about a team's performance over multiple games (season). \n"
<<"Includes total points, goals for/against etc. Each team has a rank out of 10 (1-10). \n"
<<"This rank is relative, and used to identify better teams against poorer teams. \n"
<<"In a league, the best teams shoud be set to 10 and the worst to 1. \n"
<<"The rank differential between two opposition is used to modify the baseline scoring chance per minute of each team.\n"
<<"\n\n"
<<"League:\n"
<<"Currently the teams in the Premier League 2020/21 season are held in a vector of Teams.\n"
<<"A pregenerated fixture list is used to simulate a total of 380 games. A league table can then be printed.\n"
<<"\n\n"
<<"Usage:\n"
<<"To compile and link:\n"
<<"\n"
<<"> make\n"
<<"\n"
<<"To sim a whole season:\n"
<<"\n"
<<"> sim season\n"
<<"\n"
<<"To sim a game between two teams with relative ranks:\n"
<<"\n"
<<"> sim Burnley 10 Chelsea 6\n"
<<"\n"
<<"To return the number of seasons simulated before a certain team wins the league:\n"
<<"\n"
<<"> sim howmany Burnley\n"
<<"\n"
<<"To display help:\n"
<<"\n"
<<"> sim help\n\n";

}

#endif