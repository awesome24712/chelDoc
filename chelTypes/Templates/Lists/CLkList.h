#ifndef CHEL_LKLIST_H
#define CHEL_LKLIST_H

template<typename T>
struct LkItem {
	T value;
	LkItem<T> * nextValue;
	
	LkItem<T>(T inValue, LkItem<T> * nextNode) {
		value = inValue;
		nextValue = nextNode;
	}
};

template< class T >
class CLkList {
	
private:
	LkItem<T>* m_pFirst = nullptr;
	LkItem<T>* m_pSecondLast = nullptr; //for easier popping/pushing
	LkItem<T>* m_pLast = nullptr;
	int m_iLength = 0;
	
	//these are used to enhance the performance linear indexing
	mutable LkItem<T>* m_pLastReferenced = nullptr;
	inline void nullifyLastReference() { m_pLastReferenced = nullptr;}
	mutable int		m_iLastReferencedIndex = 0;
	
	//KERNAL METHODS
	LkItem<T> * getItem(int pos) const;
public:

	/**
	 * @brief Default constructor builds an empty linked list.
	 */
	CLkList<T>();
	
	/**
	 * @brief Destructor flushes the list
	 */
	~CLkList<T>();
	
	/**
	 * @brief Adds {item} to {this} at position {pos}.
	 * @requires {this.length() >= pos}
	 * @updates {this}
	 * @param pos - the position to add the item at
	 * @param item - the item to add, by value
	 */
	void add(int pos, T item);
	
	/**
	 * @brief Removes the item at position {pos}.
	 * @requires {pos < this.length()}
	 * @updates {this}
	 * @param pos - the position to remove from 
	 * @return the removed item
	 */
	T remove(int pos);
	
	/**
	 * @brief Retrieves the value of the item at {pos}.
	 * @param pos - the position to look at
	 * @requires {pos < this.length()}
	 * @return the item
	 */
	inline T get(int pos) const;
	
	/**
	 * @brief Retrieves or calculates the number of items in the list.
	 * @requires the list does not contain any branches
	 * @return the length of the list.
	 */
	int length() const;
	
	T* getPtr(int pos) const;
	
//SECONDARY METHODS
	/**
	 * @brief Checks whether or not {this} is empty
	 * @return {this->m_iLength == 0}
	 */
	inline bool isEmpty() const {return m_iLength == 0;}

	/**
	 * @brief Pops off the last item from {this} and returns it.
	 * @requires {this.length() > 0}
	 * @return the removed item at the end of {this}
	 */
	inline T pop();
	
	/**
	 * @brief Pushes the given item onto the end {this}.
	 * @updates {this}
	 * @param item - the item to append
	 */
	inline void push(T item);
	
	/**
	 * @brief Appends the items in {otherList} onto the end of {this}.
	 * @updates {this}
	 * @restores {otherList}
	 * @param otherList
	 */
	void push(CLkList<T>& otherList);
	
	/**
	 * @brief Retrieves the value at the front {this} without removing it.
	 * @requires {this.length() > 0}
	 * @return the value at the front of {this}
	 */
	T front() const;
	
	/**
	 * @brief Retrieves the value at the end of {this} without removing it.
	 * @requires {this.length() > 0}
	 * @return the value at the end of {this}
	 */
	T end() const;
	
	/**
	 * @brief Empties the list of all its items.
	 * @updates this
	 * @warn If the items are pointers to items in the heap, does NOT delete the items off the heap
	 */
	void flush();
	
	/**
	 * @brief Replaces the item at {pos} with {replacement}
	 * @requires {0 <= pos < this.length()}
	 * @updates this
	 * @param pos
	 * @param replacement
	 */
	inline void replace(int pos, T replacement);
	
	/**
	 * @brief Flips the list 
	 * @updates {this}
	 */
	void flip();
	
};
#endif //CHEL_LKLIST_H