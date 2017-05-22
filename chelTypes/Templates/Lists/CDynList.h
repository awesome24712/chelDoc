#ifndef CHEL_DYNLIST_H
#define CHEL_DYNLIST_H

class String;

template<class T> class CDynList {
	friend class String;
protected:
	int m_iReservedLength = 5;
	int m_iStartIndex = 0;
	int m_iEndIndex = 0;
	T* m_array;
	
	int m_iReserveBuffer = 5; //how many spaces to add when reserving new space
	bool m_bAutoTrim = true;
	
public:
	/**
	 * @brief Default constructor builds and empty lisr.
	 */
	CDynList<T>() {m_array = new T[m_iReservedLength];}
	
	/**
	 * @brief Constructors builds an empty list with the given amount of space reserved
	 * @param reservation
	 */
	CDynList<T>(int reservation) {m_iReservedLength = reservation; m_array = new T[m_iReservedLength];}

	/**
	 * @brief Constructor builds an dynamicly sizeable list
	 * @param num - the initial number of elements
	 * @param value - the initial value of all the elements
	 */
	CDynList<T>(int num, T value);
	
	/**
	 * @brief Destructor removes all items from the heap.
	 */
	~CDynList<T>() {
		flush(); 
		delete[] m_array;
	}

	/**
	 * @brief Retrieves the number of elements in the list.
	 * @return 
	 */
	inline int length() const {return m_iEndIndex - m_iStartIndex;}
	
	/**
	 * @brief Checks whether or not the list is empty
	 * @return {length() == 0}
	 */
	inline bool isEmpty() const {return length() == 0;}
	
	/**
	 * @brief Retrieves the length of the list, including empty slots
	 * 			reserved on either side of the list.
	 * @return the number of allocated positions in the list 
	 */
	inline int reservedLength() const {return m_iReservedLength;}
	
	/**
	 * @brief Retrieves a pointer to the element at the given position.
	 * @param pos - the desired offset from the the list's first element
	 * @requires {0 <= pos < length()}
	 * @return - a pointer to the item
	 */
	inline T* getPtr(int pos) const {return m_array + m_iStartIndex + pos;};
	
	/**
	 * @brief Retrieves the value contained at the given position
	 * @param pos - the position to look at
	 * @requires {0 <= pos < length()}
	 * @return the value contained at the position
	 */
	inline T get(int pos) const {return *getPtr(pos);}
	
	/**
	 * @brief Sets the number of spaces to add when reserving extra space on
	 * 			on either end of the array.
	 * @param bufferSize - the reserved space will increase by this amount on
	 * 			each reservation.
	 * @requires {bufferSize > 0}
	 * @perfwarn Larger values allow for faster growing and shrinking, but
	 * 				may take up more memory!
	 * @updates this
	 */
	inline void setReserveBuffer(int bufferSize) {m_iReserveBuffer = bufferSize;}
	
	/**
	 * @brief Allocates new array slots at the end of {this}.
	 * @param newSpace - the amount of slots to add
	 * @requires {newSpace > 0}
	 * @perfwarn Larger values allow for faster growing and shrinking, but
	 * 				may take up more memory!
	 * @updates this
	 */
	void reserve(int newSpace);
	
	/**
	 * @brief Allocates new array slots at the front of this {this}.
	 * @param newSpace
	 * @requires {newSpace > 0}
	 * @perfwarn Larger values allow for faster growing and shrinking, but
	 * 				may take up more memory!
	 * @updates this
	 */
	void reserveFront(int newSpace);
	
	/**
	 * @brief Asserts that the lengths of the reserved spaces on either side
	 * 			of the list does not exceed the size of the reserved buffer.
	 * 			Clamps the reserved length on either side, they may not end up
	 * 			as equal.
	 * @block Does nothing if reserved lengths are already within limits.
	 * @updates this
	 */
	void trim();
	
	/**
	 * @brief Sets whether or not to autotrim the list to remove empty reserved
	 * 			space
	 * @param setter - the override
	 * @updates this
	 */
	inline void setAutoTrim(bool setter) {m_bAutoTrim = setter;}
	
	/**
	 * @brief Checks whether or not the dynamic array is set to autotrim
	 * @return the current state of the autotrim
	 */
	inline bool getAutoTrim() const { return m_bAutoTrim;}
	
	/**
	 * @brief Adds a value to a given location, displacing other elements.
	 * @perfwarn May reallocate the list to fit the new size
	 * @param pos - the position to insert the element at
	 * @param value - the element to add
	 * @requires {0 <= pos < length()}
	 * @updates this
	 */
	void add(int pos, T value);
	
	/**
	 * @brief Removes a value to a given location, displacing other elements
	 * 			to fill the gap.
	 * @perfwarn May reallocate the list to take up less memory
	 * @param pos - the position of remove from
	 * @requires {0 <= pos < length()}
	 * @updates this
	 * @return the value removed
	 */
	T remove(int pos);
	
	/**
	 * @brief Sets the value at the given position to the given value
	 * @param pos - the position to replace
	 * @param value - the incoming value
	 * @requires {0 <= pos < length()}
	 * @return - the deleted value
	 */
	inline T replace(int pos, T value) {T orig = get(pos); *(getPtr(pos)) = value; return orig;}
	
	/**
	 * @brief Gets the position of a given value in the list, returning -1 otherwise.
	 * @param value - the value to look for.
	 * @return -1 if not found, otherwise the index of the first equal element 
	 */
	int indexOf(T value) const;
	
	/**
	 * @brief 
	 * @param other
	 * @return 
	 */
	int indexOf(const CDynList<T>& other) const;
	
	CDynList<T> subString(int start, int end);
	
	inline CDynList<T> subString(int start) { return subString(start, m_iEndIndex);}
	
	/**
	 * @brief Pops the value from the end of this.
	 * @perfwarn May reallocate the list to take up less memory
	 * @requires {!isEmpty()}
	 * @return The removed value
	 */
	inline T pop() {return remove(length()-1);}
	
	/**
	 * @brief Pushes a value onto the end of this.
	 * @perfwarn May reallocate the list to fit new size
	 * @param value - the value to push
	 */
	inline void push(T value) {add(length(), value);}
	
	/**
	 * @brief Pops the value from the front of this
	 * @return 
	 */
	inline T popFront() {return remove(0);}
	
	inline void pushFront(T value) {add(0, value);}
	
	void flip();
	void flush();
	
	operator T*();
	
	CDynList<T>& operator=(const CDynList<T>& str);
	
	CDynList<T> operator+(const CDynList<T>& other);
	
	CDynList<T>& operator+=(const CDynList<T>& other);
};
#endif //CHEL_DYNLIST_H