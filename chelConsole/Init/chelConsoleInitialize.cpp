#include "chelConsoleInitialize.h"

bool g_bHasInit = false;
void NInitializations::ChelConsole() {
	if (!g_bHasInit) {
		g_bHasInit = true;
		ChelTypes();
	}
}