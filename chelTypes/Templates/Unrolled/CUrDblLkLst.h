#ifndef CHEL_CURDBLLKLST_H
#define CHEL_CURDBLLKLST_H

#include "../../../chelMath/chelMath.hpp"

template<class T, int N = 5> class CUrDblLkLst;

/**
 * @class SUrDblLkLstNode
 * @author Chel
 * @date 24/10/2017
 * @file CUrDblLkLst.h
 * @brief Outlines a node in an unrolled doubly-linked list.
 * 		Contains a function for splitting itself into two separate nodes
 */
template<class T, int N = 5>
struct SUrDblLkLstNode {
	friend class CUrDblLkLst<T,N>;
public:
	SUrDblLkLstNode* 	m_pPrevious;
	uint8 				m_iLength = 0;
	T					m_pArray[N];
	SUrDblLkLstNode*	m_pNext;
	
	/**
	 * @brief Inserts a value into this, displacing other values
	 * @param incomingValue
	 * @param index
	 * @requires this.length < N
	 * 			0 <= index <= this.length
	 */
	void insertNoSplit(const T& incomingValue, uint8 index);
	
	/**
	 * @brief Given a value and an index
	 * @param incomingValue - the value being added
	 * @param index - the relative index of this in which the value is being added
	 * @requires this.length == N
	 * 			0 <= index <= N
	 * @return - address of which node contains the value
	 */
	void /* SUrDblLkLstNode* */ split(const T& incomingValue, uint8 index);
	
	/**
	 * @brief Inserts a value into the node, splitting if necessary
	 * @param incomingValue
	 * @param index
	 * @requires 0 <= index <= this.length
	 */
	inline void insert(const T& incomingValue, uint8 index) {
		if (m_iLength == N)
			split(incomingValue, index);
		else
			insertNoSplit(incomingValue, index);
	}
	
	/**
	 * @brief 
	 * @param index - index of element to remove
	 * @param dest - removed value is copied to here
	 * @requires 0 <= index < this.length
	 */
	void erase(uint8 index);
	
	/**
	 * @brief 
	 * @param index - index of element to remove
	 * @param dest - removed value is copied to here
	 * @requires 0 <= index < this.length
	 */
	void remove(uint8 index, T& dest) {
		dest = m_pArray[index];
		erase(index);
	}
	
	/**
	 * @brief Merges this node with the node in front of it
	 * @requires this.length + this.next.length <= N
	 * 			0 <= index <= N
	 */
	void merge();
	
	/**
	 * @brief Copies values from the next node into this node
	 * 		to make this one at least half full
	 * @requires this.length + this.next.length >= N
	 */
	void balance();
};

/**
 * @class CUrDblLkLst
 * @author Chel
 * @date 24/10/2017
 * @file CUrDblLkLst.h
 * @brief An un-rolled doubly linked list. Combines add/remove benefits of linked lists
 * 		with the faster random access of actual arrays.
 * 		Smaller vaalues of N behave more like linked lists, larger values like arrays
 */
template <class T, int N> class CUrDblLkLst {
public:
	typedef T value_t;

	int					m_iLength;
	
	#define HALF_FULL		(N/2)
	#define HALF_FULL_UP	((N & 1) ? (N/2 + 1) : (N/2))
	#define HALF_FULL_DOWN	((N & 1) ? (N/2) : (N/2 + 1))
	
	mutable SUrDblLkLstNode<T, N>*	m_pFirst;
	mutable SUrDblLkLstNode<T, N>* 	m_pTerminal;	//sentinal nodes used to ensure consistent performance on edge cases
	
	mutable SUrDblLkLstNode<T, N>*	m_pLastReferenced;		//for faster iteration
	mutable int						m_iLastReferencedIndex; //NOT the index of last accessed value, but the index of the value at the front of m_pLastReferenced
	
	inline SUrDblLkLstNode<T, N>* postFinish() const { return m_pTerminal; }
	inline SUrDblLkLstNode<T, N>* nodeForPos(int& pos) const; //modifies pos to point to desired position in the returned node
	
public:
	CUrDblLkLst();
	
	T&		getRef	(int pos) 	const ;
	T*		getPtr	(int pos) 	const { return &(getRef(pos)); }
	T		get		(int pos) 	const { return getRef(pos); }
	
	int		length	()			const { return m_iLength; }
	
	void	add(const T& value, int pos);
	void 	erase(int pos);
	inline T remove(int pos) {
		T result = getRef(pos);
		erase(pos);
		return result;
	}
	
	void	pushFront(const T& value) { add(value, 0); }
	void	pushBack(const T& value) { add(value, length()); }
	
	void	copyTo(T* dest, int numElements);
	
	T		front() const { return get(0); }
};

#endif //CHEL_CURDBLLKLST_H