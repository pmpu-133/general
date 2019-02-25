#pragma once //гарантия что этот код один раз будет в нашей проге - заголовочный файл - описание класса
//альтернатива #ifndef LISTH проверяем объявлена ли в проге эта уникальная последовательность символов
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
	inline void rewind(); // {current = first; }; - увеличивает скорость но и увеличивает объем программы, т.к. она вставляется в исполняемый код в месте вызова. inline (встраиваемый метод) - то же но короче. Выгодня для небольших объемов и часто вызываемых
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
