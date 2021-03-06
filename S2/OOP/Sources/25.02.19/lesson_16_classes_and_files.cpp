// lesson_16_classes_and_files.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Vec2.h"
#include "Vec2util.h"

#include "List.h"
#include "Storage.h"

#include "Array.h"

using namespace std;



int main()
{
	Vec2 v1(3, 4);
	Vec2 v2(2, 3);
	double a = 2;
	cout << " Sum . x = " << v1.sum(v2).getX() << endl;
	cout << " Sum . x = " << (v1 + v2).getX() << endl;
	cout << " Sum . x = " << v1.operator+(v2).getX() << endl;
	cout << " Sum . x = " << v1 + v2 << endl;
	cout << "v2*a = " << v2 * a << endl;
	cout << "v1 - v2 = " << v1 - v2 << endl;


    return 0;
}

