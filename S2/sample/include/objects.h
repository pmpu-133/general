#pragma once
#include <iostream>
#include "pch.h"



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

class section  {
public:
  section() {
    point2 p(0, 0);
    m_beg = p;
    m_end = p;
  }

  section(const point2 &b, const point2 &e) {
    if ((b.x != e.x) && (b.y != e.y)) {
      m_beg = b;
      m_end = e;
    }
    else std::cout << "Wrong point data" << std::endl;
  }

  section(double x1, double y1, double x2, double y2) {
    if ((x1 != x2) && (y1 != y2)) {
      m_beg.x = x1;
      m_beg.y = y1;
      m_end.x = x2;
      m_end.y = y2;
    }
    else std::cout << "Wrong point data" << std::endl;
  }

  point2 beg()const { return m_beg; }

  point2 end()const { return m_end; }

  void setBeg(const point2 &b) { m_beg = b; }

  void setEnd(const point2 &e) { m_end = e; }

private:
  point2 m_beg;
  point2 m_end;
};

class arc {
public:
  arc() {
    center.x = 0;
    center.y = 0;
    m_r = 0;
    m_start = 0;
    m_finish = 0;
  }

  arc(const point2 &c, double r, double angs, double angf) {
    center = c;
    if (r > 0)
      m_r = r;
    else std::cout << "Wrong radius data" << std::endl;
    if (abs(angs - angf) <= 360) {
      m_start = angs;
      m_finish = angf;
    }
    else std::cout << "Wrong angle data" << std::endl;
  }

  arc(double x, double y, double r, double angs, double angf) {
    center.x = x;
    center.y = y;
    if (r > 0)
      m_r = r;
    else std::cout << "Wrong radius data" << std::endl;
    if (abs(angs - angf) <= 360) {
      m_start = angs;
      m_finish = angf;
    }
    else std::cout << "Wrong angle data" << std::endl;
  }

  double r()const { return m_r; }

  double start()const { return m_start; }

  double finish()const { return m_finish; }

  void setR(const double &r) { m_r = r; }

  void setStart(const double &st) { m_start = st; }

  void setFinish(const double &fi) { m_finish = fi; }

  point2 center;			
private:
  double m_r;				 
  double m_start;			
  double m_finish;		
};