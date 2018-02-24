#ifndef CHEL_LIST_H
#define CHEL_LIST_H

/**
 * @class CList
 * @author Awesome
 * @date 28/05/2017
 * @file CList.h
 * @brief Manages a staticly sized heap-allocated list.
 */
template<class T> class CList {
private:
	int 	m_iLength;
	T *		m_pFirst;
	
public:
	/**
	 * @brief Retrieves a pointer to the value at the given index
	 * @param pos - the index of the desired value
	 * @return - pointer of desired value
	 */
	inline T* getPtr(int pos) const {return m_pFirst + pos;}
	
	/**
	 * @brief Retrieves the value at the given index
	 * @param pos - the index of the desired value
	 * @return - the value
	 */
	inline T get(int pos) const {return *(getPtr(pos));}
	
	/**
	 * @brief Sets the value at the given index to the given value
	 * @param pos - the index of the overriden value
	 * @param value - the overriding value
	 */
	inline void set(int pos, T value) {*(getPtr(pos)) = value;}
	
	/**
	 * @brief Retrieves the length of the list
	 * @return - the length of the list
	 */
	inline int length() const {return m_iLength;}
	
	/**
	 * @brief Flips the list about its center
	 */
	void flip();
	
	/**
	 * @brief Builds a list of elements with the given value
	 * @param value - the initial value of all list elements
	 * @param num - the number of elements
	 */
	CList<T>(T value, int num);
	
	/**
	 * @brief Builds a list with the given number of elements
	 * @param num - the number of elements
	 * @requires - T has a default constructor
	 */
	CList<T>(int num) {
		m_iLength = num;
		m_pFirst = new T[m_iLength];
	}
	
	/**
	 * @brief Destructor removes list from the heap
	 * @requires - T has a default destructor
	 */
	~CList<T>() {
		delete[] m_pFirst;
	}
	
	/**
	 * Copy constructor and assignment operators perform deep copy
	 */
	CList<T>(const CList<T>& other);
	void operator=(const CList<T>& other);
};
#endif //CHEL_LIST_H