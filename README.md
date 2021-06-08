# Footie-sim
Minute-by-minute football simulator for games and entire seasons

### Game class
A Game object represents a single match, between two 'Side' objects

### Side class
A class to represent a side of 11 player playing at one specific game. Used to track changes goal scoring chance over time. Not to be confused with Team class

### Team class
Hold info about a team's performance over multiple games (season). Includes total points, goals for/against etc. Each team has a rank out of 10 (1-10). This rank is relative, and used to identify better teams against poorer teams. In a league, the best teams shoud be set to 10 and the worst to 1. The rank differential between two opposition is used to modify the baseline scoring chance per minute of each team.

### League
Currently the teams in the Premier League 2020/21 season are held in a vector of Teams. A pregenerated fixture list is used to simulate a total of 380 games. A league table can then be printed.


## Compile
> g++ main.cpp game.cpp side.cpp -o sim
