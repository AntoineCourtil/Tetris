#ifndef _GAME_H_
#define _GAME_H_

#include <SDL/SDL.h>
#include "Tableau.h"
#include "../include/formes.h"
#include "../include/informations.h"
#include <time.h>


const int JEU_LARGEUR = 16;
const int JEU_HAUTEUR = 20;
const int x_nextPiece = 11;
const int y_nextPiece = 3;

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
    Tableau tableau_;
    int zone[TABLEAU_LARGEUR][TABLEAU_HAUTEUR];

private:
    SDL_Surface* sdl_screen_;
    bool running_;
    int width_;
    int height_;
    int bpp_;
    formes formes_;
    informations informations_;
    int numPiece;
    const float NUM_SECONDS = 0.5;
    clock_t last_time;
};

#endif

