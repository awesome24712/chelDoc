#include "Rand.h"
#include <cstdint>
#include <ctime>
#include "stdio.h"

int a = 9158152, b = 57153;

#define abs(a) ((a) < 0 ? -(a) : (a) )

void RandReport() {
	printf("%i\n%i\n", a, b);
}

void RandSeed() {
	a = (int) time(nullptr);
	b += 200000000 * (a % 10);
}

int RandInt() {
	a += b + (a >> 5);
	b += a + (b >> 11);

	return abs(b);
}

int RandInt(int min, int max) {
	return (int) RandFloat(min, max+1);
}

float RandFloat() {
	return 1.0f * RandInt() / INT32_MAX;
}

float RandFloat(float min, float max) {
	return min + (max - min) * RandFloat();
}