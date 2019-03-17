#pragma once
#include "List.h"

class Architect {
public:
	void addElement(double x, double y) {	
		point2 p(x,y);
		m_PointStorage.addData(p);
	}

	void addElement(double x1, double y1, double x2, double y2) {
		section s(x1,y1,x2,y2);
		m_SectionStorage.addData(s);
	}
	void addElement(double x, double y, double r, double st, double fi) {
		point2 p(x,y);
		arc a(p, r, st, fi);
		m_ArcStorage.addData(a);
	}
private:
	list<point2> m_PointStorage;
	list<section> m_SectionStorage;
	list<arc> m_ArcStorage;


};
