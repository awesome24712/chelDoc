#ifndef CHEL_PTR_HPP
#define CHEL_PTR_HPP

template<class T> class CTree;
template<class T> class CTreeHandle;

template<class T>
struct Ptr {
	friend class CTree<T>;
	friend class CTreeHandle<T>;
	//friend void CTree<T>::destroyTree();
private:
	T* 		m_ptReference = nullptr;
	int*	m_piReferenceCount = nullptr;
	
public:
	//This forces the destruction of the object
	void destroy() {
		if (m_ptReference) {
			delete m_ptReference;
			delete m_piReferenceCount;
		}
	}
	
public:
	Ptr<T>() {}
	
	void init(T* newHeapObject) {
		AssertFalse(m_piReferenceCount || m_ptReference, "No reinitialization of Ptr smart pointer!");
		m_ptReference = newHeapObject;
		m_piReferenceCount = new int;
		*m_piReferenceCount = 1;
	}
	
	void nullify() {
		AssertTrue(m_ptReference, "No nullification of already null Ptr<>");
		(*m_piReferenceCount)--;
		if (*m_piReferenceCount == 0) {
			delete m_ptReference;
			delete m_piReferenceCount;
		}
	}

	Ptr<T>(T* newHeapObject) {
		init(newHeapObject);
	}
	
	Ptr<T>(const Ptr<T>& otherPtr) {
		m_ptReference = otherPtr.m_ptReference;
		m_piReferenceCount = otherPtr.m_piReferenceCount;
		if (m_piReferenceCount)
			(*m_piReferenceCount)++;
	}
	Ptr<T>& operator=(const Ptr<T>& otherPtr) {
		if (this != &otherPtr) {
			if(m_ptReference) {
				this->nullify();
			}
			m_ptReference = otherPtr.m_ptReference;
			m_piReferenceCount = otherPtr.m_piReferenceCount;
			if (m_piReferenceCount)
				(*m_piReferenceCount)++;
		}
		return *this;
	}
	
	T* operator ->() const{
		return m_ptReference;
	}
	
	~Ptr<T>(){
		if (m_ptReference) {
			nullify();
		}
	}
	
	inline int numReferences() const {
		if (m_piReferenceCount)
			return *m_piReferenceCount;
		else
			return 0;
	}
	
	operator T*() const {return m_ptReference;}
	T& operator*() const {return *m_ptReference;}
	operator bool () const { return m_ptReference; }
	
	bool operator ==(const Ptr<T>& other) const {
		return this->m_ptReference == other.m_ptReference;
	}
};

#endif //CHEL_PTR_HPP