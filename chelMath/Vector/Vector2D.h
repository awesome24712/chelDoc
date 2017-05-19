#ifndef CHEL_VECTOR2D_H
#define CHEL_VECTOR2D_H

struct Vector2D {
	float X;
	float Y;
	
	Vector2D();
	Vector2D(float x);
	Vector2D(float x, float y);
	
	float length() const;
	
	inline void toLength(float magnitude);
	inline void toClampedLength(float min, float max);
	inline void toUnit() { toLength(1.0f); }
	
	Vector2D operator+(const Vector2D& v2);
	Vector2D& operator+=(const Vector2D& v2);
	Vector2D operator-(const Vector2D& v2);
	Vector2D& operator-=(const Vector2D& v2);
	
	Vector2D operator*(float multiplier);
	Vector2D& operator*=(float multiplier);
	
	Vector2D operator/(float divisor);
	Vector2D& operator/=(float divisor);
	
};

#endif //CHEL_VECTOR2D_H