#pragma once

#include "arr.h"
#include "List.h"




template<typename K> size_t hasher(const K& k) {
	size_t res = k & 0xFF;
	for (int c = 1; c < sizeof(k); ++c)
		res += (k >> c) & 0xFF;
	return res;
}

template<typename K, 	typename V> 
	class
	hasht {

public:
	hasht() {
		m_Storage = Array<V*>(256);
		for (int c = 0; c < 256; ++c)
			m_Storage.changeValue(c, nullptr);
	}

	~hasht() {
		for (int i = 0; i < m_Storage.Size(); ++i)
			delete m_Storage[i];
		m_Storage.clear();
	}


	void AddData(const K& k, const V& value) {
		/*size_t cellind = hasher()(k); // Aaaaaaa!!
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

	/*bool hasK(const K& k)const {
		size_t cellind = hashfun(k);
		cellind %= 256;
		return m_Storage[cellind] == nullptr;
	}*/

	V operator[](const K& k)const {
		size_t cellind = hashfun(k);
		cellind %= 256;
		return *m_Storage[cellind];
	}

	
	

private:
	Array<V*> m_Storage;

};
