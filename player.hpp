#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include <vector>

class Player{
    public:
        Player(std::string n, float x){name = n; xG = x;}
        std::string name;
        float xG;

};



#endif