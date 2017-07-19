#ifndef CHEL_VECTOR_H
#define CHEL_VECTOR_H

struct Vector {
	float X;
	float Y;
	float Z;
	
	Vector();
	Vector(float x);
	Vector(float x, float y, float z);
	
	float length() const;
	
	void toLength(float magnitude);
	void toClampedLength(float min, float max);
	inline void toUnit() { toLength(1.0f); }
	
	Vector operator+(const Vector& v2);
	Vector& operator+=(const Vector& v2);
	Vector operator-(const Vector& v2);
	Vector& operator-=(const Vector& v2);
	
	Vector operator*(float multiplier);
	Vector& operator*=(float multiplier);
	
	Vector operator/(float divisor);
	Vector& operator/=(float divisor);
	
};

#endif //CHEL_VECTOR_H