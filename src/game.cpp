#include <SDL/SDL.h>
#include <iostream>
#include "../include/game.h"
#include "../include/formes.h"

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

    return true;
}

bool Game::running() {
    return running_;
}

void Game::handle_events() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        running_ = !(SDL_QUIT==event.type || (SDL_KEYDOWN==event.type && SDLK_ESCAPE==event.key.keysym.sym));

         /*if (SDL_MOUSEBUTTONDOWN==event.type && (SDL_BUTTON_LEFT==event.button.button || SDL_BUTTON_RIGHT==event.button.button || SDL_BUTTON_MIDDLE==event.button.button)) {

         }*/

    }

}

void Game::draw() {
    SDL_FillRect(sdl_screen_, NULL, SDL_MapRGB(sdl_screen_->format, 255, 255, 255));
    tableau_.render(sdl_screen_);
    formes_.draw(pieces[rand()%7][0],sdl_screen_);
    SDL_Flip(sdl_screen_);
}

void Game::clean() {
    if (sdl_screen_) SDL_FreeSurface(sdl_screen_);
    SDL_Quit();
}

