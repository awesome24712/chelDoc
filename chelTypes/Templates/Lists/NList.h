#ifndef CHEL_NLIST_H
#define CHEL_NLIST_H

#include "IList.h"

namespace NList {
	#define EXTRACT_TYPE() typedef typename L::value_t T
	
	template<class L> requires IIList<L>
	int lengthInBytes(const L& list) {
		return list.length() * sizeof(typename L::value_t);
	}
	
	template<class R>
	R printint(const R& value, int (*pFunc)(const R&)) {
		Msg("%i\n", pFunc(value));
	}
	
	template<IIList L, typename R>
	R average(const L& list, R(*pFunc)(const typename L::value_t& value)) {
		EXTRACT_TYPE(); //this gives us the type in the list T
		R avg = pFunc(list.get(0));
		for (int i = 1; i < list.length(); i++) {
			avg = (avg * i + pFunc(list.get(i)))/(i+1);
		}
		return avg;
	}
}

#endif //CHEL_NLIST_H