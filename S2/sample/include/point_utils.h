//#ifndef POINT_UTILS_H
//#define POINT_UTILS_H
#pragma once
#include <iostream>
#include "point.h"

std::ostream& operator<<(std::ostream& ost, const Point&p);

Point operator+(const Point&,const Vec&);


//endif //POINT_UTILS_H
