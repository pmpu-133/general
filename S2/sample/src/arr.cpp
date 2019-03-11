#include "arr.h"


arr::arr() {
	m_pData = nullptr;
	size = 0;
	cur = 0;
}
/*
arr(Data d) {
	m_pData = new Data[1];
	size = 1;
	cur = 0;
}

~arr() {
	//std::cout << "Destructor called" << std::endl;
	clear();
}


void clear() {
}

void addData(Data newdata) {
}
void rewind() { current = first; }
Data getCurrent()const {
	if (current == nullptr)
		throw NoCurrent();
	return current->data;
}

bool getCurrent(Data *pd)const {
	if (current != nullptr) {
		*pd = current->data;
		return true;
	}
	else return false;
}

void moveNext() { current = current->next; }
bool canMoveNext()const {
	if (current != nullptr)
		return current->next != nullptr;
	return false;
};
*/