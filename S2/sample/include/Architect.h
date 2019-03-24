#pragma once
#include "List.h"
#include "arr.h"
#include "objects.h"



enum Situations {
  SI_2PCOINCIDE,					        //2 точки совпадают
  SI_P_ON_SECTION,			        	//точка принадлежит отрезку? (непосредственно в границах отрезка)
  SI_P_ON_LINE,					          //точка принадлежит прямой, содержащей отрезок?
  SI_P_ON_ARC,					          //точка принадлежит дуге? (непосредственно в границах дуги)
  SI_P_ON_CIRCLE,				          //точка принадлежит окружности, содержащей дугу?
  SI_2SECTIONS_PARAL,			        //2 отрезка параллельны
  SI_2SECTIONS_PERP,			      	//2 отрезка перпендикулярны
  SI_2SECTIONS_ON_LINE,			      //2 отрезка лежат на 1 прямой (выражается)
  SI_2SECTIONS_ON_LINES_ANGLE,	  //2 отрезка на прямых, пересекающихся под заданным углом
  SI_2SECTIONS_SAME_LENGHT,		    //2 отреза имеют равную длину
  SI_SECTION_ON_LINE_TOUCH_ARC,  //отрезок лежит на прямой, касающейся окружности, содержащей дугу
  SI_2ARCS_SAME_R,				        //Дуги имеют одинаковый радиус
  SI_2ARCS_SAME_C				          //Дуги концентричны (имеют 1 центр)
};

enum Figure {
  FI_POINT,
  FI_SECTION,
  FI_ARC
};

#define Id int

class Architect {
public:
  Id addElement(double x, double y) {
    point2 p(x, y);
    m_Pointstorage.addData(p);
  };
  Id addElement(double x, double y, double r, double st, double fi) {
    point2 c(x, y);
    arc a(c, r, st, fi);
    m_acrstorage.addData(a);
  };
  Id addElement(double x1, double y1, double x2, double y2) {
    point2 beg(x1, y1);
    point2 end(x2, y2);
    section s(beg, end);
    m_sectionStorage.addData(s);
  };
  void deleteElement(const Id& id) {}

  Array<Id> getALLIds()const {};
  Figure getObjTypeById(const Id& id)const {};
  Array<double> getObjInfoById(const Id& id)const {};
  Array<Id> getChildIds(const Id&)const {};

  void location(Situations s1, const Array<Id> &objects) {};


private:
  template<typename Data> struct para {
    Id ID;
    Data data;
  };
  list< para<point2> >  m_Pointstorage;
  list< para<section> > m_sectionStorage;
  list< para<arc> >     m_acrstorage;

  struct SiInfo {
    Situations si;
    list<Id> elements;
  };
  list<SiInfo>  m_Situations;
  //list<para<list<SiInfo*> > >    m_Ele_Situations;

};