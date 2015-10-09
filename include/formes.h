#ifndef FORMES_H
#define FORMES_H
#include <SDL/SDL.h>


const int NB_TYPES=7; //nombres de types de pièces que l'on a
const int NB_ROTATIONS=4; // nombre de rotations pour chaques pièces
const int TAILLE=4; //taille de la matrice à manipuler

class formes {
public:
    formes();
    void draw(int piece[TAILLE][TAILLE], SDL_Surface *screen, int origine_x, int origine_y);

private:

};

static int pieces[NB_TYPES][NB_ROTATIONS][TAILLE][TAILLE]=
{//tableau avec toutes les pièces
    {//O
        {//forme1 de base de o
            {0,0,0,0},
            {0,1,2,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {//première rotation de o
            {0,0,0,0},
            {0,1,2,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {//deuxième
            {0,0,0,0},
            {0,1,2,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {//troisième
            {0,0,0,0},
            {0,1,2,0},
            {0,1,1,0},
            {0,0,0,0}
        }
    },
    {// I
        {
            {0,0,0,0},
            {1,1,2,1},
            {0,0,0,0},
            {0,0,0,0}
        },
        {
            {0,0,1,0},
            {0,0,2,0},
            {0,0,1,0},
            {0,0,1,0}
        },
        {
            {0,0,0,0},
            {1,1,2,1},
            {0,0,0,0},
            {0,0,0,0}
        },
        {
            {0,0,1,0},
            {0,0,2,0},
            {0,0,1,0},
            {0,0,1,0}
        },
    },
    {//S
        {
            {0,0,0,0},
            {0,2,1,0},
            {1,1,0,0},
            {0,0,0,0}
        },
        {
            {0,1,0,0},
            {0,2,1,0},
            {0,0,1,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {0,2,1,0},
            {1,1,0,0},
            {0,0,0,0}
        },
        {
            {0,1,0,0},
            {0,2,1,0},
            {0,0,1,0},
            {0,0,0,0}
        }
    },
    {//Z
        {
            {0,0,0,0},
            {1,2,0,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {
            {0,1,0,0},
            {1,2,0,0},
            {1,0,0,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {1,2,0,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {
            {0,1,0,0},
            {1,2,0,0},
            {1,0,0,0},
            {0,0,0,0}
        }
    },
    {//L
        {
            {0,1,0,0},
            {0,2,0,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {1,2,1,0},
            {1,0,0,0},
            {0,0,0,0}
        },
        {
            {1,1,0,0},
            {0,2,0,0},
            {0,1,0,0},
            {0,0,0,0}
        },
        {
            {0,0,1,0},
            {1,2,1,0},
            {0,0,0,0},
            {0,0,0,0}
        }
    },
    {//J
        {
            {0,0,0,0},
            {1,2,1,0},
            {0,0,1,0},
            {0,0,0,0}
        },
        {
            {0,1,0,0},
            {0,2,0,0},
            {1,1,0,0},
            {0,0,0,0}
        },
        {
            {1,0,0,0},
            {1,2,1,0},
            {0,0,0,0},
            {0,0,0,0}
        },
        {
            {0,1,1,0},
            {0,2,0,0},
            {0,1,0,0},
            {0,0,0,0}
        }
    },
    {//T
        {
            {0,0,0,0},
            {1,2,1,0},
            {0,1,0,0},
            {0,0,0,0}
        },
        {
            {0,1,0,0},
            {1,2,0,0},
            {0,1,0,0},
            {0,0,0,0}
        },
        {
            {0,1,0,0},
            {1,2,1,0},
            {0,0,0,0},
            {0,0,0,0}
        },
        {
            {0,1,0,0},
            {0,2,1,0},
            {0,1,0,0},
            {0,0,0,0}
        }
    }
};


#endif // FORMES_H
