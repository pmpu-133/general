#pragma once
// вектор на плоскости
class Vec2
{
public:
	Vec2(double _x = 0, double _y = 0) :x(_x), y(_y) {}
	double getX()const { return x; }
	double getY()const { return y; }
	Vec2 sum(const Vec2& v) { 
		return Vec2(x + v.x, y + v.y);
	}
	//вместо этого - перегрузка операндов:
	Vec2 operator+(const Vec2& v) {
		return Vec2(x + v.x, y + v.y);
	}
	Vec2 operator*(const double a) {
		return Vec2(x*a, y*a);
	}
	Vec2 operator-(const Vec2& v) {
		return Vec2(x - v.x, y - v.y);
	}
private:
	double x;
	double y;
};

