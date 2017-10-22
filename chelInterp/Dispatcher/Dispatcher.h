#ifndef CHEL_DISPATCHER
#define CHEL_DISPATCHER

#include "../../chelTypes/chelTypes.hpp"
#include "../../chelInterpBase/IInter/IInterp.h"
#include "../DynamicLoad/NDynamicLoad.h"

namespace NDispatcher {

	IInterp* getInterpreterFor(String& filePath);
	
	Ptr<CDocTree> getDocumentationFor(String& filePath);
}

#endif //CHEL_DISPATCHER