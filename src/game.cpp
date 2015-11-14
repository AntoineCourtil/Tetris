#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <iostream>
#include "../include/game.h"
#include "../include/formes.h"
#include "../include/informations.h"
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
    informations_.load_font();

    int i;
    int j;

    for(i=0; i<TABLEAU_LARGEUR; i++) {
        for(j=0; j<TABLEAU_HAUTEUR; j++) {
            zone[i][j] = 0;
            printf("#");
        }
        printf("\n");
    }

    return true;
}

bool Game::running() {
    return running_;
}

void Game::handle_events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {

         if (SDL_KEYDOWN==event.type && (SDLK_RIGHT==event.key.keysym.sym)) {
            //printf("%d %d\n",numRotation,posX);
            //printf("%d \n",posX);
            if (posX<6){
                posX+=1;
            }
            else{
                bool estVide=true;
                for(int k=0;k<4;k++){
                    if (pieces[numPiece][numRotation][k][9-posX]!=0){
                        estVide=false;
                        //printf("%d %d\n",numRotation,posX);
                    }
                    //printf("%d\n",pieces[numPiece][numRotation][k][9-posX]);
                }



                if(estVide==true){
                    posX+=1;
                }
            }
         }
         if (SDL_KEYDOWN==event.type && (SDLK_LEFT==event.key.keysym.sym)) {
                //printf("%d \n",posX);

                if (posX>0){
                    posX-=1;
                }
                else {
                    bool estVide=true;
                    for(int k=0;k<4;k++){
                        if (pieces[numPiece][numRotation][k][-posX]!=0){
                            estVide=false;
                            //printf("%d \n",-posX);
                        }
                        //printf("%d\n",-posX);
                    }
                    if(estVide==true){
                        posX-=1;
                    }
                }

         }

         if (SDL_KEYDOWN==event.type && (SDLK_DOWN==event.key.keysym.sym) ) {
            //posY+=1;

           if (posY<16){
                posY+=1;
            }
            else{
                bool estVide=true;
                for(int k=0;k<4;k++){
                    if (pieces[numPiece][numRotation][19-posY][k]!=0){
                        estVide=false;
                        //printf("%d %d\n",numRotation,posX);
                    }
                    //printf("%d\n",pieces[numPiece][numRotation][k][9-posX]);
                }
                if(estVide==true){
                    posY+=1;
                }
            }
         }

         if (SDL_KEYDOWN==event.type && (SDLK_SPACE==event.key.keysym.sym)){

            numRotation+=1;
            if (numRotation>3){
                numRotation=0;
            }

            if(posX<0){
                posX=0;
            }
            if(posX>6){
                posX=6;
            }



         }

         /*if (SDL_MOUSEBUTTONDOWN==event.type && (SDL_BUTTON_LEFT==event.button.button || SDL_BUTTON_RIGHT==event.button.button || SDL_BUTTON_MIDDLE==event.button.button)) {

         }*/

         running_ = !(SDL_QUIT==event.type || (SDL_KEYDOWN==event.type && SDLK_ESCAPE==event.key.keysym.sym));



    }

}

void Game::draw() {

    SDL_FillRect(sdl_screen_, NULL, SDL_MapRGB(sdl_screen_->format, 255, 255, 255));
    tableau_.render(sdl_screen_, zone);
    informations_.render(sdl_screen_,TABLEAU_LARGEUR,0);
    informations_.texte(sdl_screen_);

    if (not currentPiece){
        numPiece=numNextPiece;
        //numPiece=5;
        posX=3;
        posY=0;
        numRotation=0;
        numNextPiece=rand()%7;
        currentPiece=true;
    }

    if (last_time<clock()){

        last_time=clock()+(NUM_SECONDS * CLOCKS_PER_SEC);
        bool estVide=true;
        bool ligneVide=true;


                printf("posY : %d \n",posY);
                printf("posX : %d \n",posX);

            if (posY<16){
                /*for(int k=0;k<4;k++){
                    if (zone[posX+k][posY+3]!=0){
                        estVide=false;
                    }
                }*/
                for(int k=0;k<4;k++){
                    //printf("%d ",zone[posX+k][posY+3]+pieces[numPiece][numRotation][3][k]);
                    for(int j=0;j<4;j++){
                        printf("%d ",zone[posX+j][posY+k+1]+pieces[numPiece][numRotation][k][j]);
                        if (zone[posX+j][posY+k+1]+pieces[numPiece][numRotation][k][j]>1){
                            estVide=false;
                        }
                    }
                    printf("\n");
                }
                printf("\n\n");
            }
            else{
                for(int k=0;k<4;k++){
                    if (pieces[numPiece][numRotation][19-posY][k]!=0){
                        estVide=false;
                    }
                }
                for(int k=0;k<4;k++){
                    printf("%d \n",zone[posX+k][posY+3]+pieces[numPiece][numRotation][19-posY][k]);
                    if (zone[posX+k][posY+3]+pieces[numPiece][numRotation][19-posY][k]>1){
                        estVide=false;
                    }
                }
            }

            if(estVide==true){
                posY+=1;
            }
            else{
                formes_.freezePiece(pieces[numPiece][numRotation],sdl_screen_, posX, posY, zone);
                currentPiece=false;
            }
    }
    formes_.draw(pieces[numPiece][numRotation],sdl_screen_, posX, posY);
    formes_.draw(pieces[numNextPiece][0],sdl_screen_, x_nextPiece, y_nextPiece);
    //printf("%d",pieces[numPiece][numRotation][0][0]);
    SDL_Flip(sdl_screen_);

}

void Game::clean() {
    if (sdl_screen_) SDL_FreeSurface(sdl_screen_);
    SDL_Quit();
    TTF_Quit();
}

