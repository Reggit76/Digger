#include "Rock.h"


Rock::Rock()
{
	this->x = -200.f;
	this->y = -200.f;
}

Rock::Rock(float x, float y)
{
	SetCord(x, y);
}

Rock::~Rock()
{
}

float Rock::GetCordX()
{
	return x;
}

float Rock::GetCordY()
{
	return y;
}

void Rock::SetCord(float x, float y)
{
	this->x = x;
	this->y = y;
}

