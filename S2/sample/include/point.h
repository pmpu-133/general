//#ifndef POINT_H
//#define POINT_H
#pragma once
struct Vec{
    double x,y;
};

struct Point {
  double x;
  double y;
  const Point &operator+=(const Vec&v) {
    x += v.x; y += v.y;
    return *this;
  }
  bool operator==(const Point&p1) {
    return x == p1.x && y == p1.y;
  }
};

//#endif // POINT_H
