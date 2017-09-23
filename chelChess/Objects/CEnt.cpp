#include "CEnt.h"

void CEnt::setEnabled(bool is) {
	if (is != isEnabled()) {
		m_bEnabled = is;
		if (is)
			onEnabled();
		else
			onDisabled();
	}
}