#pragma once
#include "Location.h"
#include "Graphics.h"
#include <assert.h>
class Board {
public:
	Board(Graphics & gfx):gfx(gfx){}
	void DrawCell(const Location & loc, Color c);
	 int GetGridWeight() { return weight; }
	 int GetGridHeight() { return height; }
	 int GetGridDimension(){ return dimension; }
	 void DrawGameOver();
private:
	static constexpr int dimension = 10;
	static constexpr int weight = 80;
	static constexpr int height = 60;
	Graphics & gfx;
	
};