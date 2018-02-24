#ifndef CHEL_CHMAP_HPP
#define CHEL_CHMAP_HPP 2
#endif


#if CHEL_CHMAP_HPP != 0
#include "../CMap.hpp"
#include "../../Lists/CList.hpp"

/**
 * Concept to test whether or not a template parameter implements IHashable
 * IIHashable stands for "Implements IHashable"
 */
template<class T> concept bool IIHashable = 
	requires(T x) {
		x.hashSource;
		x.hashLength;
	};

#if CHEL_CHMAP_HPP == 1
template<class K, class V>
#else
template<class K, class V> requires IIHashable<K>
#endif
class CHMap {
	
private:
	CList<CMap<K,V>> m_aHashTable;
	int m_iSize;
	
#if CHEL_CHMAP_HPP == 1 
	static uint32 hash(K key) {
		uint32 sum = 0;
		bool bAlternate = false;
		for (uint32 i = 0; i < sizeof(K); i++) {
			char curByte = ((char*)(&key))[i];
			bAlternate = !bAlternate;
			sum += bAlternate ? curByte : ~curByte;
		}
		return sum;
	}
#else
	static uint32 hash(const char* pSource, uint32 iSize) {
		uint32 sum = 0;
		bool bAlternate = false;
		for (uint32 i = 0; i < iSize; i++) {
			char curByte = pSource[i];
			bAlternate = !bAlternate;
			sum += bAlternate ? curByte : ~curByte;
		}
		return sum;
	}
#endif
	
	CMap<K,V>* subMapFor(K key) const {
#if CHEL_CHMAP_HPP == 1
		uint32 hashCode = hash(key);
#else
		uint32 hashCode = hash(key.hashSource(), key.hashLength());
#endif
		uint32 modded = hashCode % m_aHashTable.length();
		
		return m_aHashTable.getPtr((int) modded);
	}
public:
	
	/**
	 * @brief Builds the hashmap
	 * @param iNumTables - the number of sub-maps
	 */
	CHMap(int iNumTables) : m_aHashTable(iNumTables) {
		m_iSize = 0;
	}

	/**
	 * @brief Checks whether or not the given key is
	 * 		already contained in the map
	 * @param key - the key to look for
	 * @return - the given key's presence
	 */
	inline bool hasKey(const K& key) const {
		return subMapFor(key)->hasKey(key);
	}
	
	/**
	 * @brief Checks whether or not the given value is
	 * 		contained in the map
	 * @param value - the value to look for
	 * @perfwarn - this method has to search through every submap
	 * @return - whether or not it's present
	 */
	inline bool hasValue(const V& value) const {
		bool bHasValue = false;
		for (int i = 0; i < m_aHashTable.length() && !bHasValue; i++) {
			bHasValue = m_aHashTable.getPtr(i)->hasValue(value);
		}
		return bHasValue;
	}

	/**
	 * @brief Adds a key value pair to the map
	 * @param key - the unique key to add
	 * @param value - the value to that's binded to the key
	 * @requires - the given key is not already in the map
	 */
	inline void add(const K& key, const V& value) {
		subMapFor(key)->add(key, value);
		m_iSize++;
	}
	
	/**
	 * @brief Removes the given key from the map
	 * @param key - the key to remove
	 * @return - the value associated with the key
	 */
	inline V remove(const K& key) {
		m_iSize--;
		return subMapFor(key)->remove(key);
	}
	
	/**
	 * @brief Removes all keys from the map
	 */
	inline void flush() {
		for(int i = 0; i < m_aHashTable.length(); i++) {
			m_aHashTable.getPtr(i)->flush();
		}
		m_iSize = 0;
	}
	
	/**
	 * @brief Finds address of value associated with the given key
	 * @param key - the key whose value to find
	 * @return - the address of the value bound to the key
	 * @requires - the key exists in the map
	 */
	inline V* valuePtr(const K& key) const {
		return subMapFor(key)->valuePtr(key);
	}
	
	/**
	 * @brief Finds the value associated with the given key
	 * @param key - the key whose value to find
	 * @return - the value bound to the key
	 * @requires - the key exists in the map
	 */
	inline V value(const K& key) const {
		return *valuePtr(key);
	}
	
	/**
	 * @brief Finds the first key bound to the given value
	 * @param value - the value to look for
	 * @perfwarn - this function cannot use hashing to its performance benefit.
	 * @return - any key bound to the value
	 */
	K key(const V& value) const {
		assertTrue(hasValue(value), "Violation of: in CHMap<T>::key(V), this has value.");
		K keyResult;
		bool bFoundKey = false;
		for (int i = 0; i < m_aHashTable.length() && !bFoundKey; i++) {
			if (m_aHashTable.getPtr(i)->hasKey(value)) {
				bFoundKey = true;
				keyResult = m_aHashTable.getPtr(i)->key(value);
			}
		}
		return keyResult;
	}
	
	/**
	 * @brief Gets the numbers of key-value pairs in the map.
	 * @return the size of the map.
	 */
	inline int size() const { return m_iSize; }
	
	bool operator ==(const CHMap<K,V>& other) const {
		bool equal = this->size() == other.size() && this->m_aHashTable.length() == other.m_aHashTable.length();
		for (int i = 0; i < this->m_aHashTable.length() && equal; i++) {
			equal = *(this->m_aHashTable.getPtr(i)) == *(other.m_aHashTable.getPtr(i));
		}
		return equal;
	}
};

#if CHEL_CHMAP_HPP == 2
	#undef CHEL_CHMAP_HPP
	#define CHEL_CHMAP_HPP 1
	#define CHMap CHLiteralMap
#elif CHEL_CHMAP_HPP == 1
	#undef CHMap
	#undef CHEL_CHMAP_HPP
	#define CHEL_ARRAY_HPP 0
#endif

#endif //CHEL_CHMAP_HPP