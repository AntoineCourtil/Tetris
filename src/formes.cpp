#include "../include/formes.h"
#include "../include/Tableau.h"
#include <stdio.h>
#include <stdlib.h>

formes::formes()
{
    //
}

void formes::draw(int piece[4][4], SDL_Surface *screen)
{
    //printf("a");
    int i;
    int j;
    int scr_w = screen->w;
    int scr_h = screen->h;
    int sq_w  = scr_w/TABLEAU_LARGEUR;
    int sq_h  = scr_h/TABLEAU_HAUTEUR;

    for(i=0; i<=3; i++){;
        for(j=0; j<=3; j++){
            if (piece[i][j]!=0) {
                //printf("#");
                SDL_Rect rect;
                rect.w = sq_w-1;
                rect.h = sq_h-1;
                rect.x = i*sq_w+3*sq_w;
                rect.y = j*sq_h;
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

