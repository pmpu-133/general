#pragma once		
#include "objects.h"
#include "hasht.h"
#include "pch.h"



enum Situations {
  SI_2PCOINCIDE,					           //2 ����� ���������
  SI_P_ON_SECTION,			        		//����� ����������� �������? (��������������� � �������� �������)
  SI_P_ON_LINE,							         //����� ����������� ������, ���������� �������?
  SI_P_ON_ARC,								  //����� ����������� ����? (��������������� � �������� ����)
  SI_P_ON_CIRCLE,						    //����� ����������� ����������, ���������� ����?
  SI_2SECTIONS_PARAL,			            //2 ������� �����������
  SI_2SECTIONS_PERP,			      		//2 ������� ���������������
  SI_2SECTIONS_ON_LINE,					    //2 ������� ����� �� 1 ������ (����������)
  SI_2SECTIONS_ON_LINES_ANGLE,				//2 ������� �� ������, �������������� ��� �������� �����
  SI_2SECTIONS_SAME_LENGHT,					//2 ������ ����� ������ �����
  SI_SECTION_ON_LINE_TOUCH_ARC,				//������� ����� �� ������, ���������� ����������, ���������� ����
  SI_2ARCS_SAME_R,							//���� ����� ���������� ������
  SI_2ARCS_SAME_C				            //���� ������������ (����� 1 �����)
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
    //return pa.ID;
  };
 /* void deleteElement(const Id& id) {}

  Array<Id> getALLIds()const {};
  Figure getObjTypeById(const Id& id)const {};
  Array<double> getObjInfoById(const Id& id)const {};
  Array<Id> getChildIds(const Id&)const {};

  void location(Situations s1, const Array<Id> &objects) {};
  */

private:
  template<typename Data> struct para {
    /*Id*/int ID;
    Data data;
  };
	hasht< /*Id*/int, para<point2> >    m_Pointstorage;
	hasht< /*Id*/int, para<section> > m_sectionStorage;
	hasht< /*Id*/int, para<arc> >     m_acrstorage;

  struct SiInfo {
    Situations si;
    list</*Id*/int> elements;
  };
  list<SiInfo>  m_Situations;
	static int LastGiven;
  //list<para<list<SiInfo*> > >    m_Ele_Situations;

};