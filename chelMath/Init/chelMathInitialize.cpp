#include "chelMathInitialize.h"

bool g_bHasInit = false;
void NInitializations::ChelMath() {
	if (!g_bHasInit) {
		g_bHasInit = true;
		//do initializations here
	}
}