#ifndef CHEL_MATH_HPP2
#define CHEL_MATH_HPP2
#include "CBase/CBase.h"

/**
 * @brief Clamps a value by reference
 * @param value - the value to clamp
 * @param min
 * @param max
 */
template<class T> void clamp(T& value, T min, T max) {
	if (value > max)
		value = max;
	else if (value < min)
		value = min;
}

template<class T> void clampMax(T& value, T max) {
	if (value > max)
		value = max;
}

template<class T> void clampMin(T& value, T min) {
	if (value < min)
		value = min;
}

/**
 * @brief Clones a given value
 * @param var - the value to clone
 * @return a copy of what's given
 */
template<class T> inline T clone(T var) {
	return var;
	}

template<class T, class R> T lerp(T lerp, R min, R max) {
	return min + lerp * (max-min);
}

/**
 * @brief Swaps to values by reference
 * @param a
 * @param b
 */
template<class T> void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

/**
 * @brief Swaps two values via pointers to those values.
 * @param a
 * @param b
 */
template<class T> void swap(T* a, T* b) {
	T tmp = *a;
	*a = *b;
	*b = tmp;
} 

#endif //CHEL_MATH_HPP2