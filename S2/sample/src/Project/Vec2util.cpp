#include "Vec2util.h"

std::ostream& operator<< (std::ostream& ost, const Vec2&v) {
	ost << '(' << v.getX() << ',' << v.getY() << ')';
	return ost;
}