#include "CStringCase.h"

CStringCase::CStringCase(unsigned int flags) {
	m_iFlags = flags;
	m_sBannedCharacters = "";
	m_sBannedPrefixingCharacters = "";	
}

void CStringCase::applyPrefixesAndSuffixes() {
	m_pAppliedString->add(0, m_sAppliedPrefix);
	(*m_pAppliedString) += m_sAppliedSuffix;
}