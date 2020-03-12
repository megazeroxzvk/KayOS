#pragma once
#include<SDL_image.h>

// Sprite class which contains a texture, position, velocity, size, and functions for drawing it.

class Sprite
{
private:
	
	SDL_Texture* pSpriteTexture = nullptr;
	SDL_Rect src;

public:

	//Members--------------------------------

	// constuctors
	Sprite();			// default constructor
	Sprite(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY);

	// destructor
	~Sprite();

	// declared the dst rect as public for accessiblity
	SDL_Rect dst;

	// velocity (maybe not necessary for every sprite)
	float velX = 0;
	float velY = 0;



	//Methods--------------------------------

	//set the size of our sprite
	void setSize(int x, int y);
	void setSizeChar(int x, int y);
	bool isCollidingWith(const Sprite &s);

	//finally draw the sprte using renderer
	void draw(SDL_Renderer* renderer);



	//XXXXXXXXXXXXXXXXXXXXXXXXXXXX
	void setPosition(int x, int y);
	SDL_Rect getPosition();
	virtual void update(float deltaTime);

	void cleanup();
};

