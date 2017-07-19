#include "Vector.h"
#include "math.h"

#define sqr(A) ((A) * (A))

Vector::Vector() {
	X = Y = Z = 0.0f;
}

Vector::Vector(float x) {
	X = x;
	Y = Z = 0.0f;
}

Vector::Vector(float x, float y, float z) {
	X = x; Y = y; Z = z;
}

void Vector::toLength(float magnitude) {
	*this /= magnitude / length();
}

void Vector::toClampedLength(float min, float max) {
	if (length() < min)
		toLength(min);
	else if (length() > max)
		toLength(max);
}

float Vector::length() const {
	return sqrtf(sqr(X) + sqr(Y) + sqr(Z));
}

Vector Vector::operator +(const Vector& v2) {
	return Vector(X + v2.X, Y + v2.Y, Z + v2.Z);
}

Vector& Vector::operator +=(const Vector& v2) {
	X += v2.X; Y += v2.Y; Z += v2.Z;
	return *this;
}

Vector Vector::operator -(const Vector& v2) {
	return Vector(X - v2.X, Y - v2.Y, Z - v2.Z);
}

Vector& Vector::operator -=(const Vector& v2) {
	X -= v2.X; Y -= v2.Y; Z -= v2.Z;
	return *this;
}

Vector Vector::operator *(float multiplier) {
	return Vector(X*multiplier, Y*multiplier, Z*multiplier);
}

Vector& Vector::operator *=(float multiplier) {
	X *= multiplier; Y *= multiplier; Z *= multiplier;
	return *this;
}

Vector Vector::operator /(float divisor) {
	return Vector(X/divisor, Y/divisor, Z/divisor);
}

Vector& Vector::operator /=(float divisor) {
	X /= divisor; Y /= divisor; Z /= divisor;
}

