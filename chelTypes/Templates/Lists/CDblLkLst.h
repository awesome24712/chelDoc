#ifndef CHEL_DBL_LK_LST_H
#define CHEL_DBL_LK_LST_H

template<class T>
struct SDLkNode {
	SDLkNode<T>* m_pre;
	SDLkNode<T>* m_post;
	T m_value;
	
	SDLkNode(SDLkNode<T>* pre, SDLkNode<T>* post, T value) {
		m_pre = pre;
		m_post = post;
		m_value = value;
	}
};

/**
 * @class CDblLkLst
 * @author Awesome
 * @date 27/05/2017
 * @file CDblLkLst.h
 * @brief An implementation of a double linked list.
 * 		The list maintains references to the start, end, and last referenced
 * 		nodes to improve speed of pushing, popping, and linear traversal.
 * 		TODO provide deep-copy operations!
 */
template<class T> class CDblLkLst {
private:
	SDLkNode<T>* m_pFirst = nullptr;
	SDLkNode<T>* m_pLast = nullptr;
	
	int m_iLength = 0;
	
	SDLkNode<T>* 	m_pLastReferenced = nullptr;
	int 			m_iLastReferencedIndex = 0;
	
	SDLkNode<T>* knownNodeClosestToIndex(int index, int& ldResultIndex);
	SDLkNode<T>* getNode(int index);
public:
	
	/**
	 * Copy contructor performs deep copy
	 */
	CDblLkLst<T>(const CDblLkLst<T>& other);
	
	/**
	 * @brief Assignment operator performs deep copy
	 * @param other - the list to copy by valueh
	 */
	CDblLkLst<T>& operator=(const CDblLkLst<T>& other);
	
	/**
	 * @brief Destructor removes all elements from the heap
	 */
	~CDblLkLst<T>() { flush(); }

	/**
	 * @brief Retrieves a pointer to the value at the given index
	 * @param index - the index of the desired value
	 * @return - a pointer to the value
	 */
	inline T*	getPtr(int index) { return &(getNode(index)->m_value); }
	
	/**
	 * @brief Retrieves a copy of the value at the given index
	 * @param index - the index of the desired value
	 * @return - a copy of the value
	 */
	inline T 	get(int index) { return *getPtr(index); }
	
	/**
	 * @brief Sets the value at the given index to the given value
	 * @param index - the index of the value to set
	 * @param value - the overriding value
	 */
	inline void set(int index, T value) { *getPtr(index) = value; }
	
	/**
	 * @brief Creates a new node in the list, displacing the list
	 * 			to the right.
	 * @param index - the index to insert it at
	 * @param value - the value of the node
	 */
	void 	add(int index, T value);
	
	/**
	 * @brief Removes a node at the given index 
	 * @param index - the index of the node to remove
	 * @return - the value of the removed node
	 */
	T		remove(int index);
	
	/**
	 * @brief Pushes a new node to the end of the list
	 * @param value - the value to add
	 */
	inline void push(T value) { add(m_iLength, value); }
	
	/**
	 * @brief Pops the end node from the list
	 * @return - the value of the node
	 */
	inline T 	pop() { return remove(m_iLength - 1); }
	
	/**
	 * @brief Pushes a new node to the front of the list
	 * @param value - the value of the node
	 */
	inline void pushFront(T value) { add(0, value); }
	
	/**
	 * @brief Pops the front node of the list
	 * @return - the value of the node
	 */
	inline T 	popFront() { return remove(0); }
	
	/**
	 * @brief Removes all elements from the list
	 */
	void flush();
	
	/**
	 * @brief Retrieves the length of the list
	 * @return - the length of the list
	 */
	inline int 	length() const { return m_iLength; }
	
	/**
	 * @brief Checks whether or not the list is empty
	 * @return - the emptiness
	 */
	inline bool isEmpty() const { return m_iLength == 0; }
};

#endif //CHEL_DBL_LK_LST_H