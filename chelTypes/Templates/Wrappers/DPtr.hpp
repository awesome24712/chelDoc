#ifndef CHEL_DPTR_HPP
#define CHEL_DPTR_HPP

/**
 * @class DPtr
 * @author Awesome
 * @date 28/07/2017
 * @file DPtr.hpp
 * @brief Handles a pointer to a heap-allocated object. 
 * 		The object is destroyed whenever its DPtr is destroyed.
 */
template<class T> class DPtr {
private:
	T* m_pObj;
	
public:
	//TODO: implement!
};

#endif //CHEL_DPTR_HPP