#ifndef _GAME_H_
#define _GAME_H_

#include <SDL/SDL.h>
#include "Tableau.h"
#include "../include/formes.h"

class Game {
public:
    Game();
    bool init_sdl(const char* title, int width, int height, int bpp);
    void handle_events();
    void draw();
    void clean();
    bool running();
    bool currentPiece;

private:
    SDL_Surface* sdl_screen_;
    bool running_;
    int width_;
    int height_;
    int bpp_;
    Tableau tableau_;
    formes formes_;
    int numPiece;
};

#endif

