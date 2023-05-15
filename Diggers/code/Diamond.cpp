#include "Diamond.h"


Diamond::Diamond()
{
	this->x = -600.f;
	this->y = -600.f;
	drop = 25;
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
// int Diamond::get_drop()
// {
// 	return drop;
// }
