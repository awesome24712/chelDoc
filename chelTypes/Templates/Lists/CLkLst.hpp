#ifndef CHEL_LKLIST_HPP
#define CHEL_LKLIST_HPP

#include "CLkLst.h"
#include "../chelMath/math.hpp"

#define min(a,b) ((a) < (b) ? (a) : (b) )

template<class T> CLkLst<T>::CLkLst() {
	//default private parameters are defined in header
}

template<class T> CLkLst<T>::~CLkLst() {
	//remove all link nodes from the heap
	this->flush();
}

template<class T> LkItem<T> * CLkLst<T>::getItem(int pos) const {
	if (!(m_pLastReferenced && pos > m_iLastReferencedIndex)) {
		m_pLastReferenced = m_pFirst;
		m_iLastReferencedIndex = 0;
	}
	
	int difference = pos - m_iLastReferencedIndex;
	while (difference > 0) {
		m_pLastReferenced = m_pLastReferenced->nextValue;
		m_iLastReferencedIndex++;
		difference--;
	}
	return m_pLastReferenced;
}

template<class T> void CLkLst<T>::add(int pos, T item) {
	if (pos == 0) {
		m_pFirst = new LkItem<T>(item, m_pFirst);
		m_pLast = m_pFirst;
		m_pSecondLast = m_pFirst;
	} else {
		LkItem<T> * before = this->getItem(pos - 1);
		LkItem<T> * newItem = new LkItem<T>(item, before->nextValue);
		before->nextValue = newItem;
		
		//update pointers to end nodes
		if (pos == m_iLength) {
			m_pLast = newItem;
			m_pSecondLast = before;
		} else if (pos == m_iLength - 1) {
			m_pSecondLast = newItem;
		}
	}
	//unconst(); //we only added after the last reference, so we don't need to do this
	m_iLength++;
}

template<class T> T CLkLst<T>::remove(int pos) {
	T result;
	if (pos == 0) {
		//handle this edge case simply
		result = m_pFirst->value;
		LkItem<T> * pNext = m_pFirst->nextValue;
		delete m_pFirst;
		m_pFirst = pNext;
	} else {
		//Get necessary references
		LkItem<T> * pBeforeBefore; //handles edge case
		LkItem<T> * pBefore;
		if (pos > 2) {
			pBeforeBefore = this->getItem(pos - 2);
			pBefore = pBeforeBefore->nextValue;
		}
		else {
			pBeforeBefore = pBefore = this->getItem(pos - 1);
		}
		LkItem<T> * pRemoveMe = pBefore->nextValue;
		LkItem<T> * pAfter = pRemoveMe->nextValue;
		
		//now start deleting things and moving around
		pBefore->nextValue = pAfter;
		result = pRemoveMe->value;
		delete pRemoveMe;
		
		//check for change of pointers at end
		if (pos == m_iLength-1) {
			m_pLast = pBefore;
			m_pSecondLast = pBeforeBefore;
		} else if (pos == m_iLength - 2) {
			m_pSecondLast = pBefore;
		}
	}
	m_iLength--;
	return result;
}

template<class T> T CLkLst<T>::get(int pos) const {
	return this->getItem(pos)->value;
}

template<class T> int CLkLst<T>::length() const {
	return m_iLength;
}

template<class T> T* CLkLst<T>::getPtr(int pos) const {
	return &(getItem(pos)->value);
}

template<class T> T CLkLst<T>::pop() {
	return this->remove(length() - 1);
}

template<class T> void CLkLst<T>::push(T item) {
	this->add(length(), item);
}

template<class T> void CLkLst<T>::push(CLkLst<T>& otherList) {
	for (int i = 0; i < otherList.length(); i++) {
		this->push(otherList.get(i));
	}
}

template<class T> T CLkLst<T>::front() const {
	return (m_pFirst->value);
}

template<class T> T CLkLst<T>::end() const {
	return (m_pLast->value);
}

template<class T> void CLkLst<T>::flush() {
	//remove all link nodes from the heap
	while (!this->isEmpty())
		this->remove(0);
}

template<class T> void CLkLst<T>::replace(int pos, T replacement) {
	*(this->getPtr(pos)) = replacement;
}

template<class T> void CLkLst<T>::flip() {
	int num = this->length();
	if (num > 0) {
		int half = num/2;
		for (int i = 0; i < half; i++) {
			swap(getPtr(i), getPtr(num-i-1));
		}
	}
}
#endif //CHEL_LKLIST_HPP