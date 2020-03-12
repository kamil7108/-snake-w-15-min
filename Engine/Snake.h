#pragma once
#include "Graphics.h"
#include "Location.h"
#include "Board.h"
#include "Points.h"
#include <assert.h>
class Snake {
private:
	class Segment {
		Location loc;
		Color c;
		
	public:
		void InitHead(const Location & loc_in);
		void InitBody();
		void Follow(const Segment & seg);
		void DrawSegment(Board & brd)const;
		void MoveBy(const Location & delta_loc);
		bool ScoringPoint(Point & point);
		bool operator ==(const Segment & seg);
		int GetX() { return loc.x; }
		int GetY() { return loc.y; }
};
public:

	Snake(const Location & loc);
	void MoveBy(const Location & delta_loc);
	void Grow();
	void DrawSnake(Board & brd)const;
	bool ScoringPoint(Point & point);
	bool EatYourself();
	bool HitTheBand(const Location & loc, Board & brd);
private:
	static constexpr Color HeadColor = Colors::Green;
	static constexpr Color BodyColor = Colors::Yellow;
	int constexpr static maxSize = 100;
	Segment segments[maxSize];
	int currentlySize ;
	
};
