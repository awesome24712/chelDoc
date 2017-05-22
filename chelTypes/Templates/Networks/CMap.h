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

template<class K, class V>
class CMap {
private:	
	CDynList<SMapPair<K, V>> m_map;
	
public:
	bool hasKey(K key) const;
	bool hasValue(V value) const;

	void add(K key, V value);
	V remove(K key);
	
	V value(K key) const;
	K key(V value) const;
	
	inline int size() const { return m_map.length(); }
	inline void reserve(int iNumPairs) { m_map.reserve(iNumPairs); }
};

#endif //CHEL_MAP_H