//Funktion, um ein Bild an eine bestimmte Stelle auf dem Bildschirm
//zu setzen. 0,0 als erste beide Parameter entspricht dabei
//der linken oberen Ecke.

#include "SDL/SDL.h"

SDL_Surface *message = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, NULL, destination, &offset );
  }
