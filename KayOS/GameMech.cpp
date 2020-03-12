#include "GameMech.h"
#include <iostream>
#include <SDL_image.h>
#include "Projectile.h"

///Mech AABB collision detection
void GameMech::move()
{
	kay.setPosition(mousePosition.x, 295);
}


void GameMech::checkBounds()
{
	// check right boundary
	if (kay.getPosition().x > 800 - kay.getPosition().w)
	{

		kay.setPosition(800 - kay.getPosition().w * 0.25, 295);
	}

	// check left boundary
	if (kay.getPosition().x < 0)
	{

		kay.setPosition(kay.getPosition().w * 0.5, 295);
	}
}


GameMech::GameMech()
{
}

GameMech::GameMech(const char* windowName, int windowSizeX, int windowSizeY)
{
	int flags = SDL_INIT_EVERYTHING;

	if (SDL_Init(flags) == 0) // if initialized SDL correctly...
	{
		// Create the window
		pWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSizeX, windowSizeY, SDL_WINDOW_SHOWN);

		if (pWindow != nullptr)
		{
			// Create the renderer
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_PRESENTVSYNC);

			if (pRenderer != nullptr)
			{
				IMG_Init(IMG_INIT_PNG);
			}
		}
	}
}

GameMech::~GameMech()
{
}

void GameMech::run()
{
	
	//render background--
	background = Sprite(pRenderer, "background.png", 800, 600);
	background.setPosition(0, 0);


	//start with rendering of our sprites
	kay = Sprite(pRenderer, "kayos.png", 229, 410);
	kay.setPosition(2,295);
	kay.setSizeChar(229,410);

	kay2 = Sprite(pRenderer, "kayos.png", 229, 410);
	kay2.setPosition(600, 295);
	kay2.setSizeChar(229, 410);


	isRunning = true;		//starting the game loop, but, will terminate as soon as one of the function sets this to false....

	// set initial delta time
	deltaTime = 1.0f / targetFramerate;
	lastFrameStartTimeMs = SDL_GetTicks();

	while (isRunning)
	{
		input();
		update();
		draw();
		waitForNextFrame();
	}

	cleanup();
}

void GameMech::input()
{
	auto wheel = 0;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		/*switch (event.type)
		{
			// when the x button is clicked on the window
		case SDL_QUIT:
			quit();
			break;
			// when the mouse is moved
		//case SDL_MOUSEMOTION:
		//	mousePosition.x = event.motion.x;----------------------------------------- 7 PM TODAY
			//mousePosition.y = event.motion.y;
		//	break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				// press on the esc key to quit
			case SDLK_ESCAPE:
				quit();
				break;
			case SDLK_w:
				// move up
				std::cout << "move up" << std::endl;
				break;
			case SDLK_a:
				// move left
				std::cout << "move left" << std::endl;
				kay.setPosition(kay.getPosition().x - 20, 295);
				break;
			case SDLK_s:
				// move down
				std::cout << "move down" << std::endl;
				break;
			case SDLK_d:
				// move right
				std::cout << "move right" << std::endl;
				kay.setPosition(kay.getPosition().x + 20, 295);
				break;
			}
			break;
		default:
			break;
		}
		*/
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_SPACE:
			{
				//projctive dst.x - kay.dst.x
				//projctive dst.y - kay.dst.y
				break;
			}
			case SDLK_LEFT:
			{
				kay.dst.x-= 5;
				break;
			}
			case SDLK_RIGHT:
			{
				kay.dst.x -= 5;
				break;
			}
			case SDLK_ESCAPE:
			{
				quit();
				break;
			}
			}
		}

	}
}

void GameMech::update()
{
	//mouse movement
	move();
	checkBounds();

}

void GameMech::draw()
{
	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(pRenderer);
	background.draw(pRenderer);
	kay.draw(pRenderer);
	kay2.draw(pRenderer);
	SDL_RenderPresent(pRenderer);
}


void GameMech::waitForNextFrame()
{
	Uint32 gameTimeMs = SDL_GetTicks();
	timeSinceLastFrame = gameTimeMs - lastFrameStartTimeMs;

	if (timeSinceLastFrame < frameDelayMs)
	{
		SDL_Delay(frameDelayMs - timeSinceLastFrame);
	}

	frameEndTimeMs = SDL_GetTicks();
	deltaTime = (frameEndTimeMs - lastFrameStartTimeMs) / 1000.f;
	gameTime = frameEndTimeMs / 1000.f;
	lastFrameStartTimeMs = frameEndTimeMs;
	//std::cout << deltaTime << std::endl;
}


void GameMech::quit()
{
	isRunning = false;
}

void GameMech::cleanup()
{
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
}
