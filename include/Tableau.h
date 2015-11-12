#ifndef TABLEAU_H
#define TABLEAU_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>




const int TABLEAU_HAUTEUR = 20;
const int TABLEAU_LARGEUR = 10;
const int DEPART_X = 3;
const int DEPART_Y = 0;
//int zone[TABLEAU_LARGEUR][TABLEAU_HAUTEUR];


class Tableau
{
    public:
        //int zone[TABLEAU_LARGEUR][TABLEAU_HAUTEUR];
        Tableau();
        void render(SDL_Surface *screen, int zone[TABLEAU_LARGEUR][TABLEAU_HAUTEUR]);


    private:

};

#endif // TABLEAU_H
