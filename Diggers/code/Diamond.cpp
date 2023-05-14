#include "Diamond.h"


Diamond::Diamond()
{
	this->x = -200.f;
	this->y = -200.f;
}

Diamond::Diamond(float x, float y)
{
	SetCord(x, y);
}

Diamond::~Diamond()
{
}

float Diamond::GetCordX()
{
	return x;
}

float Diamond::GetCordY()
{
	return y;
}

void Diamond::SetCord(float x, float y)
{
	this->x = x;
	this->y = y;
}

