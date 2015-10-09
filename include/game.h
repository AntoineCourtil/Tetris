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

private:
    SDL_Surface* sdl_screen_;
    bool running_;
    int width_;
    int height_;
    int bpp_;
    bool newPiece;
    Tableau tableau_;
    formes formes_;
};

#endif

