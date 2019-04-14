#pragma once
#include <iostream>


using namespace std;


struct point2 {
  double x, y;
  point2() {
		x = 0;
		y = 0;
	}
  point2(double x1, double y1) {
		x = x1;
		y = y1;
	}
};

class section {
public:
  section() {
		point2 p(0, 0);
		*m_beg = p;
		*m_end = p;
	}
  section(const point2 &b, const point2 &e) {
		if ((b.x != e.x) && (b.y != e.y)) {
			*m_beg = b;
			*m_end = e;
		}
		else cout << "Wrong point data" << endl;
	}
  section(double x1, double y1, double x2, double y2) {
		if ((x1 != x2) && (y1 != y2)) {
			point2 beg(x1, y1);
			point2 end(x2, y2);
			*m_beg = beg;
			*m_end = end;
		}
		else cout << "Wrong point data" << endl;
	}

  point2* beg()const { return m_beg; }

  point2* end()const { return m_end; }

  void setBeg(const point2 &b) { *m_beg = b; }

  void setEnd(const point2 &e) { *m_end = e; }

private:
  point2 *m_beg;
  point2 *m_end;
};

class arc {
public:
  arc() {
		point2 Center(0, 0);
		*center = Center;
		m_r = 1;
		m_start = 0;
		m_finish = 360;
	}
  arc(const point2 &c, double r, double angs, double angf) {
		*center = c;
		if (r > 0)
			m_r = r;
		else cout << "Wrong radius data" << endl;
		if (abs(angs - angf) <= 360) {
			m_start = angs;
			m_finish = angf;
		}
		else cout << "Wrong angle data" << endl;
	}
  arc(double x, double y, double r, double angs, double angf) {
		point2 Center(x, y);
		*center = Center;
		if (r > 0)
			m_r = r;
		else cout << "Wrong radius data" << endl;
		if (abs(angs - angf) <= 360) {
			m_start = angs;
			m_finish = angf;
		}
		else cout << "Wrong angle data" << endl;
	}

  double r()const { return m_r; }

  double start()const { return m_start; }

  double finish()const { return m_finish; }
	
  point2* Center()const { return center; }

  void setR(const double &r) { m_r = r; }

  void setCenter(const point2& Center) { *center = Center; }

  void setStart(const double &st) { m_start = st; }

  void setFinish(const double &fi) { m_finish = fi; }

  point2* center;
private:
  double m_r;
  double m_start;
  double m_finish;
};