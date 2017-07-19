#ifndef CHEL_MAP_H
#define CHEL_MAP_H

#include "../Lists/CDynList.hpp"

template<class K, class V>
struct SMapPair {
private:
	K m_key;
	V m_value;
public:
	SMapPair() {}
	SMapPair(K key, V value) {
		m_key = key; m_value = value;
	}
	inline K key() const { return m_key; }
	inline V value() const { return m_value; }
};

/**
 * @class CMap
 * @author Awesome
 * @date 28/05/2017
 * @file CMap.h
 * @brief Maps keys to values, like a dictionary.
 * 		Uniqueness of keys must be enforced by client.
 */
template<class K, class V> class CMap {
private:	
	CDynList<SMapPair<K, V>> m_map;
	
public:
	/**
	 * @brief Checks whether or not the given key is
	 * 		already contained in the map
	 * @param key - the key to look for
	 * @return - the given key's presence
	 */
	bool hasKey(K key) const;
	
	/**
	 * @brief Checks whether or not the given value is
	 * 		contained in the map
	 * @param value - the value to look for
	 * @return - whether or not it's present
	 */
	bool hasValue(V value) const;

	/**
	 * @brief Adds a key value pair to the map
	 * @param key - the unique key to add
	 * @param value - the value to that's binded to the key
	 * @requires - the given key is not already in the map
	 */
	void add(K key, V value);
	
	/**
	 * @brief Removes the given key from the map
	 * @param key - the key to remove
	 * @return - the value associated with the key
	 */
	V remove(K key);
	
	/**
	 * @brief Removes all keys from the map
	 */
	void flush();
	
	/**
	 * @brief Finds the value associated with the given key
	 * @param key - the key whose value to find
	 * @return - the value bound to the key
	 * @requires - the key exists in the map
	 */
	V value(K key) const;
	
	/**
	 * @brief Finds the first key bound to the given value
	 * @param value - the value to look for
	 * @return - the key bound to the value
	 */
	K key(V value) const;
	
	/**
	 * @brief 
	 * @return 
	 */
	inline int size() const { return m_map.length(); }
	
	/**
	 * @brief Reserves space on the heap for the given number
	 * 		of key-value pairs.
	 * @perf - This is already done automatically, but doing
	 * 			it manually can improve performance
	 * @param iNumPairs - the number of pairs to allocate for
	 */
	inline void reserve(int iNumPairs) { m_map.reserve(iNumPairs); }
	
	inline K keyByIndex(int index) const { return m_map.get(index).key(); }
	
	inline V valueByIndex(int index) const { return m_map.get(index).value(); }
	
	inline int indexOfKey(K key) const { 
		int result = -1;
		for (int i = 0; i < m_map.length(); i++) {
			if (m_map.get(i).key() == key) {
				result = i;
				break;
			}
		}
		return result;
	}
};

#endif //CHEL_MAP_H