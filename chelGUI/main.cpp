#include "SDL/SDL.h"
#include <time.h>
#include "../chelTypes/chelTypes.hpp"

//setup the putpixel function
inline void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    //int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * 4;

	*(Uint32 *)p = pixel;
        //break;

    /*switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }*/
}

int main( int argc, char* args[] )
{ //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    //The attributes of the screen
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int SCREEN_BPP = 32;
    const int NOOFFLAKES = 100;
    int x[NOOFFLAKES];
    int y[NOOFFLAKES];
    int xo[NOOFFLAKES];
    int yo[NOOFFLAKES];

    //The surface that will be used
    SDL_Surface *screen = NULL;

	//Set up the screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_DOUBLEBUF|SDL_FULLSCREEN);
	SDL_ShowCursor(SDL_DISABLE);

	SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );
	SDL_WM_SetCaption( "Snow Test 1", NULL );

	//If there was an error in setting up the screen
	if( screen == NULL ) { return 1; }

    Uint32 white;
    Uint32 black;

	//Map the color white to this display (R=0xff, G=0xff, B=0xff)

    white = SDL_MapRGB(screen->format, 0xff, 0x11, 0x11);
    black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);

	//Setup Snow Flakes
	srand ( time (NULL));
	
	unsigned char r, g, b;
	
	while (true) {
		/* Lock the screen for direct access to the pixels */
		if ( SDL_MUSTLOCK(screen) ) {
			if ( SDL_LockSurface(screen) < 0 ) {
				fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
				return 4;
			}
		}
		if ( SDL_MUSTLOCK(screen) ) {
			SDL_UnlockSurface(screen);
			return 5;
		}
		
		Uint32 color = RandInt();//SDL_MapRGB(screen->format, r, g, b);
		r++;
		g+=2;
		b--;
		
		for (int j = 0; j < SCREEN_HEIGHT; j++) {
			for (int i = 0; i < SCREEN_WIDTH; i++) {
				putpixel(screen, i, j, color);
			}
		}
		SDL_UpdateRect(screen, 0, 0, 0, 0);
		//SDL_Delay(30);
	}
	
#if 0
	while (true) {
		for (int flake = 0; flake < NOOFFLAKES; flake ++)
		{

			x[flake] = rand () % SCREEN_WIDTH;
			y[flake] = rand () % (SCREEN_HEIGHT );
			xo[flake] = x[flake];
			yo[flake] = y[flake];

			/* Lock the screen for direct access to the pixels */
			if ( SDL_MUSTLOCK(screen) ) {
				if ( SDL_LockSurface(screen) < 0 ) {
					fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
					return 4;
				}
			}
			if ( SDL_MUSTLOCK(screen) ) {
				SDL_UnlockSurface(screen);
				return 5;
			}

			putpixel(screen, x[flake], y[flake], white);

			/* Update just the part of the display that we've changed */
			SDL_UpdateRect(screen, x[flake], y[flake], 1, 1);

		}
		SDL_Delay(40);
		white++;
	}
#endif
	
	/*int move, movex, movey;
	for (int loop = 0; true; loop  ++)
	{
		for (int flake = 0; flake < NOOFFLAKES; flake ++)
		{
			// choose whether to move left, right or straight down and by how many pixels
			move = rand () % 3;
			movex = (rand () % 2) + 1;
			movey = (rand () % 5) + 1;

			//backup the existing positions
			xo[flake] = x[flake];
			yo[flake] = y[flake];

			// now draw again

			/* Lock the screen for direct access to the pixels */
			/*if ( SDL_MUSTLOCK(screen) ) {
				if ( SDL_LockSurface(screen) < 0 ) {
					fprintf(stderr, "Can't lock screen: %s\n", SDL_GetError());
					return 1;
				}
			}
			if ( SDL_MUSTLOCK(screen) ) {
				SDL_UnlockSurface(screen);
				return 2;
			}*/

			/*putpixel(screen, xo[flake], yo[flake], black);

			// move down the screen by the no of movey
			if (y[flake] + (movey +1) < SCREEN_HEIGHT) {
					y[flake] = y[flake] + (movey +1);
			}
			else { 
				putpixel(screen, x[flake], y[flake], white);
				y[flake] = rand () % (SCREEN_HEIGHT / 2 );
			}

			if (x[flake] < 0)
				{x[flake] = movex;}
			if (x[flake] > SCREEN_WIDTH)
				{x[flake] = (SCREEN_WIDTH - movex);}

			// if 0 then left, 1 for right, else straight down
			if (move == 0)
				{x[flake] = x[flake] - movex;}
			if (move == 1)
				{x[flake] = x[flake] + movex;}

			putpixel(screen, x[flake], y[flake], white);

			/* Update just the part of the display that we've changed */
			/*SDL_UpdateRect(screen, xo[flake], yo[flake], 1, 1);
			SDL_UpdateRect(screen, x[flake], y[flake], 1, 1);

		}
		//set snowflake loop update delay
		//SDL_Delay (80);

	}*/

	//Wait 2 seconds
	SDL_Delay( 2000 );

    //Quit SDL
    SDL_Quit(); return 4; 
}