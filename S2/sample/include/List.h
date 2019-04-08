#pragma once
#include "stdafx.h"

template<typename Data> class list {
public:
	list() {
		first = nullptr;
		last = nullptr;
	}

	list(Data d) {
		first = nullptr;
		last = nullptr;
		addData(d);
	}

	list(const list &original) {
		first = nullptr;
		last = nullptr;
		if (original.first != nullptr) {
			cell* tmp1 = original.first;
			while (tmp1 != nullptr) {
				addData(tmp1->data);
				tmp1 = tmp1->next;
			}
		}
	}

	~list() {
		clear();
	}

	void operator=(const list<Data>& original) {
		clear();
		first = nullptr;
		last = nullptr;
		if (original.first != nullptr) {
			cell * tmp = original.first;
			while (tmp != nullptr) {
				addData(tmp->data);
				tmp = tmp->next;
			}
		}
	}

	struct cell {
		Data data;
		cell* next;
		cell* prev;
	};


	void clear() {
		list::Pointer pointer = this->getFirstPtr();
		while (pointer.canMoveNext()) {
			cell* toDelete = pointer.currentPos();
			pointer++;
			delete toDelete;
		}
	}

	class Pointer {
	public:
		Pointer(list &li) {
			current = li.first;
			first = li.first;
		}

		void rewind() {
			current = first;
		}

		Data operator*()
		{
			if (current == nullptr)
				return -1;
			return current->data;
		}

		Pointer& operator++()
		{
			current = current->next;
			return *this;
		}

		Pointer& operator++(int)
		{
			Pointer result(*this);
			current = current->next;
			return result;
		}

		Pointer& operator--()
		{
			if (current->prev != nullptr)
				current = current->prev;
			return *this;
		}

		Pointer& operator--(int) {
			Pointer result(*this);
			current = current->prev;
			return result;
		}

		bool canMoveNext()const {
			if (current != nullptr)
				return current->next != nullptr;
			return false;
		}

		bool canMoveBack()const {
			if (current != nullptr)
				return current->prev != nullptr;
			return false;
		}
		cell* currentPos()const {
			return this->current;
		}
	private:
		cell * current;
		cell * first;
	};

	void addData(Data newdata) {
		cell* newcell = new cell;
		newcell->data = newdata;
		newcell->next = nullptr;
		newcell->prev = nullptr;

		if (first == nullptr) {
			first = newcell;
			last = newcell;
		}
		else {
			last->next = newcell;
			newcell->prev = last;
			last = newcell;
		}
	}

	Pointer getFirstPtr() {
		Pointer p(*this);
		return p;

	}

	bool ContainsId(int id) {
		Pointer p(this);
		Data checker(id);
		while ((*p != checker) || (p != nullptr))
			p++;
		if (p == nullptr) return false;
		else return true;
	}

private:
	cell * first;
	cell * last;
};
