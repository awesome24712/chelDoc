#ifndef CHEL_HASH_H
#define CHEL_HASH_H

namespace NHash {
	inline int mod(int a, int b) { 
		int modVal = a % b;
		if (a < 0 && modVal != 0) {
			modVal += b;
		}
		return modVal;
	}
	
	template<class T>
	unsigned int hash(const T& key) {
		unsigned int sum;
		bool bAlternate;
		for (int i = 0; i < sizeof(T); i++) {
			char curByte = ((char*)(&key))[i];
			bAlternate = !bAlternate;
			sum += bAlternate ? curByte : ~curByte;
		}
		return sum;
	}
}
#endif //CHEL_HASH_H