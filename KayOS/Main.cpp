//Vineet Kumar
//cleanup the entire build to start from scratch
//git setup
//resharper C++
//class conversion
//sprite change
//additional sprites
//input detection and response
//collision detection

#include<iostream>
#include<SDL.h>
#include "SDL_image.h"
#include "GameMech.h"

GameMech game_v001;

int main(int argc, char* argv[])
{
	game_v001 = GameMech("Kay.OS - v0.01", 800, 600);
	game_v001.run();
	getchar();

	return 0;
}
