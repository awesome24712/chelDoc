#ifndef CHEL_TYPES_INITIALIZE_H
#define CHEL_TYPES_INITIALIZE_H

#include "../chelMath/chelMath.hpp"

/**
 * Calls initializations of sub-libraries, and then calls initializations
 * 		of this library.
 * These functions are only called from main functions, and not on library load.
 * Beyond actual initializations, the purpose of these is to ensure libraries full
 * 		purposeful global-scope objects are loaded, even if no functions or objects
 * 		are directly accessed from higher up.
 */ 
namespace NInitializations {
	void ChelTypes();
}

#endif //CHEL_TYPES_INITIALIZE_H