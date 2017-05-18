#ifndef CHEL_FIELD_HPP
#define CHEL_FIELD_HPP

#include "CField.h"

template<class T> CField<T>::CField(int height, int width) {
	m_iSize = height * width;
	m_iHeight = height;
	m_iWidth = width;
	
	m_field = CList<Ptr<CList<T>>>(new Ptr<CList<T>>, height);
	
	for (int i = 0; i < height; i++) {
		CList<T>* curRow = new CList<T>(width);
		Ptr<CList<T>>* ptrRow = m_field.getPtr(i);
		ptrRow->init(curRow);
	}
}

template<class T> CField<T>::CField(int height, int width, T initialValue) {
	m_iSize = height * width;
	m_iHeight = height;
	m_iWidth = width;
	
	m_field = CList<Ptr<CList<T>>>(new Ptr<CList<T>>, height);
	
	for (int i = 0; i < height; i++) {
		CList<T>* curRow = new CList<T>(width, initialValue);
		Ptr<CList<T>>* ptrRow = m_field.getPtr(i);
		ptrRow->init(curRow);
	}
}

template<class T> CField<T>::CField(const CField<T>& otherSize, T initialValue) {
	m_iSize = otherSize.m_iSize;
	m_iHeight = otherSize.m_iHeight;
	m_iWidth = otherSize.m_iWidth;
	
	m_field = CList<Ptr<CList<T>>>(new Ptr<CList<T>>, m_iHeight);
	
	for (int i = 0; i < height; i++) {
		CList<T>* curRow = new CList<T>(m_iWidth, initialValue);
		Ptr<CList<T>>* ptrRow = m_field.getPtr(i);
		ptrRow->init(curRow);
	}
}

template<class T> CField<T>::CField(const CField& other) {
	m_iSize = other.m_iSize;
	m_iHeight = other.m_iHeight;
	m_iWidth = other.m_iWidth;
	
	m_field = CList<Ptr<CList<T>>>(new Ptr<CList<T>>, m_iHeight);
	for (int i = 0; i < height; i++) {
		CList<T>* curRow = new CList<T>(*(other.m_field.get(i));
		Ptr<CList<T>>* ptrRow = m_field.getPtr(i);
		ptrRow->init(curRow);
	}
}

template<class T> CField<T>::operator=(const CField& other) {
	m_iSize = other.m_iSize;
	m_iHeight = other.m_iHeight;
	m_iWidth = other.m_iWidth;
	
	m_field = CList<Ptr<CList<T>>>(new Ptr<CList<T>>, m_iHeight);
	for (int i = 0; i < height; i++) {
		CList<T>* curRow = new CList<T>(*(other.m_field.get(i));
		Ptr<CList<T>>* ptrRow = m_field.getPtr(i);
		ptrRow->init(curRow);
	}
}

template<class T> T CField<T>::get(int j, int i) {
	return (*(m_field.get(j))).get(i);
}

template<class T> T CField<T>::getAbs(int i) {
	int j = i / width;
	i = i % width;
	return (*(m_field.get(j))).get(i);
}

template<class T> T* CField<T>::getPtr(int j, int i) {
	return (*(m_field.get(j))).getPtr(i);
}

template<class T> T* CField<T>::getPtrAbs(int i) {
	int j = i / width;
	i = i % width;
	return (*(m_field.get(j))).getPtr(i);
}

#endif //CHEL_FIELD_HPP