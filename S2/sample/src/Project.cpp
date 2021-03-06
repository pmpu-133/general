#include "stdafx.h"
//#include "pch.h"

#include <stdexcpt.h>
#include <iostream>

#include "Architect.h"

#include <fstream> 

#include <string> 

#include "stakk.h"
#include "qu.h"
#include "formula.h"

#include "2DimenArray.h"



using namespace std;

/*
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

class Base {
public:
  Base(int a) :m_a(a) {}
  ~Base() { cout << "Base object killed having a = " << m_a << endl; }
  operator int() { return m_a; }
  //private:
protected:
  int m_a;
};

class Sub : private Base {
public:
  Sub(int a ) : Base(a) {}
  virtual ~Sub() { cout << "Sub object killed with a = " << m_a << endl; }
  virtual void say() { cout << "Hello " << m_a + 2 << endl; }
};

class SubSup : public Sub {
public:
  SubSup(int a): Sub(a) {}
  ~SubSup() { cout << "Oh no! SubSup is killed! " << endl; }
  void write() { 
    cout << "Hello! I'm supreme!  " << 2 << endl; 
  }
  void say() {
    cout << "Hello! SupSub there  " << 2 << endl;
  }
};

Array<Sub*> giveMePleaseObjects() {
  Array<Sub*> objs(2);
  objs.changeValue(0, new Sub(45));
  objs.changeValue(1, new SubSup(34));
  return objs;
}

template<typename T> Array<T> reverse(const Array<T>& origi) {
  Array<T> original(origi);
  for (int k = 0; k < original.Size() / 2; ++k) {
    T tmp = original[k];
    original.changeValue(k, original.getValue(original.Size() - 1 - k));
    original.changeValue(original.Size() - 1 - k, tmp);
  }
  return original;
}


//Классы и методы стандартной библиотеки
#include <list>
#include <vector>

class StorageElement {
  StorageElement() {}
  int m_a;
public:
  StorageElement(int a): m_a(a) {} 
  StorageElement(const StorageElement & a) { m_a = a.m_a; }
  void operator=(const StorageElement &a) { m_a = a.m_a; }
  int get()const { return m_a; }
  bool operator< (const StorageElement &l)const { return m_a < l.m_a; }
};
ostream& operator<< (ostream& ost, const StorageElement& el) {
  ost << el.get();
  return ost;
}

template<typename stdcontainer> void process(const stdcontainer& cont) {
  for (typename stdcontainer::const_iterator ci = cont.begin(); ci != cont.end(); ++ci)
    cout << *ci << " ";
}

#include <stack>
#include <queue>

#include <map>

#include <set>

#include "stlsamples.h"

int main() {

  stlsample01();
  stlsample02();
  stlsample03();
  stlsample04();
  stlsample05();
  stlsample06();
  stlsample07();
  stlsample08();
  stlsample09();
  stlsample10();
  stlsample11();

  /*vector<StorageElement> v;
  v.push_back(StorageElement(3));
  vector<StorageElement> v1;
  v1.push_back(StorageElement(2));
  v1.push_back(StorageElement(23));
  v1[0] = 2;
  v1.at(0) = 22;
  v1 = v;
  std::list<StorageElement> s;
  s.push_back(StorageElement(2));
  s.push_front(StorageElement(2));
 

  process(s);
  process(v1);
  
  std::stack<int> st;
  st.push(2);
  st.top();
  st.pop();
    
  std::queue<int> qu;
  qu.push(12);
  int a  = qu.front();
  cout << a;
  qu.pop();
 
  

  std::deque<int> d;
  d.push_back(4);
  d.push_front(5);
  cout << d[0] << endl;


  map<int, double> i2d;
  i2d[2] = 3.14;
  i2d[3] = 2.71;
  map<StorageElement, int> se;
  se[StorageElement(3)] = 5;
  se[StorageElement(2)] = 6;

  map<StorageElement, int>::const_iterator ci = se.begin();
  while (ci != se.end()) {
    std::cout << ci->first  << " " << ci->second;
    ci++;
  }


  map<StorageElement, int>::const_iterator ciq = se.find(StorageElement(3));
  if (ciq != se.end())
    cout << ciq->first;
*/


 /* 
  Sub s(45);
  Sub* psub = &s;
  psub->say();


  SubSup ss(34);
  psub = &ss;
 */

  /*
  Array<Sub*> objs = giveMePleaseObjects();

  for (int i = 0; i < objs.Size(); ++i)
    objs[i]->say();

  cout << "Clear all objects \n" << endl;

  for (int i = 0; i < objs.Size(); ++i)
    delete objs[i];
 */

  /*try {
    evalTree tree;
    cout << tree.eval() << endl;
    tree.getUsualForm();
    cout << endl;
 }
  catch (runtime_error r) {
    cout << r.what() << endl;
  }*/

  /*
  string expression = "3+5*2-4/2";
  try {
    evalTree tree(expression);
    cout << tree.evalChar() << endl;
  }
  catch (runtime_error r) {
    cout << r.what() << endl;
  }
  catch (invalid_argument er) {
    cout << er.what() << endl;
  }
  */

  
  //int c = '3' - '0';

  /*
  char f[] = "(((5+7)*(2+2*2))/(((4/2)*4)+2*2))/6";   //((6+10-4)*5)/(1+1*2)+1
  qu<FormulaNode> inputQ, outputQ;

  FormulaParser< qu<FormulaNode> > parser;
  parser.setResult(&outputQ);
  parser.parse(f);
  

  outputQ.print();

  try {
    DijkstraSorter< qu<FormulaNode> > result;
    result.setInput(&outputQ);
    result.setOutput(&inputQ);

    result.run();

    cout << evaluate(inputQ) << endl;
   
  }
  catch (logic_error r1) {
    cout << r1.what() << endl;
  }
  catch (runtime_error r2) {
    cout << r2.what() << endl;
  }
  */


  TwoDimenArray<int> arr2dim;

  Array<int> ar;
  for (int k = 0; k < 5; ++k)
    ar.addData(k);

  Array<int> b = reverse(ar);

  /*
  Array<int> b = a;
  b.addData(3);
  Array<int> c(a = b);
  */

  /*
  Array<bool> ar;
  bool b = true;
  ar.setValue(0, b);



  try {
    fstream ifs("data.in");
    Array <para<unsigned char, size_t> > symbols_w_freqs = calcStats(ifs);
    HuffNode* root = buildHuffTree(symbols_w_freqs);
    AVLtree <unsigned char, Array<bool> >  tablE = tree2table(root);

    ifs.clear();
    ifs.seekg(0);

    
    ofstream fs("data.out");
    bitwriter <ofstream> bw(&fs);

    while (ifs) {
      unsigned char byt = ifs.get();
      Array <bool> &huffcode = tablE[byt];
      for (int k = 0; k < huffcode.Size(); ++k)
        bw.writebit(huffcode[k]);
    }
  }
  catch(invalid_argument &e) {
    cout << e.what() << endl;
  }



  AVLtree <int, double> b;


  
  hasht< int, double, double> ha_point;
  hasht< int, double, double > ha_section;
  hasht< int, double, double> ha_arc;

  for (int k = 0; k < 300; ++k)
    try {
    ha_point.AddData(k,2.5);
    }
  catch(int) {
    cout << "Problem at " << k << endl;
  }

  ha_point.AddData(2, 2.6);
  ha_point.hasK(2);/*

  BMPRenderer renderer("sample.bmp");
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