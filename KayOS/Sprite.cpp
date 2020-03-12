#include "Sprite.h"

Sprite::Sprite()
{
}

Sprite::Sprite(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY)
{
	pSpriteTexture = IMG_LoadTexture(renderer, filename);

	SDL_QueryTexture(pSpriteTexture, NULL, NULL, &src.w, &src.h);

	//start from which pixel of the source
	src.x = 0;
	src.y = 0;
	//to where and what size in our canvas
	dst.x = 0;
	dst.y = 0;
	dst.w = sizeX;
	dst.h = sizeY;
}

Sprite::~Sprite()
{
}

void Sprite::cleanup()
{
	SDL_DestroyTexture(pSpriteTexture);
}


//set position
void Sprite::setPosition(int x, int y)
{
	dst.x = x;	// -dst.w * 0.5f;
	dst.y = y;	// -dst.h * 0.5f;
}




SDL_Rect Sprite::getPosition()
{
	return dst;
}



void Sprite::setSize(int x, int y)
{
	dst.w = x;
	dst.h = y;
}

void Sprite::setSizeChar(int x, int y)
{
	dst.w = x*0.5;
	dst.h = y*0.5;
}

bool Sprite::isCollidingWith(const Sprite& s)
{
	//check if our xMin is less than Other's xMax and our xMax is greater than others xMin - use width here
	//check if our yMin is less than Other's yMax and our yMax is greater Other's ymin - use height here
	//
	//
	//


	
	return false;
}

void Sprite::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pSpriteTexture, &src, &dst);
}
