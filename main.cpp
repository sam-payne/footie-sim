#include "game.hpp"
#include <time.h>
#include <stdlib.h>

int main (void){
    srand(time(NULL));
    Game game("Burnley","Wigan");
    while(game.game_active){
        game.Cycle();
    }
}