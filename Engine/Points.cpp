#include "Points.h"

Point::Point(const Location & new_loc)
{
	loc = new_loc;
}

void Point::setNewLocation(const Location & new_loc)
{
	loc = new_loc;
}



void Point::DrawPoint(Board & brd)const
{
	brd.DrawCell(loc, c);
}
