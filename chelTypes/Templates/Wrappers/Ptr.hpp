#ifndef CHEL_PTR_HPP
#define CHEL_PTR_HPP

template<class T>
struct Ptr {
private:
	T* 		m_ptReference = nullptr;
	int*	m_piReferenceCount = nullptr;
	
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
	operator T*() {return m_ptReference;}
	T& operator*() {return *m_ptReference;}
	operator bool () { return m_ptReference; }
};

#endif //CHEL_PTR_HPP