#ifndef _GAME_H_
#define _GAME_H_

#include <SDL/SDL.h>
#include "Tableau.h"
#include "../include/formes.h"
#include "../include/informations.h"
#include <time.h>


const int JEU_LARGEUR = 16;
const int JEU_HAUTEUR = 20;

class Game {
public:
    Game();
    bool init_sdl(const char* title, int width, int height, int bpp);
    void handle_events();
    void draw();
    void clean();
    bool running();
    bool currentPiece;
    int posX;
    int posY;
    int numRotation;
    int numNextPiece;

private:
    SDL_Surface* sdl_screen_;
    bool running_;
    int width_;
    int height_;
    int bpp_;
    Tableau tableau_;
    formes formes_;
    informations informations_;
    int numPiece;
    const float NUM_SECONDS = 0.5;
    clock_t last_time;
};

#endif

