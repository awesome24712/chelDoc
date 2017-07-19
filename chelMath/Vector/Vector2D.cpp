#include "Vector2D.h"
#include "math.h"

#define sqr(A) ((A) * (A))

Vector2D::Vector2D() {
	X = Y = 0.0f;
}

Vector2D::Vector2D(float x) {
	X = x;
	Y = 0.0f;
}

Vector2D::Vector2D(float x, float y) {
	X = x; Y = y;
}

void Vector2D::toLength(float magnitude) {
	*this /= magnitude / length();
}

void Vector2D::toClampedLength(float min, float max) {
	if (length() < min)
		toLength(min);
	else if (length() > max)
		toLength(max);
}

float Vector2D::length() const {
	return sqrtf(sqr(X) + sqr(Y));
}

Vector2D Vector2D::operator +(const Vector2D& v2) {
	return Vector2D(X + v2.X, Y + v2.Y);
}

Vector2D& Vector2D::operator +=(const Vector2D& v2) {
	X += v2.X; Y += v2.Y;
	return *this;
}

Vector2D Vector2D::operator -(const Vector2D& v2) {
	return Vector2D(X - v2.X, Y - v2.Y);
}

Vector2D& Vector2D::operator -=(const Vector2D& v2) {
	X -= v2.X; Y -= v2.Y;
	return *this;
}

Vector2D Vector2D::operator *(float multiplier) {
	return Vector2D(X*multiplier, Y*multiplier);
}

Vector2D& Vector2D::operator *=(float multiplier) {
	X *= multiplier; Y *= multiplier;
	return *this;
}

Vector2D Vector2D::operator /(float divisor) {
	return Vector2D(X/divisor, Y/divisor);
}

Vector2D& Vector2D::operator /=(float divisor) {
	X /= divisor; Y /= divisor;
}

