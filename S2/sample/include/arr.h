#pragma once

#include "stdafx.h"
#include <iostream>

#include <stdexcpt.h>

template<typename Data> class Array {
public:
  Array() : arr(nullptr), size(0) {}
  Array(size_t n);
  Array(const Array &original);
  ~Array();
  
  const Array& operator=(const Array<Data>& original) {
    clear();
    size = original.size;
    arr = new Data[size];
    for (size_t i = 0; i < size; ++i)
      arr[i] = original.arr[i];
    return *this;
  }
  Data* getFirst();
  Data* getLast();

  class Pointer {
  public:
    Pointer(Array* arr) : first(arr->getFirst()), current(arr->getFirst()), last(arr->getLast()) {}
    void rewind();
    bool canMoveNext()const;
    bool canMoveBack()const;
    Pointer& operator++() {
      if (this->canMoveNext())
        current = current + 1;
      return *this;
    }
    Pointer& operator++(int) {
      if (this->canMoveNext())
        current = current + 1;
      return *this;
    }
    Pointer&operator--() {
      if (this->canMoveBack())
        current = current - 1;
      return *this;
    }
    Pointer& operator--(int) {
      if (this->canMoveBack())
        current = current - 1;
      return *this;
    }
    Data operator*();
    Data& operator=(const Data& data);
  private:
    Data * current;
    Data* last;
    Data* first;
  };
  
  void clear();
  void addData(Array a, Data data);
  size_t Size()const;
  Data getValue(size_t i)const;
  Data getLast()const {
    if (!isVoid())
      return *(arr + size - 1);
    else throw std::logic_error("No array");
  }
  void changeValue(size_t i, Data data);
  void printArray();
  bool isVoid()const;
  void deleteElement(size_t i);
  Data& operator[](int ind);
private:
  Data * arr; 
  size_t size;
};


template<> class Array<bool> {
public:
  Array() {
    arr = nullptr;
    size = 0;
  };
  Array(size_t n) {
    size = n;
    size_t asize = size / 8 + (size % 8) ? 1 : 0;
    arr = new unsigned char[asize];

    for (size_t i = 0; i < asize; ++i) {
      *(arr + i) = 0;
    }
  };
  Array(const Array &original) {
    size = original.size;
    size_t asize = size / 8 + (size % 8) ? 1 : 0;
    arr = new unsigned char[asize];
    for (size_t i = 0; i < asize; ++i)
      arr[i] = original.arr[i];
  };
  const Array& operator=(const Array<bool>&original) {
    if (arr != nullptr)
      delete[] arr;
    size = original.size;
    size_t asize = size / 8 + (size % 8) ? 1 : 0;
    arr = new unsigned char[asize];
    for (size_t i = 0; i < asize; ++i)
      arr[i] = original.arr[i];
    return *this;
  }
  ~Array() {
    clear();
  };
  /*
  class Pointer {
  public:
  Pointer(Array* arr) {
  first = arr->first();
  current = arr->first();
  last = arr->last();
  };
  void rewind() {
  current = first;
  };
  bool canMoveNext()const {
  if (current != nullptr)
  return current != last;
  return false;
  };
  bool canMoveBack()const {
  if (current != nullptr)
  return current != first;
  return false;
  };
  Pointer& operator++() {
  if (this->canMoveNext())
  current = current + 1;
  return *this;
  };
  Pointer& operator++(int) {
  if (this->canMoveNext())
  current = current + 1;
  return *this;
  };
  Pointer& operator--() {
  if (this->canMoveBack())
  current = current - 1;
  return *this;
  };
  Pointer& operator--(int) {
  if (this->canMoveBack())
  current = current - 1;
  return *this;
  };
  Data operator*() {
  if (current != nullptr)
  return *current;
  return -1;
  };
  Data& operator=(const Data& data) {
  *current = data;
  return *current;
  };
  private:
  Data * current;
  Data* last;
  Data* first;
  };*/
  void clear() {
    if (!isVoid())
      delete[] arr;
  };
  /*void addData(Array a, Data data) {
  Data* tmp = new Data[a.Size()];
  for (int i = 0; i < a.Size(); ++i)
  tmp[i] = a.getValue(i);
  arr = new Data[size + 1];
  for (int i = 0; i < a.Size(); ++i)
  arr[i] = tmp[i];
  arr[size] = data;
  size++;
  };
  Data* pointer()const {
  return arr;
  };*/
  size_t Size()const {
    return size;
  }
  void setValue(size_t i, bool data) {
    if (0 <= i && i < size)
      /*set correct bit */;
    else
      throw std::invalid_argument("Index values out of bounds");
  }
  bool isVoid()const {
    return size == 0;
  }
  /*
  void deleteElement(size_t i) {
  if (i < Size()) {
  for (int j = i; j < Size() - 1; ++j)
  *(arr + i) = *(arr + j + 1);
  size--;
  }
  };*/
  bool operator[](size_t ind)const {
    if (0 <= size && ind < size)
      return *(arr + ind);
    throw std::invalid_argument("Index values out of bounds");
  };
private:
  unsigned char * arr;
  size_t size;

};

template<typename Data> Array<Data>::Array(size_t n) {
  size = n;
  arr = new Data[size];
  for (size_t i = 0; i < size; ++i) {
    *(arr + i) = 0;
  }
}


template<typename Data> Array<Data>::Array(const Array &original) {
  size = original.Size();
  arr = new Data[size];
  for (size_t i = 0; i < size; ++i)
    *(arr + i) = original.getValue(i);
}


template<typename Data> Array<Data>::~Array() {
  clear();
}


template<typename Data> Data* Array<Data>::getFirst() {
  return arr;
}


template<typename Data> Data* Array<Data>::getLast() {
  return arr + this->size;
}


template<typename Data>  void Array<Data>::Pointer::rewind() {
  current = first;
}


template<typename Data> bool Array<Data>::Pointer::canMoveNext()const {
  if (current != nullptr)
    return current != last;
  return false;
}

 
template<typename Data> bool Array<Data>::Pointer::canMoveBack()const {
  if (current != nullptr)
    return current != first;
  return false;
}


template<typename Data> Data Array<Data>::Pointer::operator*() {
  if (current != nullptr)
    return *current;
  else throw std::invalid_argument("Index values out of bounds");
}


template<typename Data> Data& Array<Data>::Pointer::operator=(const Data& data) {
  *current = data;
  return *current;
}


template<typename Data> void Array<Data>::clear() {
  if (!isVoid())
    delete[] arr;
  else
    throw std::logic_error("No array");
}


template<typename Data> void Array<Data>::addData(Array a, Data data) {
  Data* tmp = new Data[a.Size()];
  for (int i = 0; i < a.Size(); ++i)
    tmp[i] = a.getValue(i);
  arr = new Data[size + 1];
  for (int i = 0; i < a.Size(); ++i)
    arr[i] = tmp[i];
  arr[size] = data;
  size++;
}


template<typename Data> size_t Array<Data>::Size()const {
  return size;
}


template<typename Data> Data Array<Data>::getValue(size_t i)const {
  if (0 <= i && i < size)
    return *(arr + i);
  else throw std::invalid_argument("Index values out of bounds");
}


template<typename Data> void Array<Data>::changeValue(size_t i, Data data) {
  if (0 <= i && i < size)
    *(arr + i) = data;
  else throw std::invalid_argument("Index values out of bounds");
}


template<typename Data> void Array<Data>::printArray() {
  if (arr)
    for (size_t i = 0; i < size; ++i)
      std::cout << *(arr + i) << " ";
  else std::cout << "No array" << std::endl;
}


template<typename Data> bool Array<Data>::isVoid()const {
  return size == 0;
}


template<typename Data> void Array<Data>::deleteElement(size_t i) {
  if (0 <= i && i < size) {
    for (int j = i; j < size - 1; ++j)
      *(arr + j) = *(arr + j + 1);
    size--;
  }
  else 
    throw std::invalid_argument("Index values out of bounds");
}


template<typename Data> Data& Array<Data>::operator[](int ind) {
  if ((ind < size) && (ind > -1))
    return *(arr + ind);
  throw std::invalid_argument("Index values out of bounds");
}