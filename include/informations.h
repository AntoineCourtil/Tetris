#ifndef INFORMATIONS_H
#define INFORMATIONS_H
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>


class informations
{
    public:
        informations();
        void render(SDL_Surface *screen, int origine_x, int origine_y);
        void texte(SDL_Surface *screen);
        void printGameover(SDL_Surface *screen);
        void load_font();


    private:
        TTF_Font *police;
        int sq_w;
        int sq_h;

};

#endif // INFORMATIONS_H
