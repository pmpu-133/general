
#include "BMPRenderer.h"


BMPRenderer::BMPRenderer(const char*filename){
	m_fs.open(filename, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
	if (!m_fs.is_open())
		throw std::invalid_argument("Can't open BMP file");
	// Fill in bitmap file header
	m_bmfh.bfType = 0x4d42;
	m_bmfh.bfOffBits = sizeof(m_bmfh) + sizeof(m_bmih);//  +++


	// Fill in bitmap info header
	m_bmih.biSize = sizeof(m_bmih);
	m_bmih.biBitCount = 1;
	m_bmih.biHeight = 1024;
	m_bmih.biWidth = 768;
	m_bmih.biCompression = BI_RGB;

	// +++
	
	// pixel data
	m_pPixels = new unsigned char[m_bmih.biHeight*m_bmih.biWidth / 8];
}
void BMPRenderer::draw(double x, double y) {
	int r = static_cast<int>(y);
	int c = static_cast<int>(x);
	m_pPixels[(r*m_bmih.biWidth + c) % 8] |= (1 << c);
}

BMPRenderer::~BMPRenderer(){

	m_fs.write((char*)&m_bmfh, sizeof(m_bmfh));
	m_fs.write((char*)&m_bmih, sizeof(m_bmih));
	m_fs.write((char*)m_pPixels, m_bmih.biHeight*m_bmih.biWidth / 8);
	m_fs.close();
	delete[]  m_pPixels;
}
