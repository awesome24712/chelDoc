#ifndef CHEL_CONSOLE_INITIALIZE_H
#define CHEL_CONSOLE_INITIALIZE_H

#include "../chelTypes/chelTypes.hpp"

/**
 * Calls initializations of sub-libraries, and then calls initializations
 * 		of this library.
 * These functions are only called from main functions, and not on library load.
 * Beyond actual initializations, the purpose of these is to ensure libraries full
 * 		purposeful global-scope objects are loaded, even if no functions or objects
 * 		are directly accessed from higher up.
 */ 
namespace NInitializations {
	void ChelConsole();
}

#endif //CHEL_CONSOLE_INITIALIZE_H