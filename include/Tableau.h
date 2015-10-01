#ifndef TABLEAU_H
#define TABLEAU_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>



enum {LIBRE, FILLED};

const int TABLEAU_HAUTEUR = 20;
const int TABLEAU_LARGEUR = 10;
const int DEPART_X = 0;
const int DEPART_Y = 5;



class Tableau
{
    public:
        int zone[TABLEAU_LARGEUR][TABLEAU_HAUTEUR];
        Tableau();
        void render(SDL_Surface *screen);

//        void flood(int i, int j, int px, int py, int k, int o, int valeur, bool visite[][TAILLE]);
//        void floodFill(int i, int j, int px, int py, int k, int o, int valeur);
//            void setpieceActuelle(Piece p);
//            Piece getpieceActuelle();
        //virtual ~Tableau();
    //protected:
    private:
//        Piece pieceActuelle;
};

#endif // TABLEAU_H
