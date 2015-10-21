#ifndef TABLEAU_H
#define TABLEAU_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>



enum {LIBRE, FILLED};

const int TABLEAU_HAUTEUR = 20;
const int TABLEAU_LARGEUR = 10;
const int DEPART_X = 3;
const int DEPART_Y = 0;



class Tableau
{
    public:
        int zone[TABLEAU_LARGEUR][TABLEAU_HAUTEUR];
        Tableau();
        void render(SDL_Surface *screen);

    private:

};

#endif // TABLEAU_H
