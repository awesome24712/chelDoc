#ifndef CHEL_COORD2D
#define CHEL_COORD2D

#include "math.h"

struct Coord2D {
public:
	Coord2D() { X = 0; Y = 0; }
	Coord2D(int x, int y) { X = x; Y = y; }
	
	int X, Y;
	
	inline float length() const { return sqrtf(X*X + Y*Y); }
	float distanceTo(const Coord2D& other) const;
	
	void toLength(int len);
	inline void toUnit() { toLength(1); }
	//void toClampedLength(int min, int max);
	
	Coord2D operator+(const Coord2D& other) { return Coord2D(X + other.X, Y + other.Y); }
	Coord2D& operator+=(const Coord2D& other) { X += other.X; Y += other.Y; return *this; }
	Coord2D operator-(const Coord2D& other) { return Coord2D(X - other.X, Y - other.Y); }
	Coord2D& operator-=(const Coord2D& other) { X -= other.X; Y -= other.Y; return *this; }
	
	Coord2D operator*(float multiplier) { return Coord2D(X * multiplier, Y * multiplier); }
	Coord2D& operator*=(float multiplier) { X *= multiplier; Y *= multiplier; return *this; }
	
	Coord2D operator/(float divisor) { return Coord2D(X / divisor, Y / divisor); }
	Coord2D& operator/=(float divisor) { X /= divisor; Y /= divisor; return *this; }
};

#endif //CHEL_COORD2D