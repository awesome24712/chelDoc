#ifndef CHEL_ARRAY_HPP
#define CHEL_ARRAY_HPP 2
#endif

#if CHEL_ARRAY_HPP
#include "IArray.hpp"

template<class T>
#if CHEL_ARRAY_HPP == 2
#define CArray ICArray
class ICArray : public IList
#else
#undef CArray
class CArray
#endif
{
private:
	T* 		m_pBegin;
	T* 		m_pEnd;
	int 	m_iLength;
	
public:
	CArray(T* _begin, int _length) {
		m_pBegin = _begin;
		m_iLength = _length;
		
		m_pEnd = m_pBegin + m_iLength;
	}
	
	byte* 	begin() const { return (unsigned char*)m_pBegin; }
	
	byte* 	end() 	const { return (unsigned char*)m_pEnd; }
	
	int 	length()const { return m_iLength; }
	
	short 	elementSize() const { return sizeof (T); }
	
	//Guards here to prevent redefition of IArray function
	#if CHEL_ARRAY_HPP == 1
	inline 	int		lengthInBytes() const { return length() * elementSize(); }
	inline 	byte* 	get(int i) { return begin() + i * elementSize(); }
	inline 	byte* 	getByte(int i) { return begin() + i; }
	#endif
};



#if CHEL_ARRAY_HPP == 2
#undef CHEL_ARRAY_HPP
#define CHEL_ARRAY_HPP 1
#elif CHEL_ARRAY_HPP == 1

template<class T1, class T2> requires IIList<T1> && IIList<T2>
bool arrayequals(T1 pList1, T2 pList2) {
	bool result = false;
	if (pList1.length() == pList2.length()) {
		result = true;
		int i = 0;
		while (i++ < pList1.lengthInBytes() && result) {
			result = pList1.getByte(i) == pList2.getByte(i);
		}
	}
	return result;
}

template<class T> requires IIList<T>
void printList(T* pList) {
	for (int i = 0; i < pList->length(); i++) {
		printf("%c", *(pList->getByte(i)));
	}
	printf("\n");
}

#undef CHEL_ARRAY_HPP
#define CHEL_ARRAY_HPP 0
#endif

#endif //CHEL_ARRAY_HPP





