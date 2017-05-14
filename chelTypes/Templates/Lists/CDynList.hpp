#ifndef CHEL_DYNLIST_HPP
#define CHEL_DYNLIST_HPP
#include "CDynList.h"
#include "stdio.h"
#include "../chelMath/math.hpp"

template<class T> CDynList<T>::CDynList(int num, T value) {
	m_array = new T[num];
	m_iReservedLength = num;
	m_iEndIndex = num;
	for (int i = 0; i < num; i++)
		m_array[i] = value;
}

template<class T> void CDynList<T>::reserve(int newSpace) {
	m_iReservedLength += newSpace;
	T * newArray = new T[m_iReservedLength];
	for (int i = m_iStartIndex; i < m_iEndIndex; i++) {
		newArray[i] = m_array[i];
	}
	delete[] this->m_array;
	this->m_array = newArray;
}

template<class T> void CDynList<T>::reserveFront(int newSpace) {
	m_iReservedLength += newSpace;
	T * newArray = new T[m_iReservedLength];
	for (int i = m_iStartIndex; i < m_iEndIndex; i++) {
		newArray[i+newSpace] = m_array[i];
	}
	delete[] this->m_array;
	this->m_array = newArray;
	m_iStartIndex += newSpace;
	m_iEndIndex += newSpace;
}

template<class T> void CDynList<T>::trim() {
	//first check if we even need to trim
	int reservedBack = reservedLength() - m_iEndIndex;
	int reserveLimit = m_iReserveBuffer * 2;
	if (m_iStartIndex > reserveLimit || reservedBack > reserveLimit) {
		int reservedFront = m_iStartIndex;
		
		//build new array of correct size
		clampMax(reservedFront, m_iReserveBuffer);
		clampMax(reservedBack, m_iReserveBuffer);
		clampMin(reservedBack, 1);
		m_iReservedLength = reservedFront + length() + reservedBack;
		T * newArray = new T[m_iReservedLength];
		
		//copy contents of old array into new array
		for (int i = 0; i < length(); i++)
			newArray[reservedFront + i] = get(i);
			
		//restore indexes and delete old array
		m_iStartIndex = reservedFront;
		m_iEndIndex = m_iReservedLength - (reservedBack);
		clampMin(m_iEndIndex, 0);
		delete[] m_array;
		m_array = newArray;
	}
}

template<class T> void CDynList<T>::add(int pos, T value) {
	//absolute position in the array
	int absolutePos = m_iStartIndex + pos;
	
	//first determine which side we're adding to
	bool bFrontHalf = pos < length() / 2;
	
	//then determine if we need to reserve new space
	if (bFrontHalf && m_iStartIndex == 0) {
		this->reserveFront(m_iReserveBuffer);
		absolutePos += m_iReserveBuffer;
	} else if (!bFrontHalf && m_iEndIndex == reservedLength()) {
		this->reserve(m_iReserveBuffer);
	}
	
	//shift the values left or right, and insert value
	if (bFrontHalf) {
		//decrement start index
		m_iStartIndex--;
		absolutePos--;
		
		for (int i = m_iStartIndex; i < absolutePos; i++)
			m_array[i] = m_array[i+1];
	} else {
		for (int i = m_iEndIndex; i > absolutePos; i--) 
			m_array[i] = m_array[i-1];
			
		//increment end index
		m_iEndIndex++;
	}
	
	//copy value into its position
	m_array[absolutePos] = value;
}

template<class T> T CDynList<T>::remove(int pos) {
	//absolute position in the array
	int absolutePos = m_iStartIndex + pos;
	
	//first determine which side we're adding to
	bool bFrontHalf = pos < length() / 2;
	
	T removed = get(pos);
	
	//shift the values left or right, and forgetting value
	if (bFrontHalf) {
		for (int i = absolutePos; i > m_iStartIndex; i--)
			m_array[i] = m_array[i-1];
		
		//increment start index
		m_iStartIndex++;
	} else {
		//decrement end index
		m_iEndIndex--;
		for (int i = absolutePos; i < m_iEndIndex; i++) 
			m_array[i] = m_array[i+1];
	}
	
	//now check if we need to autotrim
	if (m_bAutoTrim)
		trim();
		
	return removed;
}

template<class T> int CDynList<T>::indexOf(T value) const {
	int foundIndex = -1;
	for (int i = 0; i < length(); i++) {
		if (get(i) == value) {
			foundIndex = i;
			break; //I will break you!
		}
	}
	return foundIndex;
}

template<class T> int CDynList<T>::indexOf(const CDynList<T>& other) const {
	bool foundFirst = false;
	int foundIndex = -1;
	bool foundLast = false;
	
	if (other.length() <= length() && !other.isEmpty()) {
		for (int i = 0; i < length() && !foundLast; i++) {
			//if we've already started checking matches
			if (foundFirst) {
				if (get(i) != other.get(i - foundIndex)) {
					foundFirst = false;
					foundIndex = -1;
				} else if ((i - foundIndex + 1) == other.length()) {
					foundLast = true; //completion
				}
			}
			//check for start of next match
			 if (get(i) == other.get(0) && !foundFirst) {
				foundFirst = true;
				foundIndex = i;
			}
		}
	}
	return foundIndex;
}

template<class T> CDynList<T> CDynList<T>::subString(int start, int end) {
	CDynList<T> result(end - start + 1);
	//can't use null termination, in case we're storing objects by value
	for (int i = start; i < end; i++)
		result.m_array[i] = m_array[i + m_iStartIndex];
	result.m_iEndIndex = end;
	return result;
}

template<class T> void CDynList<T>::flip() {
	int num = length();
	for (int i = 0; i < num / 2; i++) {
		swap(getPtr(i), getPtr(num-i-1));
	}
}

template<class T> void CDynList<T>::flush() {
	bool initialTrimState = getAutoTrim();
	setAutoTrim(false);
	while (!isEmpty()) {
		pop();
	}
	setAutoTrim(initialTrimState);
}

template<class T> CDynList<T>::operator T*() {
	//assert that the string is null-terminated
	m_array[m_iEndIndex] = 0;
	return m_array + m_iStartIndex;
}

template<class T>CDynList<T>& CDynList<T>::operator =(const CDynList<T>& str) {
	if (&str != this) {
		m_iReservedLength 	= str.m_iReservedLength;
		m_array 			= new char[m_iReservedLength];
		m_iReserveBuffer 	= str.m_iReserveBuffer;
		m_iEndIndex 		= str.m_iEndIndex;
		m_iStartIndex 		= str.m_iStartIndex;
		m_bAutoTrim			= str.m_bAutoTrim;
		for (int i = m_iStartIndex; i < m_iEndIndex; i++) {
			m_array[i] = str.m_array[i];
		}
	}
	return *this;
}

template<class T> CDynList<T> CDynList<T>::operator +(const CDynList<T>& other){
	CDynList<T> copy = *this;
	
	int reservedBack = reservedLength() - m_iEndIndex;
	int otherLength = other.length();
	if (otherLength >= reservedBack) {
		copy.reserve(otherLength + m_iReserveBuffer);
	}
	for (int i = 0; i < otherLength; i++)
		copy.push(other.get(i));
		
	return copy;
}

template<class T> CDynList<T>& CDynList<T>::operator +=(const CDynList<T>& other) {
	int reservedBack = reservedLength() - m_iEndIndex;
	int otherLength = other.length();
	if (otherLength >= reservedBack) {
		this->reserve(otherLength + m_iReserveBuffer);
	}
	for (int i = 0; i < otherLength; i++)
		this->push(other.get(i));
		
	return *this;
}
#endif //CHEL_DYNLIST_HPP