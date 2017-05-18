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

template<class T> CList<T>::CList(const CList<T>& other) {
	m_iLength = other.m_iLength;
	m_pFirst = new T[m_iLength];
	
	for (int i = 0; i < m_iLength; i++)
		set(i, other.get(i));
}

template<class T> CList<T>::operator =(const CList<T>& other) {
	m_iLength = other.m_iLength;
	m_pFirst = new T[m_iLength];
	
	for (int i = 0; i < m_iLength; i++)
		set(i, other.get(i));
}

#endif //CHEL_LIST_HPP