// lesson_18_project_part1.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include <iostream>

#include "objects.h"
#include "Architect.h"
#include "BMPRenderer.h"

#include "hasht.h"
#include "bintree.h"


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

/*bool testArchitectAddQuantity() {
	Architect ar;
	Id id = ar.addElement(1, 1);
	Array<Id> ids = ar.getALLIds();
	if (ids.Size() != 1) return false;
	if (ids[0] != id) return false;
	id = ar.addElement(1, 1);
	ids = ar.getALLIds();
	if (ids.Size() != 2) return false;

	return true;
}

bool testArchitectAddType() {
	Architect ar;
	Id id = ar.addElement(1, 1);
	Array<Id> ids = ar.getALLIds();
	if (ar.getObjTypeById(id) != FI_POINT) 
		return false;
	return true;
}*/
template<typename T> class simple_hasher {

  public:
    size_t operator()(const T&t) {
      unsigned char* dataptr = (unsigned char*)(&t);
      size_t res = 0;
      for (size_t k = 0; k < sizeof(T); ++k) {
        res += *dataptr;
        ++dataptr;
      }
      return res;
    }
  };

  class idhasher {
  public:
   /* size_t operator()(const Id&) {
      return 0;
    }*/
  };

int main() {

  bintree<int,double> b;
  b.AddData(4, 2.5);
  b.AddData(34, 23.5);
  b.AddData(2, 2.1);
  b.AddData(0, 4.5);
  b.AddData(-1, 0.5);
  b.AddData(8, 2);
  b.AddData(6, 100);
  b.print();
  cout << b.hasK(4) << endl;
  cout << b.hasK(34) << endl;
  cout << b.hasK(2) << endl; 
  cout << b.hasK(0) << endl;
  cout << b.hasK(-1) << endl;
  cout << b.hasK(8) << endl;
  cout << b.hasK(6) << endl;

  cout << b.hasK(7) << endl;
	/*hasht<point2> ha_point;
	hasht<section> ha_section;
	hasht<arc> ha_arc;

	for (int k = 0; k < 300; ++k)
		try {
		ha_point.AddData(k, point2());
	}
	catch(int) {
		cout << "Problem at " << k << endl;
	}

	ha_point.AddData(2, point2());
//	ha_point.hasK(2);




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

