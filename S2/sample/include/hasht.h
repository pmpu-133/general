#pragma once

#include "arr.h"
#include "List.h"




unsigned int RSHash(const char* str, unsigned int length)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < length; ++str, ++i)
	{
		hash = hash * a + (*str);
		a = a * b;
	}

	return hash;
}

template<typename K, 	typename V> class hasht {

public:
	hasht() {
		m_Storage = Array<V*>(256);
		for (int c = 0; c < 256; ++c)
			m_Storage.changeValue(c, nullptr);
	}

	~hasht() {
		for (int i = 0; i < m_Storage.Size(); ++i)
			if (m_Storage[i] != nullptr) 
        delete m_Storage[i];
		m_Storage.clear();
	}


	void AddData(const K& k, const V& value) {
/*    size_t cellind = hasher<K>(k);
		cellind %= 256;
		if (m_Storage[cellind] != nullptr){
			size_t probe = (cellind + 1) % 256;
		while (probe != cellind && m_Storage[cellind] != nullptr)
			++probe %= 256;
		if (m_Storage[probe] != nullptr)
			throw 42;
		cellind = probe;
	}
	m_Storage.changeValue(cellind, new V(value));*/
}

/*	bool hasK(const K& k)const {
		size_t cellind = hasher<K>(k);
		cellind %= 256;
		return m_Storage[cellind] == nullptr;
	}*/

	V operator[](const K& k)const {
		size_t cellind = hasher<K>(k);
		cellind %= 256;
		return *m_Storage[cellind];
	}

	
private:
	Array<V*> m_Storage;

};
