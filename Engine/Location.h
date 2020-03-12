#pragma once
struct Location {
	int x;
	int y;
public:
	
	void Add(const Location & loc);
	bool operator ==(const Location & loc) {
		if (x == loc.x) {
			if (y == loc.y) {
				return true;
			}
	}
		return false;
	}
};
