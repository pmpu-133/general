#pragma once		
#include "objects.h"
#include "hasht.h"



enum Situations {
  SI_2PCOINCIDE,					             //2 точки совпадают
  SI_P_ON_SECTION,			        		   //точка принадлежит отрезку? (непосредственно в границах отрезка)
  SI_P_ON_LINE,							           //точка принадлежит прямой, содержащей отрезок?
  SI_P_ON_ARC,								         //точка принадлежит дуге? (непосредственно в границах дуги)
  SI_P_ON_CIRCLE,						           //точка принадлежит окружности, содержащей дугу?
  SI_2SECTIONS_PARAL,			             //2 отрезка параллельны
  SI_2SECTIONS_PERP,			      		   //2 отрезка перпендикулярны
  SI_2SECTIONS_ON_LINE,					       //2 отрезка лежат на 1 прямой (выражается)
  SI_2SECTIONS_ON_LINES_ANGLE,				 //2 отрезка на прямых, пересекающихся под заданным углом
  SI_2SECTIONS_SAME_LENGHT,					   //2 отреза имеют равную длину
  SI_SECTION_ON_LINE_TOUCH_ARC,				 //отрезок лежит на прямой, касающейся окружности, содержащей дугу
  SI_2ARCS_SAME_R,							       //Дуги имеют одинаковый радиус
  SI_2ARCS_SAME_C				               //Дуги концентричны (имеют 1 центр)
};

enum Figure {
  FI_POINT,
  FI_SECTION,
  FI_ARC
};

//#define Id Array<char>

class Architect {
public:
  /*Id*/ void addElement(double x, double y) {
    point2 p(x, y);
    para<point2> pa;
    pa.ID = LastGiven++;
    pa.data = p;
    m_Pointstorage.AddData(pa.ID, pa);
    // return pa.ID;
  };
  /*Id*/ void addElement(double x, double y, double r, double st, double fi) {
    point2 c(x, y);
    arc a(c, r, st, fi);
    para<arc> pa;
    pa.ID = LastGiven++;
    pa.data = a;
    m_acrstorage.AddData(pa.ID, pa);
    para<point2> par;
    par.ID = LastGiven++;
    par.data = c;
    m_Pointstorage.AddData(par.ID, par);
    //return pa.ID;
  };
  /*Id*/ void addElement(double x1, double y1, double x2, double y2) {
    point2 beg(x1, y1);
    point2 end(x2, y2);
    section s(beg, end);
    para<section> pa;
    pa.ID = LastGiven++;
    pa.data = s;
    m_sectionStorage.AddData(pa.ID, pa);
    para <point2> par;
    par.ID = LastGiven++;
    par.data = beg;
    m_Pointstorage.AddData(par.ID, par);
    para<point2> par2;
    par2.ID = LastGiven++;
    par2.data = end;
    m_Pointstorage.AddData(par2.ID, par2);
    //return pa.ID;
  };

  void deleteElement(const int& id){}
  /* Array<Id> getALLIds()const {};
  Figure getObjTypeById(const Id& id)const {};
  Array<double> getObjInfoById(const Id& id)const {};
  Array<Id> getChildIds(const Id&)const {};
  void location(Situations s1, const Array<Id> &objects) {};
  */

private:
  template<typename Data> struct para {
    /*Id*/int ID;
    Data data;

    para() {};
    para(int c) {
      int ID = c;
    }

    bool operator==(Data data) {
      if (data.Id == this.Id)
        return true;
      else
        return false;
    }

  };
  hasht< /*Id*/int, para<point2>, double >    m_Pointstorage;
  hasht< /*Id*/int, para<section>, double> m_sectionStorage;
  hasht< /*Id*/int, para<arc>, double>     m_acrstorage;

  struct SiInfo {
    Situations si;
    list</*Id*/int> elements;
  };
  list<SiInfo>  m_Situations;
  static int LastGiven;
  list<para<list<SiInfo*> > >    m_Ele_Situations;
};