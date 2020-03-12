#pragma once
#include <SDL.h>
#include "Sprite.h"


// GameMech class with a the game loop functions-- 
//run, input, update, draw, waitforenextframe, quit and cleanup

class GameMech
{
private:

	// For framerate
	int targetFramerate = 60;
	int frameDelayMs = 1000 / targetFramerate;

	//Undefined integers
	Uint32 frameEndTimeMs;
	Uint32 lastFrameStartTimeMs;
	Uint32 timeSinceLastFrame;


	//deltatime for gameplay
	float deltaTime;
	float gameTime = 0;

	//Pointers for for Drawing our window canvas and renderer 
	SDL_Window* pWindow = nullptr;
	SDL_Renderer* pRenderer = nullptr;

	
	// Mouse position
	SDL_Rect mousePosition;
	

	
	// ship movement functions
	void move();
	void checkBounds();
	

	// to know when to quit
	bool isRunning;

public:
	
	//constructors default
	GameMech();
	GameMech(const char* windowName, int windowSizeX, int windowSizeY);

	//destructors
	~GameMech();
	
	//Sprites declared in public... will clean up later.. 
	Sprite kay, background, kay2;

	

	// start the game loop
	void run();

	// input handling
	void input();

	// update your game world in here!
	void update();

	// draw your sprites here!
	void draw();

	// called at the end of the loop
	void waitForNextFrame();

	// stop running the game
	void quit();

	// clean memory related to the Game object.
	void cleanup();
};