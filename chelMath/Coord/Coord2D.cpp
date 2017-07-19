#include "Coord/Coord2D.h"

#define sqr(a) (a)*(a)

inline int signof(int n) {
	if (n < 0)
		return -1;
	else
		return 1;
}

float Coord2D::distanceTo(const Coord2D& other) const {
	return sqrtf((float) sqr(X - other.X) + (float) sqr(Y - other.Y));
}

void Coord2D::toLength(int len) {
	X = signof(X) * len;
	Y = signof(Y) * len;
}