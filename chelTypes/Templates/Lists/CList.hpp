#ifndef CHEL_LIST_HPP
#define CHEL_LIST_HPP

#include "CList.h"
#include "../chelMath/math.hpp"


template<class T> void CList<T>::flip() {
	int num = length();
	for (int i = 0; i < num/2; i++) {
		swap(getPtr(i), getPtr(num-i-1));
	}
}

#endif //CHEL_LIST_HPP