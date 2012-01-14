#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

void apply_surface();

void showscreen( SDL_Surface* bitmap, SDL_Surface* screen,SDL_Surface* bitmapT){
	apply_surface( 0, 0, bitmap, screen );
	apply_surface( -20, -20, bitmapT, screen );//Datei: apply_surface.c
}
