#include "pch.h"
#include "Array.h"
#include <iostream>

using namespace std;

Array::Array() {
  arr = nullptr;
  size = 0;
}
Array::Array(size_t n) {
  size = n;
  arr = new Data[size];
  for (size_t i = 0; i < size; ++i) {
    *(arr + i) = 0;
  }
}
Array::Array(const Array &original) {
  size = original.Size();
  arr = new Data[size];
  for (size_t i = 0; i < size; ++i)
    *(arr + i) = original.getValue(i);
}
Array::~Array() {
  clear();
}
Data* Array::first() {
  return arr;
}
Data* Array::last() {
  return arr + this->size;
}
Array::Pointer::Pointer(Array* arr) {
  first = arr->first();
  current = arr->first();
  last = arr->last();
}
void Array::Pointer::rewind() {
  current = first;
}

bool Array::Pointer::canMoveNext()const {
  if (current != nullptr)
     return current != last;
  return false;
    
}
bool Array::Pointer::canMoveBack()const {
  if (current != nullptr)
    return current != first;
  return false;
}
Array::Pointer& Array::Pointer::operator++() {
  if (this->canMoveNext())
    current = current + 1;
  return *this;
}
Array::Pointer& Array::Pointer::operator++(int) {
  if (this->canMoveNext())
    current = current + 1;
  return *this;
}
Array::Pointer& Array::Pointer::operator--() {
  if (this->canMoveBack())
    current = current - 1;
  return *this;
}
Array::Pointer& Array::Pointer::operator--(int) {
  if (this->canMoveBack())
    current = current - 1;
  return *this;
}
Data& Array::Pointer::operator=(const Data& data) {
    *current = data;
  return *current;
}

Data Array::Pointer::operator*() {
  if (current != nullptr)
    return *current;
  return -1;
}

void Array::clear() {
  if (!isVoid())
    delete[] arr;
}
void Array::addData(Array a, Data data) {
  Data* tmp = new Data[a.Size()];
  for (int i = 0; i < a.Size(); ++i)
    tmp[i] = a.getValue(i);
  arr = new Data[size + 1];
  for (int i = 0; i < a.Size(); ++i)
    arr[i] = tmp[i];
  arr[size] = data;
  size++;
}
Data* Array::pointer()const {
  return arr;
};
size_t Array::Size()const {
  return size;
}
Data Array::getValue(size_t i)const {
  if (i < size)
    return *(arr + i);
}
void Array::changeValue(size_t i, Data data) {
  if (i < Size())
    *(arr + i) = data;
}
void Array::printArray() {
  for (size_t i = 0; i < Size(); ++i)
    cout << *(arr + i) << " ";
}
bool Array::isVoid() const {
  return Size() == 0;
};
void Array::deleteElement(size_t i) {
  if (i < Size()) {
    for (int j = i; j < Size() - 1; ++j)
      *(arr + i) = *(arr + j + 1);
    size--;
  }
}
Data Array::operator[](int ind) {
  if ((ind < size) && (ind > -1))
    return *(arr + ind);
  return -123452;
}
 