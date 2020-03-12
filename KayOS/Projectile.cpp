#pragma once
#include "Projectile.h"


class Bullet :
	public Sprite
{
	float speed = 300;
	void update (float deltaTime) override;
};