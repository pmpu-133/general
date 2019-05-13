#pragma once


#include "arr.h"


template<typename Data> class TwoDimenArray{
public:
  TwoDimenArray() : m_arr(nullptr), m_lines(0), m_columns(0) {}
  TwoDimenArray(size_t lin, size_t col) {
    if (lin >= 0 && col >= 0) {
      m_arr = new Array<Data>* [col];
      for (int i = 0; i < col; ++i)
        m_arr[i] = new Data[lin];
      m_lines = lin;
      m_columns = col;
    }
    else
      throw std::logic_error("Negative size of Array");
  }
  TwoDimenArray(const TwoDimenArray &original) {

  }

  ~TwoDimenArray() {
    if (m_arr) {
      for (int i = 0; i < m_columns; ++i)
        if (m_arr[i])
          delete[] m_arr[i];
      delete[] m_arr;
    }
  }
  void clear() {

  }
private:
  Array<Data> **m_arr;
  size_t m_lines;
  size_t m_columns;
};