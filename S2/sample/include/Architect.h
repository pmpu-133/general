#pragma once
#include "List.h"

enum Situations{
 SI_2PCOINCIDE,//2 ����� ���������
 SI_P_ON_SECTION, //����� ����������� �������? (��������������� � �������� �������)
 SI_P_ON_LINE, //����� ����������� ������, ���������� �������?
 SI_P_ON_ARC, //����� ����������� ����? (��������������� � �������� ����)
 SI_P_ON_CIRCLE, //����� ����������� ����������, ���������� ����?
 SI_2SECTIONS_PARAL, //2 ������� �����������
 SI_2SECTIONS_PERP, //2 ������� ���������������
 SI_2SECTIONS_ON_LINE, //2 ������� ����� �� 1 ������ (����������)
 SI_2SECTIONS_ON_LINES_ANGLE, //2 ������� �� ������, �������������� ��� �������� �����
 SI_2SECTIONS_SAME_LENGHT, //2 ������ ����� ������ �����
 SI_SECTION_ON_LINE__TOUCH_ARC, //������� ����� �� ������, ���������� ����������, ���������� ����
 SI_2ARCS_SAME_R, //���� ����� ���������� ������
 SI_2ARCS_SAME_C //���� ������������ (����� 1 �����)
};

enum Figure {
	FI_POINT,
	FI_SECTION,
	FI_ARC
};

class Architect {
public:
	void addElement(double x, double y) {
		point2 p(x,y);
		m_Pointstorage.addData(p);
	};//�����
	void addElement(double x, double y, double r, double st, double fi) {
		point2 c(x,y);
		arc a(c,r,st,fi);
		m_acrstorage.addData(a);
	};//����
	void addElement(double x1, double y1, double x2, double y2) {
		point2 beg(x1, y1);
		point2 end(x2, y2);
		section s(beg, end);
		m_sectionStorage.addData(s);
	};//�������

	//list<id> getALLIds()const;
	//Figure getObjTypeById(const id& );
	//list<double> getObjInfoById(const id&);
	//void location(Situations s1, const list<id> &objects);


private:
	list<point2> m_Pointstorage;
	list<section> m_sectionStorage;
	list<arc> m_acrstorage;
};