
#include "stdafx.h"
#include <iostream>

#include "objects.h"
#include "Architect.h"
#include "BMPRenderer.h"


using namespace std;


class SampleOne {
public:
  int generateID() { return 0; };
  static SampleOne* getSampleOne() {
    if (_one == nullptr) _one = new SampleOne();
    return _one;
  }
private:
  SampleOne() {};
  static SampleOne *_one;

};

SampleOne *SampleOne::_one = nullptr;

bool testArchitectAddQuantity() {
  Architect ar;
  Id id = ar.addElement(1, 1);
  Array<Id> ids = ar.getAllIds();
  if (ids.Size() != 1) return false;
  if (ids[0] != id) return false;
  id = ar.addElement(1, 1);
  ids = ar.getAllIds();
  if (ids.Size() != 2) return false;

  return true;
}

bool testArchitectAddType() {
  Architect ar;
  Id id = ar.addElement(1, 1);
  Array<Id> ids = ar.getAllIds();
  if (ar.getObjTypeById(id) != FI_POINT)
    return false;
  return true;
}


int main() {

  /*BMPRenderer renderer("sample.bmp");
  for (int k = 0; k < 100; ++k)
    renderer.draw(k, 4);

  Architect ar;
  ar.addElement(4, 5.6);
  ar.addElement(4, 5.6, 3, 5.4);
  ar.addElement(4, 5.6, 3, 5.4, 2.5);
  point2 p;
  p.id = 12;



  list<int> l1(1);
  list<int> l2(2);
  list<int> l3(3);
  l1 = l2 = l3;
  list<int>::Pointer p1(l1);
  list<int>::Pointer p2(l2);

  cout << *p1 << " " << *p2 << endl;*/


  return 0;
}

