#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Board.h"
class Point {
public:
	Point() :loc({ 0,0 }){}
	Point(const Location & new_loc);
	void setNewLocation(const Location & new_loc);
	void DrawPoint(Board & brd)const;
	Location GetLocation() { return loc; }
private:
	Location loc;
	Color c=Colors::Red;

};