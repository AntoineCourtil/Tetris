#include "../include/informations.h"
#include "../include/game.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

informations::informations() : police(NULL) {}

void informations::load_font()
{
    TTF_Init();
    //printf("TTF_Init: %s\n", TTF_GetError());
    police = TTF_OpenFont("/home/antoine/GitHub/Tetris/src/BebasNeue.otf", 30);
}

void informations::render(SDL_Surface *screen, int origine_x, int origine_y)
{
    int i;
    int j;
    int scr_w = screen->w;
    int scr_h = screen->h;
    sq_w  = scr_w/JEU_LARGEUR;
    sq_h  = scr_h/JEU_HAUTEUR;

    SDL_Rect rect;
    rect.w = scr_w-(origine_x*sq_w);
    rect.h = scr_h-(origine_y*sq_h);
    rect.x = origine_x*sq_w;
    rect.y = origine_y*sq_h;
    SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 0,0,52));

    for(i=0; i<=3; i++){;
        for(j=0; j<=3; j++){
            SDL_Rect rect2;
            rect2.w = sq_w-1;
            rect2.h = sq_h-1;
            rect2.x = i*sq_w+11*sq_w;
            rect2.y = j*sq_h+3*sq_h;
            SDL_FillRect(screen, &rect2, SDL_MapRGB(screen->format, 0,0,205));

        }
    }
}

void informations::texte(SDL_Surface *screen, int chrono, int score)
{
    SDL_Color clr_blanc = {255, 255, 255};

    SDL_Surface *txt_next = NULL;
    SDL_Rect position_txt_next;
    position_txt_next.x = 10.5*sq_w;
    position_txt_next.y = 1*sq_h;
    txt_next = TTF_RenderText_Blended(police, "Prochaine Piece", clr_blanc);

    SDL_Surface *txt_score = NULL;
    SDL_Rect position_txt_score;
    position_txt_score.x = 12*sq_w;
    position_txt_score.y = 10*sq_h;
    txt_score = TTF_RenderText_Blended(police, "Score", clr_blanc);

    SDL_Surface *txt_time = NULL;
    SDL_Rect position_txt_time;
    position_txt_time.x = 12*sq_w;
    position_txt_time.y = 15*sq_h;
    txt_time = TTF_RenderText_Blended(police, "Time", clr_blanc);

    SDL_Surface *txt_chrono = NULL;
    SDL_Rect position_txt_chrono;
    position_txt_chrono.x = 12.5*sq_w;
    position_txt_chrono.y = 16*sq_h;

    char char_chrono[3];
    sprintf(char_chrono,"%d", chrono);

    txt_chrono = TTF_RenderText_Blended(police, char_chrono, clr_blanc);

    SDL_Surface *score_score = NULL;
    SDL_Rect position_score_score;
    position_score_score.x = 12.5*sq_w;
    position_score_score.y = 11*sq_h;

    char char_score[3];
    sprintf(char_score,"%d", score);

    score_score = TTF_RenderText_Blended(police, char_score, clr_blanc);

    SDL_BlitSurface(txt_next, NULL, screen, &position_txt_next);
    SDL_BlitSurface(txt_score, NULL, screen, &position_txt_score);
    SDL_BlitSurface(txt_time, NULL, screen, &position_txt_time);
    SDL_BlitSurface(txt_chrono, NULL, screen, &position_txt_chrono);
    SDL_BlitSurface(score_score, NULL, screen, &position_score_score);

}

void informations::printGameover(SDL_Surface *screen)
{
    SDL_Color clr_blanc = {255, 255, 255};

    SDL_Surface *txt_gameover = NULL;
    SDL_Rect position_txt_gameover;
    position_txt_gameover.x = 11*sq_w;
    position_txt_gameover.y = 8*sq_h;
    txt_gameover = TTF_RenderText_Blended(police, "GAME OVER", clr_blanc);


    SDL_BlitSurface(txt_gameover, NULL, screen, &position_txt_gameover);
}
