#include <iostream>
#include "include/game.h"
#include "include/formes.h"
#include "include/informations.h"


using namespace std;

int main(int argc, char* args[]) {
    Game game;
    game.init_sdl("Tetris", 500, 500, 32);
    game.currentPiece=false;

    while (game.running()) {
        game.handle_events();
        game.draw();
    }
    game.clean();
    return 0;
}
