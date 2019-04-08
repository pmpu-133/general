#pragma once

#include <windows.h>
#include <fstream>

class BMPRenderer{
public:
	BMPRenderer(const char*filename);
	void setWidth(size_t);
	void setHeight(size_t);
	
	void draw(double x,double y);
	void draw(double x1, double y1, double x2, double y2);
	void draw(double x, double y, double r, double st, double fi); // дуга

	~BMPRenderer();
private:
	std::ofstream m_fs;
	BITMAPFILEHEADER m_bmfh;
	BITMAPINFOHEADER m_bmih;
	unsigned char *m_pPixels;
};

