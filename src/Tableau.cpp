#include "Tableau.h"
#include <stdio.h>
#include <stdlib.h>

Tableau::Tableau()
{
    int i;
    int j;

    for(i=0;i<TABLEAU_LARGEUR;i++)
    {
        for(j=0;j<TABLEAU_HAUTEUR;j++)
        {
            zone[i][j] = LIBRE;
            printf("#");
        }
        printf("\n");
    }
}

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