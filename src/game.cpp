#include <SDL/SDL.h>
#include <iostream>
#include "../include/game.h"
#include "../include/formes.h"
#include <unistd.h>
#include <time.h>

Game::Game() : running_(false), tableau_() {
}

bool Game::init_sdl(const char* title, int width, int height, int bpp) {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cerr << "SDL_Init failed, SDL_GetError()=" << SDL_GetError() << std::endl;
        return false;
    }
    SDL_WM_SetCaption(title, NULL);
    sdl_screen_ = SDL_SetVideoMode(width, height, bpp, 0);
    if (!sdl_screen_) {
        std::cerr << "SDL_SetVideoMode failed, SDL_GetError()=" << SDL_GetError() << std::endl;
        return false;
    }
    running_ = true;
    width_ = width;
    height_ = height;
    bpp_ = bpp;
    currentPiece=false;

    last_time=clock()+(NUM_SECONDS * CLOCKS_PER_SEC);

    return true;
}

bool Game::running() {
    return running_;
}

void Game::handle_events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {

         if (SDL_KEYDOWN==event.type && (SDLK_RIGHT==event.key.keysym.sym) && posX<=TABLEAU_LARGEUR-TAILLE) {
            posX+=1;
         }
         if (SDL_KEYDOWN==event.type && (SDLK_LEFT==event.key.keysym.sym) && posX>1) {

            posX-=1;
         }

         if (SDL_KEYDOWN==event.type && (SDLK_DOWN==event.key.keysym.sym) && posY<TABLEAU_HAUTEUR-TAILLE) {
            posY+=1;
         }

         if (SDL_KEYDOWN==event.type && (SDLK_SPACE==event.key.keysym.sym)){
            numRotation+=1;
            if (numRotation>3){
                numRotation=0;
            }
         }

         /*if (SDL_MOUSEBUTTONDOWN==event.type && (SDL_BUTTON_LEFT==event.button.button || SDL_BUTTON_RIGHT==event.button.button || SDL_BUTTON_MIDDLE==event.button.button)) {

         }*/

         running_ = !(SDL_QUIT==event.type || (SDL_KEYDOWN==event.type && SDLK_ESCAPE==event.key.keysym.sym));



    }

}

void Game::draw() {

    SDL_FillRect(sdl_screen_, NULL, SDL_MapRGB(sdl_screen_->format, 255, 255, 255));
    tableau_.render(sdl_screen_);

    if (not currentPiece){
        numPiece=rand()%7;
        posX=3;
        posY=0;
        numRotation=0;
        currentPiece=true;
    }

    if (last_time<clock() && posY<TABLEAU_HAUTEUR-TAILLE){
        posY+=1;
        last_time=clock()+(NUM_SECONDS * CLOCKS_PER_SEC);
    }
    formes_.draw(pieces[numPiece][numRotation],sdl_screen_, posX, posY);
    SDL_Flip(sdl_screen_);

}

void Game::clean() {
    if (sdl_screen_) SDL_FreeSurface(sdl_screen_);
    SDL_Quit();
}

