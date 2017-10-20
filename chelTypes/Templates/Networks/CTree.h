#include "../Lists/CDynList.hpp"
#include "../../String/String.h"
#include "../Wrappers/Ptr.hpp"

template<class T> class CTreeHandle;
template<class T> class Ptr;

class CXMLTree;

template<class T>
class CTree {
	friend class CXMLTree;
	friend class CTreeHandle<T>;
	friend class Ptr<CTree<T>>;
protected:
	T 					m_tValue;
	CTree<T>* 			m_pParent;
	CDynList<CTree<T>*> m_aChildren;
	
	CTree(const T& value) {
		m_tValue = value;
		m_pParent = nullptr;
	}
	~CTree() {
		for (int i = 0; i < m_aChildren.length(); i++) {
			delete m_aChildren.get(i);
		}
		printf("Destorying tree node\n");
	}
	
	
public:
	/**
	 * @brief Retrieves the value at this node.
	 * @return - the value.
	 */
	T value() const { return m_tValue; }
	
	/**
	 * @brief Retrieves the address of the value at this node;
	 * @return - the address.
	 */
	T* valuePtr() const { return &m_tValue; }
	
	/**
	 * @brief Sets the value at this node to the given value.
	 * @param value - the new value
	 */
	void setValue(const T& value) { m_tValue = value; }
	
	/**
	 * @brief Given a procedure which takes a pointer to T as a parameter,
	 * 	dispatches the procedure onto the value at this and onto all children.
	 * 	Order is depth-first.
	 */
	void dispatchProcedure(void (*pProcedure)(T*));
	
	/**
	 * @brief Given a function which takes a pointer to T and returns R,
	 * 		dispatches the function onto the value of this and onto all
	 * 		children, recursively. Returns a tree of results matching the
	 * 		original shape and ordering of the tree at this.
	 * @return - the tree of results
	 */
	template<class R> CTreeHandle<R> dispatchFunction(R (*pFunction)(T*)) {
		return CTreeHandle<T>(dispatchFunctionRecurse(pFunction));
	}
	
private:
	template<class R> CTree<R>* dispatchFunctionRecurse(R (*pFunction)(T*));
	
	//requires that otherTree has no parent already
	CTree<T>*	addChild(CTree<T>* otherTree) {
		assertFalse(otherTree->hasParent());
		
		otherTree->m_pParent = this;
		this->m_aChildren.push(otherTree);
		return otherTree;
	}
public:
	
	int numChildren() const { return m_aChildren.length(); }
	
	/**
	 * @brief Pushes a child onto this.
	 * @param value - the value of the child node.
	 * @return - address of added child.
	 */
	CTree<T>*	addChild(const T& value) {
		CTree<T>* pChild = new CTree<T>(value);
		pChild->m_pParent = this;
		m_aChildren.push(pChild);
		return m_aChildren.getEnd(0);
	}
	
	/**
	 * @brief Retrieves address of child, by index
	 * @param index
	 * @return 
	 */
	CTree<T>* 	child(int index) const {
		return m_aChildren.get(index);
	}
	
	/**
	 * @brief Given a value, returns the index of the first found child
	 * 		whose value() matches. Returns -1 otherwise.
	 * @param childValue - the value to look for
	 * @return - the index of the firstfound child with that value, -1 otherwise.
	 */
	int 		indexOfChild(const T& childValue) const;
	
	/**
	 * @brief Detaches a child ang gives it back as a CTreeHandle
	 * @param index - the index of the child to remove
	 * @return - a CTreeHandle for that child
	 */
	CTreeHandle<T> removeChild(int index) { return CTreeHandle<T>(m_aChildren.remove(index)); }
	
	/**
	 * @brief Gets the parent of this
	 * @return - pointer to parent
	 */
	CTree<T>* parent() const { return m_pParent; }
	
	/**
	 * @brief Inserts a node between this and the children of this.
	 * @updates this, this.children
	 * @param value - the value at the new node
	 * @return - address of the new node
	 */
	CTree<T>* insertSubParent(const T& value);
	
	/**
	 * @brief Allocates more space children. This happens automatically anyway
	 * 			but doing it manually can improve performance.
	 * @perf Use this if you are about to add more children, and you know
	 * 		about how many you will add.
	 * 		Larger amounts will allow for faster growing/shrinking, but take
	 * 		up more memory.
	 * @param newSpace - the number of extra children to allocate for.
	 */
	void reserve(int newSpace) {
		m_aChildren.reserve(newSpace);
	}
	
	/**
	 * @brief Modifiers the amount by which extra space is reserved when
	 * 		adding additional children to this requires re-allocation
	 * 		of the array. Larger values allow for faster adding/removing, but
	 * 		take up more memory.
	 * @perf Use larger values when the expected number of children is small,
	 * 		small values otherwise.
	 * @param iBuffer - the amount by which to grow
	 */
	void setReserveBuffer(int iBufferSize) {
		m_aChildren.setReserveBuffer(iBufferSize);
	}
	
	void toString(String& dest, void (*pFunc)(String&, const T&), int iIndentLevel = 0) const;
	
	/**
	 * @brief Recursively counts the number subtrees + 1
	 * @return - number of subtrees + 1
	 */
	int size() const;
	
};

template<class T>
class CTreeHandle {
	friend class CTree<T>;
	friend class CXMLTree;
protected:
	CTreeHandle(CTree<T>* pTree) {
		m_pNode = pTree;
	}
	
	Ptr<CTree<T>> m_pNode;
	
public:
	CTreeHandle(const T& value) {
		m_pNode = new CTree<T>(value);
	}
	
	~CTreeHandle() {
		//printf("Destroying tree handle\n");
	}
	
	CTree<T>& get() { return *m_pNode; }
	CTree<T>* getPtr() { return m_pNode; }
	
	operator CTree<T>*() const { return m_pNode; }
	operator CTree<T>&() const { return *m_pNode; } 
	CTree<T>* operator->() const { return m_pNode; }
	CTree<T>& operator*() const { return *m_pNode; }
};