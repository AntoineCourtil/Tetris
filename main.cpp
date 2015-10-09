#include <iostream>
#include "include/game.h"
#include "include/formes.h"


using namespace std;

int main(int argc, char* args[]) {
    Game game;
    game.init_sdl("Tetris", 250, 500, 32);
    game.currentPiece=false;

    while (game.running()) {
        game.handle_events();
        game.draw();
    }
    game.clean();
    return 0;
}
