#pragma once

#include "arr.h"
#include "List.h"

template<typename T> class simple_hasher {
public:
  size_t operator()(const T&t) {
    unsigned char* p = (unsigned char*)&t;
    size_t res = 0;
    for (int k = 0; k < sizeof(T); ++k) {
      res += *p;
      ++p;
    }
    return res;
  }
};

class idhasher {
public:/*
  size_t operator()(const Id&) {
    return 0;
  }*/
};

template<typename K, typename V, typename hasher = simple_hasher<K> > class hasht {
public:
  hasht();
  ~hasht();
  void AddData(const K& k, const V&value); 
  bool hasK(const K& k)const;
  V operator[](const K&k)const;
  void validate() {
    size_t notNullCount = 0;
    for (size_t k = 0; k < m_Storage.Size(); ++k) {
      //std::cout << k << '\t' << m_Storage[k] << std::endl;
      if (m_Storage[k] != nullptr) ++notNullCount;
    }
    if (notNullCount != m_size)
      throw 42;
  };

private:
  Array<V*> m_Storage;
  size_t m_size;
};



template<typename K, typename V, typename hasher> hasht<K, V, hasher>::hasht() {
  m_Storage = Array<V*>(256);
  for (int c = 0; c < 256; ++c) {
    //std::cout << c << '\t' << m_Storage[c] << std::endl;
    m_Storage[c] = nullptr;
    //std::cout <<c << '\t' << m_Storage[c] << std::endl;
  }
  //std::cout << 0 << '\t' << m_Storage[0] << std::endl;
  m_size = 0;
  validate();
}


template<typename K, typename V, typename hasher> hasht<K, V, hasher>::~hasht() {
  for (int c = 0; c < 256; ++c)
    if (m_Storage[c] != nullptr)
      delete m_Storage[c];
}


template<typename K, typename V, typename hasher> void hasht<K, V, hasher>::AddData(const K& k, const V&value) {
  //std::cout << "--------------------" << std::endl;
  simple_hasher<K> t;
  size_t cellind = t(k);
  cellind %= 256;
  if (m_Storage[cellind] != nullptr) {
    size_t probe = (cellind + 1) % 256;
    while (probe != cellind && m_Storage[probe] != nullptr) {
      ++probe %= 256;

      //std::cout << "Probe " << probe << '\t' << (m_Storage[probe] != nullptr)  << std::endl;

    }
    if (m_Storage[probe] != nullptr)
      throw std::out_of_range("Table is full");

    cellind = probe;
  }

  m_Storage[cellind] = new V(value);
  ++m_size;
  validate();
}


template<typename K, typename V, typename hasher> bool hasht<K, V, hasher>::hasK(const K&k)const {
  simple_hasher<K> t;
  size_t cellind = t(k);
  cellind %= 256;
  V* v = m_Storage.getValue(cellind);
  return v == nullptr;
}


template<typename K, typename V, typename hasher> V hasht<K, V, hasher>::operator[](const K&k)const {
  simple_hasher<K> t;
  size_t cellind = t(k);
  cellind %= 256;
  return *m_Storage[cellind];
}
