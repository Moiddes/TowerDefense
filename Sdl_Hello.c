#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

int main()
{
    SDL_Surface *screen, *bitmap, *bug, *bitmapT;
    int running,i=0,step_ud=0,step_lr=90;
    unsigned int timer;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL konnte nicht initialisiert werden: %s\n",
            SDL_GetError());
        exit(1);
    }
    atexit(SDL_Quit);

     screen = SDL_SetVideoMode(600, 600, 0, 0);
    if (!screen) {
        fprintf(stderr, "Konnte Bildschirmmodus nicht setzen: %s\n",
            SDL_GetError());
        exit(1);
    }

    bitmap = SDL_LoadBMP("map.bmp");//Hintergrund laden
    if (!bitmap) {
        fprintf(stderr, "Bitmap konnte nicht geladen werden: %s\n",
            SDL_GetError());
        exit(1);
    }
    bitmapT = SDL_LoadBMP("bug2.bmp");//Hintergrund laden
    if (!bitmap) {
        fprintf(stderr, "Bitmap konnte nicht geladen werden: %s\n",
            SDL_GetError());
        exit(1);
    }
	bug = SDL_LoadBMP("bug1.bmp");
	if (!bug) {
	    fprintf(stderr, "Bitmap konnte nicht geladen werden: %s\n",
	    	SDL_GetError());
	    exit(1);
	}
    bug = colorkeying(bug); //Datei: coller_keying.c
    showscreen(bitmap,screen,bitmapT);
    SDL_Flip( screen );//Screen updaten


    running = 1;
    while(running) {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
        	if( event.type == SDL_KEYDOWN ){

            switch(event.key.keysym.sym) {
            case SDLK_s:
            	movement(screen, bitmap, bug, bitmapT);//ausgelagerte Funktion(fehlerhaft)
            	break;
            case SDLK_k:
            	running = 0;
            	break;
            }
        }
        	if(event.type == SDL_QUIT){
        		running = 0;
        		break;
        	}
    }
    }

    SDL_FreeSurface(bitmap);
    SDL_FreeSurface(bug);

  return 0;
}
