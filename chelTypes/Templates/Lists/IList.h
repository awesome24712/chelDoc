#ifndef CHEL_IARRAY_H
#define CHEL_IARRAY_H

template<class L> concept bool IIList =
	requires(L x) {
		typename L::value_t;
		//x.begin;
		//x.end;
		x.length;
		x.get;
		//x.elementSize;
		//x.lengthInBytes;
		//x.getByte
	};


#if 0
typedef unsigned char byte;

class IList;

/**
 * Concept to test whether or not a template parameter implements IList
 * 		or otherwise has bodies for methods declared in IList
 * IIList stands for "Implements IList"
 */
template<class T> concept bool IIList = 
	requires(T x) {
		x.begin;
		x.end;
		x.length;
		x.elementSize;
		x.lengthInBytes;
		x.getByte;
	};


class IList {
protected:
	/**
	 * Default constructors and destructors do nothing. 
	 */
	IList() {}
	~IList() {}
public:
	/**
	 * Retrieves a pointer to the first element in the array.
	 * @return - pointer to first element.
	 */
	virtual byte* 	begin() const = 0;
	
	/**
	 * Retrieves a pointer to the element at the end of the array.
	 * @return - pointer to last element.
	 */
	virtual byte* 	end() 	const = 0;
	
	/**
	 * Gets the length of this, in number of elements (not number of bytes).
	 * @return - number of elements in this
	 */
	virtual int 	length() 		const = 0;
	
	/**
	 * Gets the size in bytes of a single element of this.
	 * @return - the number of bytes used by each element.
	 */
	virtual short 	elementSize() 	const = 0;
	
	/**
	 * Calculates the length of the array in bytes.
	 * @return - the length in bytes.
	 */
	inline 	int		lengthInBytes() const { return length() * elementSize(); }
	
	inline 	byte* 	get(int i) { return begin() + i * elementSize(); }
	inline 	byte* 	getByte(int i) { return begin() + i; }
};
#endif
#endif //CHEL_IARRAY_H