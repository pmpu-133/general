#pragma once
#include "List.h"

class Architect {
public:
	void addElement(double x, double y); // �����
	void addElement(double x1, double y1, double x2, double y2); // �������
	void addElement(double x, double y,double r,double st,double fi); // ����
private:
	list<point2> m_PointStorage;
	list<section> m_SectionStorage;
	list<arc> m_ArcStorage;
};