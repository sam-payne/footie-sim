#include "game.hpp"
#include <time.h>
#include <stdlib.h>

int main (void){
    srand(time(NULL));
    Game game("Burnley",10,"Blackburn",5);
    game.SimGame();
    
}

//int GetStats()