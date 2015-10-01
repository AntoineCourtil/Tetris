#include "Tableau.h"
#include <stdio.h>
#include <stdlib.h>

Tableau::Tableau() {
    int i;
    int j;

    for(i=0; i<TABLEAU_LARGEUR; i++) {
        for(j=0; j<TABLEAU_HAUTEUR; j++) {
            zone[i][j] = LIBRE;
            printf("#");
        }
        printf("\n");
    }
}

void Tableau::render(SDL_Surface *screen) {
    int scr_w = screen->w;
    int scr_h = screen->h;
    int sq_w  = scr_w/TABLEAU_LARGEUR;
    int sq_h  = scr_h/TABLEAU_HAUTEUR;

    for (int i=0; i<TABLEAU_LARGEUR; i++) {
        for (int j=0; j<TABLEAU_HAUTEUR; j++) {
            SDL_Rect rect;
            rect.w = sq_w-1;
            rect.h = sq_h-1;
            rect.x = i*sq_w;
            rect.y = j*sq_h;
            SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 255,127,80));
        }
    }


/*
    for (int i=0; i<(int)pieces_.size(); i++) {
        for (int j=0; j<(int)pieces_[i].size(); j++) {
            Vec2i pt = pieces_[i].pos + pieces_[i].cell(j)*square_size;
            SDL_Rect tmp;
            tmp.w = tmp.h = square_size-1;
            tmp.x = pt.x;
            tmp.y = pt.y;
            SDL_FillRect(screen, &tmp, SDL_MapRGB(screen->format, pieces_[i].rgb[0], pieces_[i].rgb[1], pieces_[i].rgb[2]));
        }
    }
*/
}


/*
void Tableau::setpieceActuelle()
{
    pieceActuelle = p;
}

Piece Tableau::getpieceActuelle()
{
    return pieceActuelle;
}

void Board::flood(int i, int j, int px, int py, int k, int o, int valeur, bool visite[][TAILLE])
{
    if(px < 0 || px >= TAILLE || py < 0 || py >= TAILLE || visite[px][py] || PIECES[k][o][px][py] == LIBRE)
        return;

    visite[px][py] = true;
    zone[j][i] = valeur;

    flood(i, j - 1, px, py - 1, k, o, valeur, visite);
    flood(i + 1, j, px + 1, py, k, o, valeur, visite);
    flood(i, j + 1, px, py + 1, k, o, valeur, visite);
    flood(i - 1, j, px - 1, py, k, o, valeur, visite);
}


void Board::floodFill(int i, int j, int px, int py, int k, int o, int valeur)
{
    bool visite[TAILLE][TAILLE];

    for(int l = 0; l < TAILLE; ++l)
        for(int m = 0; m < TAILLE; ++m)
            visite[l][m] = false;

    flood(i, j, px, py, k, o, valeur, visite);
}

*/
