#pragma once

class Rock{
private:
	float x, y;

public:
	Rock();
	Rock(float x, float y);
	~Rock();
	float GetCordX();
	float GetCordY();
	void SetCord(float x, float y);

};

