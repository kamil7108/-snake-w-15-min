#include "Snake.h"

Snake::Snake(const Location & loc)
{
	currentlySize = 1;
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = currentlySize - 1; i > 0; i--) {
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (currentlySize < maxSize) { currentlySize++; 
		segments[currentlySize - 1].InitBody();
	}
}

void Snake::DrawSnake(Board & brd) const
{
	for (int i = 0; i < currentlySize; i++) {
		segments[i].DrawSegment(brd);
}
}

bool  Snake::ScoringPoint(Point & point)
{
	if (segments[0].ScoringPoint(point)) {
		return true;
 }
	return false;

}

bool Snake::EatYourself()
{
	for (int i = 1; i < currentlySize; i++) {
		if (segments[0] == segments[i])return true;
}
	return false;
}

bool Snake::HitTheBand(const Location & loc, Board & brd)
{
	if ((segments[0].GetX() + loc.x)*brd.GetGridDimension() < 0 || (segments[0].GetX() + loc.x)*brd.GetGridDimension() >= Graphics::ScreenWidth-1|| (segments[0].GetY() + loc.y)*brd.GetGridDimension() < 0 || (segments[0].GetY() + loc.y)*brd.GetGridDimension() >= Graphics::ScreenHeight - 1) { return true; }
	else {
		return false;
	}
}

bool Snake::Segment::operator==(const Segment & seg)
{
	if (loc == seg.loc)return true;
	else {
		return false;
	}
}

void Snake::Segment::InitHead(const Location & loc_in)
{
	loc = loc_in;
	c = Snake::HeadColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::BodyColor;
}

void Snake::Segment::Follow(const Segment & seg)
{
	loc = seg.loc;
}

void Snake::Segment::DrawSegment(Board & brd) const
{
	brd.DrawCell(loc, c);
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

bool Snake::Segment::ScoringPoint(Point & point)
{	
	return loc == point.GetLocation();
}
