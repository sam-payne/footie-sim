#include "game.hpp"
#include "team.hpp"
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
int RunGame(Team &home, Team &away);
int GetFixtures(int gamenumber,int homeaway);
void PrintTable(vector<Team> &data);

int main (void){
    srand(time(NULL));
    // Team Man_C("Man_C",10);
    // Team Man_U("Man_U",10);
    // Team Liverpool("Liverpool",10);
    // Team Chelsea("Chelsea",10);
    // Team Leicester("Leicester",10);
    // Team West_Ham("West_Ham",10);
    // Team Spurs("Spurs",10);
    // Team Arsenal("Arsenal",10);
    // Team Leeds("Leeds",10);
    // Team Everton("Everton",10);
    // Team Aston_Villa("Aston_Villa",10);
    // Team Newcastle("Newcastle",10);
    // Team Wolves("Wolves",10);
    // Team Crystal_Palace("Crystal_Palace",10);
    // Team Southampton("Southampton",10);
    // Team Brighton("Brighton",10);
    // Team Burnley("Burnley",10);
    // Team Fulham("Fulham",10);
    // Team West_Brom("West_Brom",10);
    // Team Sheffield("Sheffield",10);
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
    int home,away;
    for (gamenumber=0;gamenumber<380;gamenumber++){
        home = GetFixtures(gamenumber,0);
        away = GetFixtures(gamenumber,1);
        RunGame(TeamVector[home],TeamVector[away]);
    }
    PrintTable(TeamVector);
     
       
    
}

int RunGame(Team &home, Team &away){
    Game game(home.GetName(),home.GetRank(),away.GetName(),away.GetRank());
    game.SimGame();
    home.AddPoints(game.GetHomePoints());
    away.AddPoints(game.GetAwayPoint());
    home.AddGoalsFor(game.GetHomeGoals());
    home.AddGoalsAgainst(game.GetAwayGoals());
    away.AddGoalsFor(game.GetAwayGoals());
    away.AddGoalsAgainst(game.GetHomeGoals());
    return 0;
}

void PrintTable(vector<Team> &data){
    vector< pair <int,int> > vect;
    int i,teamid;
    for (i=0;i<20;i++){
        vect.push_back(make_pair(data[i].GetTotalPoints(),i));
    }
    sort(vect.begin(),vect.end());
    for(i=19;i>=0;i--){
        teamid = vect[i].second;
        cout << 20-i << " -> " << data[teamid].GetName() << " - Points: " << data[teamid].GetTotalPoints() << " - Goals for: " << data[teamid].GetGoalsFor() << " - Goals against: " << data[teamid].GetGoalsAgainst() << "\n";
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
// RunGame(Man_C,Sheffield);
    // RunGame(Man_U,West_Brom);
    // RunGame(Liverpool,Fulham);
    // RunGame(Chelsea,Burnley);
    // RunGame(Leicester,Brighton);
    // RunGame(West_Ham,Southampton);
    // RunGame(Spurs,Crystal_Palace);
    // RunGame(Arsenal,Wolves);
    // RunGame(Leeds,Newcastle);
    // RunGame(Sheffield,Man_C);
    // RunGame(West_Brom,Man_U);
    // RunGame(Fulham,Liverpool);
    // RunGame(Burnley,Chelsea);
    // RunGame(Brighton,Leicester);
    // RunGame(Southampton,West_Ham);
    // RunGame(Crystal_Palace,Spurs);
    // RunGame(Wolves,Arsenal);
    // RunGame(Newcastle,Leeds);
    // RunGame(Man_C,West_Brom);
    // RunGame(Sheffield,Fulham);
    // RunGame(Man_U,Burnley);
    // RunGame(Liverpool,Brighton);
    // RunGame(Chelsea,Southampton);
    // RunGame(Leicester,Crystal_Palace);
    // RunGame(West_Ham,Wolves);
    // RunGame(Spurs,Newcastle);
    // RunGame(Arsenal,Aston_Villa);
    // RunGame(West_Brom,Man_C);
    // RunGame(Fulham,Sheffield);
    // RunGame(Burnley,Man_U);
    // RunGame(Brighton,Liverpool);
    // RunGame(Southampton,Chelsea);
    // RunGame(Crystal_Palace,Leicester);
    // RunGame(Wolves,West_Ham);
    // RunGame(Newcastle,Spurs);
    // RunGame(Aston_Villa,Arsenal);
    // RunGame(Man_C,Fulham);
    // RunGame(West_Brom,Burnley);
    // RunGame(Sheffield,Brighton);
    // RunGame(Man_U,Southampton);
    // RunGame(Liverpool,Crystal_Palace);
    // RunGame(Chelsea,Wolves);
    // RunGame(Leicester,Newcastle);
    // RunGame(West_Ham,Aston_Villa);
    // RunGame(Spurs,Everton);
    // RunGame(Fulham,Man_C);
    // RunGame(Burnley,West_Brom);
    // RunGame(Brighton,Sheffield);
    // RunGame(Southampton,Man_U);
    // RunGame(Crystal_Palace,Liverpool);
    // RunGame(Wolves,Chelsea);
    // RunGame(Newcastle,Leicester);
    // RunGame(Aston_Villa,West_Ham);
    // RunGame(Everton,Spurs);
    // RunGame(Man_C,Burnley);
    // RunGame(Fulham,Brighton);
    // RunGame(West_Brom,Southampton);
    // RunGame(Sheffield,Crystal_Palace);
    // RunGame(Man_U,Wolves);
    // RunGame(Liverpool,Newcastle);
    // RunGame(Chelsea,Aston_Villa);
    // RunGame(Leicester,Everton);
    // RunGame(West_Ham,Leeds);
    // RunGame(Burnley,Man_C);
    // RunGame(Brighton,Fulham);
    // RunGame(Southampton,West_Brom);
    // RunGame(Crystal_Palace,Sheffield);
    // RunGame(Wolves,Man_U);
    // RunGame(Newcastle,Liverpool);
    // RunGame(Aston_Villa,Chelsea);
    // RunGame(Everton,Leicester);
    // RunGame(Leeds,West_Ham);
    // RunGame(Man_C,Brighton);
    // RunGame(Burnley,Southampton);
    // RunGame(Fulham,Crystal_Palace);
    // RunGame(West_Brom,Wolves);
    // RunGame(Sheffield,Newcastle);
    // RunGame(Man_U,Aston_Villa);
    // RunGame(Liverpool,Everton);
    // RunGame(Chelsea,Leeds);
    // RunGame(Leicester,Arsenal);
    // RunGame(Brighton,Man_C);
    // RunGame(Southampton,Burnley);
    // RunGame(Crystal_Palace,Fulham);
    // RunGame(Wolves,West_Brom);
    // RunGame(Newcastle,Sheffield);
    // RunGame(Aston_Villa,Man_U);
    // RunGame(Everton,Liverpool);
    // RunGame(Leeds,Chelsea);
    // RunGame(Arsenal,Leicester);
    // RunGame(Man_C,Man_U);
    // RunGame(Liverpool,Sheffield);
    // RunGame(Chelsea,West_Brom);
    // RunGame(Leicester,Fulham);
    // RunGame(West_Ham,Burnley);
    // RunGame(Spurs,Brighton);
    // RunGame(Arsenal,Southampton);
    // RunGame(Leeds,Crystal_Palace);
    // RunGame(Everton,Wolves);
    // RunGame(Man_C,Liverpool);
    // RunGame(Chelsea,Man_U);
    // RunGame(Leicester,Sheffield);
    // RunGame(West_Ham,West_Brom);
    // RunGame(Spurs,Fulham);
    // RunGame(Arsenal,Burnley);
    // RunGame(Leeds,Brighton);
    // RunGame(Everton,Southampton);
    // RunGame(Aston_Villa,Crystal_Palace);
    // RunGame(Man_C,Chelsea);
    // RunGame(Leicester,Liverpool);
    // RunGame(West_Ham,Man_U);
    // RunGame(Spurs,Sheffield);
    // RunGame(Arsenal,West_Brom);
    // RunGame(Leeds,Fulham);
    // RunGame(Everton,Burnley);
    // RunGame(Aston_Villa,Brighton);
    // RunGame(Newcastle,Southampton);
    // RunGame(Man_C,Leicester);
    // RunGame(West_Ham,Chelsea);
    // RunGame(Spurs,Liverpool);
    // RunGame(Arsenal,Man_U);
    // RunGame(Leeds,Sheffield);
    // RunGame(Everton,West_Brom);
    // RunGame(Aston_Villa,Fulham);
    // RunGame(Newcastle,Burnley);
    // RunGame(Wolves,Brighton);
    // RunGame(Man_C,West_Ham);
    // RunGame(Spurs,Leicester);
    // RunGame(Arsenal,Chelsea);
    // RunGame(Leeds,Liverpool);
    // RunGame(Everton,Man_U);
    // RunGame(Aston_Villa,Sheffield);
    // RunGame(Newcastle,West_Brom);
    // RunGame(Wolves,Fulham);
    // RunGame(Crystal_Palace,Burnley);
    // RunGame(Man_C,Spurs);
    // RunGame(Arsenal,West_Ham);
    // RunGame(Leeds,Leicester);
    // RunGame(Everton,Chelsea);
    // RunGame(Aston_Villa,Liverpool);
    // RunGame(Newcastle,Man_U);
    // RunGame(Wolves,Sheffield);
    // RunGame(Crystal_Palace,West_Brom);
    // RunGame(Southampton,Fulham);
    // RunGame(Man_C,Arsenal);
    // RunGame(Leeds,Spurs);
    // RunGame(Everton,West_Ham);
    // RunGame(Aston_Villa,Leicester);
    // RunGame(Newcastle,Chelsea);
    // RunGame(Wolves,Liverpool);
    // RunGame(Crystal_Palace,Man_U);
    // RunGame(Southampton,Sheffield);
    // RunGame(Brighton,West_Brom);
    // RunGame(Man_C,Leeds);
    // RunGame(Everton,Arsenal);
    // RunGame(Aston_Villa,Spurs);
    // RunGame(Newcastle,West_Ham);
    // RunGame(Wolves,Leicester);
    // RunGame(Crystal_Palace,Chelsea);
    // RunGame(Southampton,Liverpool);
    // RunGame(Brighton,Man_U);
    // RunGame(Burnley,Sheffield);
    // RunGame(Man_C,Everton);
    // RunGame(Aston_Villa,Leeds);
    // RunGame(Newcastle,Arsenal);
    // RunGame(Wolves,Spurs);
    // RunGame(Crystal_Palace,West_Ham);
    // RunGame(Southampton,Leicester);
    // RunGame(Brighton,Chelsea);
    // RunGame(Burnley,Liverpool);
    // RunGame(Fulham,Man_U);
    // RunGame(Man_C,Aston_Villa);
    // RunGame(Newcastle,Everton);
    // RunGame(Wolves,Leeds);
    // RunGame(Crystal_Palace,Arsenal);
    // RunGame(Southampton,Spurs);
    // RunGame(Brighton,West_Ham);
    // RunGame(Burnley,Leicester);
    // RunGame(Fulham,Chelsea);
    // RunGame(West_Brom,Liverpool);
    // RunGame(Man_C,Newcastle);
    // RunGame(Wolves,Aston_Villa);
    // RunGame(Crystal_Palace,Everton);
    // RunGame(Southampton,Leeds);
    // RunGame(Brighton,Arsenal);
    // RunGame(Burnley,Spurs);
    // RunGame(Fulham,West_Ham);
    // RunGame(West_Brom,Leicester);
    // RunGame(Sheffield,Chelsea);
    // RunGame(Man_C,Wolves);
    // RunGame(Crystal_Palace,Newcastle);
    // RunGame(Southampton,Aston_Villa);
    // RunGame(Brighton,Everton);
    // RunGame(Burnley,Leeds);
    // RunGame(Fulham,Arsenal);
    // RunGame(West_Brom,Spurs);
    // RunGame(Sheffield,West_Ham);
    // RunGame(Man_U,Leicester);
    // RunGame(Man_C,Crystal_Palace);
    // RunGame(Southampton,Wolves);
    // RunGame(Brighton,Newcastle);
    // RunGame(Burnley,Aston_Villa);
    // RunGame(Fulham,Everton);
    // RunGame(West_Brom,Leeds);
    // RunGame(Sheffield,Arsenal);
    // RunGame(Man_U,Spurs);
    // RunGame(Liverpool,West_Ham);
    // RunGame(Man_C,Southampton);
    // RunGame(Brighton,Crystal_Palace);
    // RunGame(Burnley,Wolves);
    // RunGame(Fulham,Newcastle);
    // RunGame(West_Brom,Aston_Villa);
    // RunGame(Sheffield,Everton);
    // RunGame(Man_U,Leeds);
    // RunGame(Liverpool,Arsenal);
    // RunGame(Chelsea,Spurs);
    // RunGame(Southampton,Man_C);
    // RunGame(Crystal_Palace,Brighton);
    // RunGame(Wolves,Burnley);
    // RunGame(Newcastle,Fulham);
    // RunGame(Aston_Villa,West_Brom);
    // RunGame(Everton,Sheffield);
    // RunGame(Leeds,Man_U);
    // RunGame(Arsenal,Liverpool);
    // RunGame(Spurs,Chelsea);
    // RunGame(Crystal_Palace,Man_C);
    // RunGame(Wolves,Southampton);
    // RunGame(Newcastle,Brighton);
    // RunGame(Aston_Villa,Burnley);
    // RunGame(Everton,Fulham);
    // RunGame(Leeds,West_Brom);
    // RunGame(Arsenal,Sheffield);
    // RunGame(Spurs,Man_U);
    // RunGame(West_Ham,Liverpool);
    // RunGame(Wolves,Man_C);
    // RunGame(Newcastle,Crystal_Palace);
    // RunGame(Aston_Villa,Southampton);
    // RunGame(Everton,Brighton);
    // RunGame(Leeds,Burnley);
    // RunGame(Arsenal,Fulham);
    // RunGame(Spurs,West_Brom);
    // RunGame(West_Ham,Sheffield);
    // RunGame(Leicester,Man_U);
    // RunGame(Newcastle,Man_C);
    // RunGame(Aston_Villa,Wolves);
    // RunGame(Everton,Crystal_Palace);
    // RunGame(Leeds,Southampton);
    // RunGame(Arsenal,Brighton);
    // RunGame(Spurs,Burnley);
    // RunGame(West_Ham,Fulham);
    // RunGame(Leicester,West_Brom);
    // RunGame(Chelsea,Sheffield);
    // RunGame(Aston_Villa,Man_C);
    // RunGame(Everton,Newcastle);
    // RunGame(Leeds,Wolves);
    // RunGame(Arsenal,Crystal_Palace);
    // RunGame(Spurs,Southampton);
    // RunGame(West_Ham,Brighton);
    // RunGame(Leicester,Burnley);
    // RunGame(Chelsea,Fulham);
    // RunGame(Liverpool,West_Brom);
    // RunGame(Everton,Man_C);
    // RunGame(Leeds,Aston_Villa);
    // RunGame(Arsenal,Newcastle);
    // RunGame(Spurs,Wolves);
    // RunGame(West_Ham,Crystal_Palace);
    // RunGame(Leicester,Southampton);
    // RunGame(Chelsea,Brighton);
    // RunGame(Liverpool,Burnley);
    // RunGame(Man_U,Fulham);
    // RunGame(Leeds,Man_C);
    // RunGame(Arsenal,Everton);
    // RunGame(Spurs,Aston_Villa);
    // RunGame(West_Ham,Newcastle);
    // RunGame(Leicester,Wolves);
    // RunGame(Chelsea,Crystal_Palace);
    // RunGame(Liverpool,Southampton);
    // RunGame(Man_U,Brighton);
    // RunGame(Sheffield,Burnley);
    // RunGame(Arsenal,Man_C);
    // RunGame(Spurs,Leeds);
    // RunGame(West_Ham,Everton);
    // RunGame(Leicester,Aston_Villa);
    // RunGame(Chelsea,Newcastle);
    // RunGame(Liverpool,Wolves);
    // RunGame(Man_U,Crystal_Palace);
    // RunGame(Sheffield,Southampton);
    // RunGame(West_Brom,Brighton);
    // RunGame(Spurs,Man_C);
    // RunGame(West_Ham,Arsenal);
    // RunGame(Leicester,Leeds);
    // RunGame(Chelsea,Everton);
    // RunGame(Liverpool,Aston_Villa);
    // RunGame(Man_U,Newcastle);
    // RunGame(Sheffield,Wolves);
    // RunGame(West_Brom,Crystal_Palace);
    // RunGame(Fulham,Southampton);
    // RunGame(West_Ham,Man_C);
    // RunGame(Leicester,Spurs);
    // RunGame(Chelsea,Arsenal);
    // RunGame(Liverpool,Leeds);
    // RunGame(Man_U,Everton);
    // RunGame(Sheffield,Aston_Villa);
    // RunGame(West_Brom,Newcastle);
    // RunGame(Fulham,Wolves);
    // RunGame(Burnley,Crystal_Palace);
    // RunGame(Leicester,Man_C);
    // RunGame(Chelsea,West_Ham);
    // RunGame(Liverpool,Spurs);
    // RunGame(Man_U,Arsenal);
    // RunGame(Sheffield,Leeds);
    // RunGame(West_Brom,Everton);
    // RunGame(Fulham,Aston_Villa);
    // RunGame(Burnley,Newcastle);
    // RunGame(Brighton,Wolves);
    // RunGame(Chelsea,Man_C);
    // RunGame(Liverpool,Leicester);
    // RunGame(Man_U,West_Ham);
    // RunGame(Sheffield,Spurs);
    // RunGame(West_Brom,Arsenal);
    // RunGame(Fulham,Leeds);
    // RunGame(Burnley,Everton);
    // RunGame(Brighton,Aston_Villa);
    // RunGame(Southampton,Newcastle);
    // RunGame(Liverpool,Man_C);
    // RunGame(Man_U,Chelsea);
    // RunGame(Sheffield,Leicester);
    // RunGame(West_Brom,West_Ham);
    // RunGame(Fulham,Spurs);
    // RunGame(Burnley,Arsenal);
    // RunGame(Brighton,Leeds);
    // RunGame(Southampton,Everton);
    // RunGame(Crystal_Palace,Aston_Villa);
