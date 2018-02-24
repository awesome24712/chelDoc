#include "chelTesterInitialize.h"

bool g_bHasInit = false;
void NInitializations::ChelTester() {
	if (!g_bHasInit) {
		g_bHasInit = true;
		ChelTypes();
	}
}