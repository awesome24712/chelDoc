

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

	Ptr<T>(T* newHeapObject) {
		init(newHeapObject);
	}
	
	Ptr<T>(const Ptr<T>& otherPtr) {
		m_ptReference = otherPtr.m_ptReference;
		m_piReferenceCount = otherPtr.m_piReferenceCount;
		(*m_piReferenceCount)++;
	}
	Ptr<T>& operator=(const Ptr<T>& otherPtr) {
		if (this != &otherPtr) {
			(*m_piReferenceCount)--;
			if (*m_piReferenceCount == 0) {
				delete m_ptReference;
				delete m_piReferenceCount;
			}
			m_ptReference = otherPtr.m_ptReference;
			m_piReferenceCount = otherPtr.m_piReferenceCount;
			(*m_piReferenceCount)++;
		}
		return *this;
	}
	~Ptr<T>(){
		(*m_piReferenceCount)--;
		if (*m_piReferenceCount == 0) {
			delete m_ptReference;
			delete m_piReferenceCount;
		}
	}
	
	inline int numReferences() const {return *m_piReferenceCount;}
	operator T*() {return m_ptReference;}
	T& operator*() {return *m_ptReference;}
};