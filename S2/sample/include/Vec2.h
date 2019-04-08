#pragma once
#include <iostream>

class Vec2
{
public:
	Vec2(double _x = 0, double _y = 0) :x(_x), y(_y), m_id(lastGiven++) {
	}
	double getX()const { return x; }
	double getY()const { return y; }
	Vec2 operator+(const Vec2& v) {
		return Vec2(x + v.x, y + v.y);}
	Vec2 operator-(const Vec2& v) {
		return Vec2(x - v.x, y - v.y);
	}
	Vec2 operator-() {
		return Vec2(-x, -y);
	}

	Vec2 operator*(double d) {
		return Vec2(d*x, d*y);
	}
	int getID()const { 
		std::cout << "Now lastgiven " << lastGiven << std::endl;
		return m_id; 
	}

private:
	double x;
	double y;
	int m_id;

	static int lastGiven;
};

