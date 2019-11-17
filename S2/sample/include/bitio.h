#pragma once


template<typename Stream, size_t cachesize = 4> class bitwriter {
public:
  bitwriter() : m_numBitsToWrite(0), m_stream(nullptr) {}

  bitwriter(Stream *s) : m_numBitsToWrite(0) {
    if (s == nullptr)
      throw std::invalid_argument("Bad stream");
    m_stream = s;
  }

  ~bitwriter() {
   // if (m_numBitsToWrite > 0)
      //Zero unused bits in cache

     // Write bit buf bytes
     // m_stream->put(m_bitBuf);
  }

  void writebit(bool bi) {
    //add bi to bit cache
    m_bitBuf[m_numBitsToWrite / 8] | bi;
    m_bitBuf[m_numBitsToWrite / 8] = m_bitBuf[m_numBitsToWrite / 8] << 1;
    m_numBitsToWrite++;

    //if cache is full flush it ti stream
    if (m_numBitsToWrite == sizeof(m_bitBuf)*8) {
      for (int k = 0; k < sizeof(m_bitBuf); ++k)
        m_stream->put(m_bitBuf[k]);
      m_numBitsToWrite = 0;
    }
  }
private:
  unsigned char m_bitBuf[cachesize];
  Stream *m_stream;
  size_t m_numBitsToWrite;
};

template<typename Stream> class bitreader {
public:
  bitreader();
  ~bitreader();
  bool readbit();
private:

};