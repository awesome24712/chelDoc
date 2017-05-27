#ifndef CHEL_FIELD_H
#define CHEL_FIELD_H

#include "../Wrappers/Ptr.hpp"

template<class T> 
class CField {
private:
	CList<Ptr<CList<T>>> m_field;
	
	int m_iSize;
	int m_iWidth;
	int m_iHeight;
	
public:
	CField(int height, int width);
	CField(int height, int width, T initialValue);
	CField(const CField& otherSize, T initialValue);
	CField(const CField& other);
	CField<T>& operator=(const CField& other);

	T get(int j, int i) const;
	T getAbs(int i) const;
	
	T* getPtr(int j, int i) const;
	T* getPtrAbs(int i) const;
	
	inline void set(int j, int i, T value) { *getPtr(j, i) = value; }
	inline void setAbs(int i, T value) { *getPtrAbs(i) = value; }
	
	inline int size() const { return m_iSize; }
	inline int width() const { return m_iWidth; }
	inline int height() const { return m_iHeight; }
};

#endif //CHEL_FIELD_H

