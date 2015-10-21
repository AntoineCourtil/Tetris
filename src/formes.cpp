#include "../include/formes.h"
#include "../include/Tableau.h"
#include "../include/game.h"
#include <stdio.h>
#include <stdlib.h>


formes::formes()
{
    //
}

void formes::draw(int piece[TAILLE][TAILLE], SDL_Surface *screen, int origine_x, int origine_y)
{
    //printf("a");
    int i;
    int j;
    int scr_w = screen->w;
    int scr_h = screen->h;
    int sq_w  = scr_w/JEU_LARGEUR;
    int sq_h  = scr_h/JEU_HAUTEUR;

    for(j=0; j<=3; j++){;
        for(i=0; i<=3; i++){
            if (piece[j][i]!=0) {
                //printf("#");
                SDL_Rect rect;
                rect.w = sq_w-1;
                rect.h = sq_h-1;
                rect.x = i*sq_w+origine_x*sq_w;
                rect.y = j*sq_h+origine_y*sq_h;
                SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 255,0,0));
            }
            else {
                //printf(".");
            }
        }
        //printf("\n");
    }
    //printf("\n");

}


