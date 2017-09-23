#ifndef CHEL_IARRAY_H
#define CHEL_IARRAY_H

typedef unsigned char byte;

class IArray;

/**
 * Concept to test whether or not a template parameter implements IArray
 * 		or otherwise has bodies for methods declared in IArray
 * @return 
 */
template<class T> concept bool IIArray = 
	requires(T x) {
		x.begin;
		x.end;
		x.length;
		x.elementSize;
		x.lengthInBytes;
		x.getByte;
	};


class IArray {
protected:
	/**
	 * Default constructors and destructors do nothing. 
	 */
	IArray() {}
	~IArray() {}
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

#endif //CHEL_IARRAY_H