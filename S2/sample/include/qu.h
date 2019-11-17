#pragma once

#include "List.h"

template <typename T> class qu {
public:
 
  qu() {}

  ~qu() {}

  void print() {
    for (int i = 0; i < m_storage.Size(); ++i)
      cout << m_storage[i] << " ";
    cout << endl;
  }

  void push(const T& data) {
      m_storage.addData(data);
  }

  size_t size()const {
    return m_storage.Size();
  }

  bool empty()const {
    return m_storage.Size() == 0;
  }

  T getfirst() {
    if (!empty()) {
      T result = m_storage.getFirst();
      m_storage.deleteFirstElement();
      return result;
    }
    else 
      throw std::logic_error("Queue is empty!");
  }

private:
  list<T> m_storage;
};