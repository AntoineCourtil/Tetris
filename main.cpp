#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, char* args[]) {
    Game game;
    game.init_sdl("Tetris", 480, 300, 32);
    while (game.running()) {
        game.handle_events();
        game.draw();
    }
    game.clean();
    return 0;
}
