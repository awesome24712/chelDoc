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

template<class T>
class CDblLkLst {
private:
	SDLkNode<T>* m_pFirst = nullptr;
	SDLkNode<T>* m_pLast = nullptr;
	
	int m_iLength = 0;
	
	SDLkNode<T>* 	m_pLastReferenced = nullptr;
	int 			m_iLastReferencedIndex = 0;
	
	SDLkNode<T>* knownNodeClosestToIndex(int index, int& ldResultIndex);
	SDLkNode<T>* getNode(int index);
public:
	~CDblLkLst<T>() { flush(); }

	inline T*	getPtr(int index) { return &(getNode(index)->m_value); }
	inline T 	get(int index) { return *getPtr(index); }
	inline void set(int index, T value) { *getPtr(index) = value; }
	
	void 	add(int index, T value);
	T		remove(int index);
	
	inline void push(T value) { add(m_iLength, value); }
	inline T 	pop() { return remove(m_iLength - 1); }
	inline void pushFront(T value) { add(0, value); }
	inline T 	popFront() { return remove(0); }
	
	void flush();
	
	inline int 	length() const { return m_iLength; }
	inline bool isEmpty() const { return m_iLength == 0; }
};

#endif //CHEL_DBL_LK_LST_H