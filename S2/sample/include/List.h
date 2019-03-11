#pragma once

template<typename Data> class list {
public:
	list() {
		first = nullptr;
		last = nullptr;
	};
	list(Data d) {
		first = nullptr;
		last = nullptr;

		addData(d);
	};
	list(const list &original) {
		first = nullptr;
		last = nullptr;
		if (original.first != nullptr) {
			cell * tmp = original.first;
			while (tmp != nullptr) {
				addData(tmp->data);
				tmp = tmp->next;
			}
		}
		//original.canMoveNext();
	};
	~list() {
		//std::cout << "Destructor called" << std::endl;
		clear();
	};

	struct cell {
		Data data;
		cell* next;
	};

	void clear();

	class Pointer {
		cell* current;
		cell* first;
	public:
		Pointer(list &li) {
			current = li.first;
			first = li.first;
		}
		void rewind();
		//Data getCurrent()const; // *
		Data operator*()const;
		//void moveNext(); // ++
		Pointer& operator++();
		Pointer operator++(int);
		bool canMoveNext()const;
	};
	void addData(Data newdata) {
		cell* newcell = new cell;
		newcell->data = newdata;
		newcell->next = nullptr;

		if (first == nullptr) {
			first = newcell;
			last = newcell;
		}
		else {
			last->next = newcell;
			last = newcell;
		}
	};
	Pointer getFirstPtr();
private:
	cell * first;
	cell* last;
	
};
