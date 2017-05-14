#ifndef CHEL_LIST_H
#define CHEL_LIST_H

template<class T> class CList {
private:
	int 	m_iLength;
	T *		m_pFirst;
	
public:
	inline T* getPtr(int pos) const {return m_pFirst + pos;}
	inline T get(int pos) const {return *(getPtr(pos));}
	inline void set(int pos, T value) {*(getPtr(pos)) = value;}
	inline int length() {return m_iLength;}
	
	void flip();
	
	CList<T>(T value, int num) {
		m_iLength = num;
		m_pFirst = new T[m_iLength];
		T* pItr = m_pFirst;
		for (int i = 0; i < m_iLength; i++) {
			*pItr = value;
			pItr++;
		}
	}
	
	CList<T>(int num) {
		m_iLength = num;
		m_pFirst = new T[m_iLength];
	}
	
	~CList<T>() {
		delete[] m_pFirst;
	}
	
	
};
#endif //CHEL_LIST_H