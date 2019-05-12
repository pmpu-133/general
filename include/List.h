#pragma once
#include <iostream>
#include <stdexcpt.h>

template<typename Data> class list {
public:
	list() : first(nullptr), last(nullptr), size(0) {}
	list(Data d) {
		size = 0;
		first = nullptr;
		last = nullptr;
		addData(d);
	}
	list(const list& original) {
		size = 0;
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
	size_t Size()const {
		return size;
	}
	Data getFirst() {
		if (this->Size() > 0)
			return first->data;
		else
			throw std::logic_error("List is empty!");
	}
	void deleteFirstElement() {
		cell* tmp = first;
		first = first->next;
		delete tmp;
		size--;
	}

	void operator=(const list<Data>& original) {
		clear();
		first = nullptr;
		last = nullptr;
		if (original.first != nullptr) {
			cell* tmp = original.first;
			while (tmp != nullptr) {
				addData(tmp->data);
				tmp = tmp->next;
			}
		}
	}
	Data operator[](int ind) {
		if ((ind < size) && (ind > -1)) {
			Pointer tmp(*this);
			if (ind == 0)
				return *tmp;
			for (int i = 0; i < ind; ++i)
				tmp++;
			return *tmp;
		}

		throw std::invalid_argument("Index values out of bounds");
	}
	struct cell {
		Data data;
		cell* next;
		cell* prev;
	};

	void clear() {
		list::Pointer pointer = this->getFirstPtr();
		while (pointer.canMoveNext()) {
			cell* toDelete = pointer.getCurrentPtr();
			pointer++;
			delete toDelete;
		}
	}

	class Pointer {
	public:
		Pointer(list& li) : current(li.first), first(li.first) {}

		void rewind() {
			current = first;
		}
		Data operator*() {
			if (current == nullptr)
				throw std::invalid_argument("No data");
			return current->data;
		}
		Pointer& operator++() {
			current = current->next;
			return *this;
		}
		Pointer& operator++(int) {
			Pointer result(*this);
			current = current->next;
			return result;
		}
		Pointer& operator--() {
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

		cell* getCurrentPtr()const {
			return this->current;
		}

	private:
		cell* current;
		cell* first;
	};

	Pointer getFirstPtr() {
		Pointer p(*this);
		return p;
	}

	void addData(Data newdata) {
		size++;
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

	bool ContainsId(int id)const {
		Pointer p(this);
		Data checker(id);
		while ((*p != checker) || (p != nullptr))
			p++;
		if (p == nullptr)
			return false;
		else
			return true;
	}
private:
	cell* first;
	cell* last;
	size_t size;
};
