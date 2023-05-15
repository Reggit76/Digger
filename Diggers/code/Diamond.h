#pragma once

class Diamond{
private:
	float x, y;
	int drop;

public:
	Diamond();
	Diamond(float x, float y);
	~Diamond();
	float GetCordX();
	float GetCordY();
	void SetCord(float x, float y);
	// int get_drop();
};

