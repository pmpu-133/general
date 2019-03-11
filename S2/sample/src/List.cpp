#include "List.h"


/*
template<typename Data> list<Data>::Pointer list::getFirstPtr() {
	Pointer p(*this);
	return p;
}
Data list::Pointer::getCurrent()const { 
	return current->data; 
}

template<typename Data> Data list::Pointer::operator*()const {
	return current->data;
}
template<typename Data> void list::Pointer::rewind() {
	current = first;
}
//void list::Pointer::moveNext() { current = current->next; }
template<typename Data> list<Data>::Pointer& list::Pointer::operator++() {
	current = current->next; 
	return *this;
}
template<typename Data> list<Data>::Pointer list::Pointer::operator++(int) {
	Pointer result(*this);
	current = current->next; 
	return result;
}
template<typename Data> bool list<Data>::Pointer::canMoveNext()const {
	if (current != nullptr)
		return current->next != nullptr;
	return false;
};
*/