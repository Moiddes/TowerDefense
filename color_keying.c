//Funktion, um ein Bild zu laden und eine bestimmte Farbe
//transparent zu machen.

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

SDL_Surface *colorkeying(SDL_Surface *bug){
	Uint32 colorkey = SDL_MapRGB( bug->format, 255, 255, 255 );
	//255,255,255 ist der C-Farbwert für weiß.
    SDL_SetColorKey( bug, SDL_SRCCOLORKEY, colorkey );
    return bug;
}
