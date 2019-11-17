#pragma once

#include "arr.h"

template <typename T> class stakk {
public:

  stakk() {}

  ~stakk() {}

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
    return m_storage.isVoid();
  }

  T looktop()const {
    if (!empty())
      return  m_storage.getValue(m_storage.Size() - 1);
    else
      throw std::logic_error("Stack is empty!");
  }

  void pop() {
    if (!empty())
      m_storage.deleteElement(m_storage.Size() - 1);
    else
      throw std::logic_error("Stack is empty!");
  }

private:
  Array<T> m_storage;
};