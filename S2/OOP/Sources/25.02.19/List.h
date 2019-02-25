#pragma once //�������� ��� ���� ��� ���� ��� ����� � ����� ����� - ������������ ���� - �������� ������
//������������ #ifndef LISTH ��������� ��������� �� � ����� ��� ���������� ������������������ ��������
//#define LISTH

#define Data double

struct cell {
	Data data;
	cell* next;
};


class list {
public:
	list();
	list(Data d);
	list(const list &original);
	~list();
	void clear();
	void addData(Data newdata);
	inline void rewind(); // {current = first; }; - ����������� �������� �� � ����������� ����� ���������, �.�. ��� ����������� � ����������� ��� � ����� ������. inline (������������ �����) - �� �� �� ������. ������� ��� ��������� ������� � ����� ����������
	/*Data getCurrent()const {
		if (current == nullptr)
			throw NoCurrent();
		return current->data;   
	}*/
	bool getCurrent(Data *pd)const;
	void moveNext();
	bool canMoveNext()const;

private:
	cell * first;
	cell * current;
	cell * last;
};
//#endif
