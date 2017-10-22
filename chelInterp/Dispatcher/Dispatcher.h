#ifndef CHEL_DISPATCHER
#define CHEL_DISPATCHER

#include "../../chelInterpBase/IInterp/IInterp.h"
#include "../DynamicLoad/NDynamicLoad.h"

namespace NDispatcher {

	IInterp* getInterpreterFor(String& filePath);
	
	Ptr<NChelDoc::CDocTree> getDocumentationFor(String& filePath);
}

#endif //CHEL_DISPATCHER