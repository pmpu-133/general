#pragma once
#include "List.h"

enum Situations{
 SI_2PCOINCIDE,//2 точки совпадают
 SI_P_ON_SECTION, //точка принадлежит отрезку? (непосредственно в границах отрезка)
 SI_P_ON_LINE, //точка принадлежит прямой, содержащей отрезок?
 SI_P_ON_ARC, //точка принадлежит дуге? (непосредственно в границах дуги)
 SI_P_ON_CIRCLE, //точка принадлежит окружности, содержащей дугу?
 SI_2SECTIONS_PARAL, //2 отрезка параллельны
 SI_2SECTIONS_PERP, //2 отрезка перпендикулярны
 SI_2SECTIONS_ON_LINE, //2 отрезка лежат на 1 прямой (выражается)
 SI_2SECTIONS_ON_LINES_ANGLE, //2 отрезка на прямых, пересекающихся под заданным углом
 SI_2SECTIONS_SAME_LENGHT, //2 отреза имеют равную длину
 SI_SECTION_ON_LINE__TOUCH_ARC, //отрезок лежит на прямой, касающейся окружности, содержащей дугу
 SI_2ARCS_SAME_R, //Дуги имеют одинаковый радиус
 SI_2ARCS_SAME_C //Дуги концентричны (имеют 1 центр)
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
	};//точка
	void addElement(double x, double y, double r, double st, double fi) {
		point2 c(x,y);
		arc a(c,r,st,fi);
		m_acrstorage.addData(a);
	};//дуга
	void addElement(double x1, double y1, double x2, double y2) {
		point2 beg(x1, y1);
		point2 end(x2, y2);
		section s(beg, end);
		m_sectionStorage.addData(s);
	};//отрезок

	//list<id> getALLIds()const;
	//Figure getObjTypeById(const id& );
	//list<double> getObjInfoById(const id&);
	//void location(Situations s1, const list<id> &objects);


private:
	list<point2> m_Pointstorage;
	list<section> m_sectionStorage;
	list<arc> m_acrstorage;
};