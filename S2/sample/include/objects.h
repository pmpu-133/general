#pragma once

struct point2 {
	double x, y;
};

class section {
public:
	section(const point2 &b,const point2 &e);
	section(double x1,double y1, double x2, double y2);
	point2 beg()const { return m_beg; }
	point2 end()const { return m_end; }
	void setBeg(const point2 &b);
	void setEnd(const point2 &e);
private:
	point2 m_beg;
	point2 m_end;
};

class arc {
public:
	arc(const point2&c, double r, double angs, double angf);
	// дописать методы	!!!
	point2 center; // центр
private:
	double m_r; // радиус
	double m_start; // угол начала, в градусах
	double m_finish; // угол окончания, в градусах
};

