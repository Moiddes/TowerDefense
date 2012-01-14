#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

void apply_surface();
void showscreen();

void movement(SDL_Surface *screen,SDL_Surface *bitmap,SDL_Surface *bug,SDL_Surface* bitmapT){
	int i=0,step_lr=90, step_ud=0, hp=30;
	unsigned int timer1, timer2;
	while(i<40 && hp>0){
		timer1=SDL_GetTicks()%100;
		timer2=SDL_GetTicks()%1000;
	    if(timer1==0){
	    	apply_surface( step_lr, step_ud, bug, screen );
	    	step_ud+=3;
	    	SDL_Flip( screen );
	    	showscreen(bitmap,screen,bitmapT);
	        i++;
	        }
	    if(timer2==0){
	    	hp-=5;
	    }
	    }
	i=0;
	while(i<41 && hp>0){
		timer1=SDL_GetTicks()%100; timer2=SDL_GetTicks()%1000;
	    if(timer1==0){
	    	apply_surface( step_lr, step_ud, bug, screen );
	    	step_lr+=3;
	    	SDL_Flip( screen );
	    	showscreen(bitmap,screen,bitmapT);
	        i++;
	    }
	    if(timer2==0){
	    	hp-=5;
		}
	}
	apply_surface( 0, 0, bitmap, screen );
	SDL_Flip( screen );
}


