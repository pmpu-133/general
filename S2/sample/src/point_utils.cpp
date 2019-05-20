#include "stdafx.h"
#include "point_utils.h"


std::ostream& operator<<(std::ostream& ost, const Point&p){
  ost << '(' << p.x << ", " << p.y << ')';
  return ost;
}

Point operator+ (const Point&p, const Vec&v) {
  Point pnew(p);
  pnew += v;
  return pnew;
}
