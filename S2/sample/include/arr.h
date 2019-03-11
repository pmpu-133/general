#pragma once
#define Data double
class arr {
public:
	arr();
	arr(Data d);
	~arr();
	void clear();
	void addData(Data newdata);
	void rewind();
	bool getCurrent(Data *pd)const;
	void moveNext();
	bool canMoveNext()const;

	Data operator[](int ind);
private:
	Data * m_pData;
	size_t size;
	size_t cur;
};
