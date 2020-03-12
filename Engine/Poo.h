#pragma once
#include "Graphics.h"
#include "Dude.h"

class Poo
{
public:
	Poo(int x, int y);
	void Update();
	void ProcessConsumption( const Dude& dude );
	void Draw(Graphics& gfx) const;
	bool IsEaten() { return isEaten; }
	static constexpr int width = 24;
	static constexpr int height = 24;
private:
	int x;
	int y;
	int vx;
	int vy;
	bool isEaten = false;
};