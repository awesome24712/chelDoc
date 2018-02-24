#include "chelTypesInitialize.h"
#include "../chelMath/Init/chelMathInitialize.h"

bool g_bHasInit = false;
void NInitializations::ChelTypes() {
	if (!g_bHasInit) {
		g_bHasInit = true;
		ChelMath();
	}
}