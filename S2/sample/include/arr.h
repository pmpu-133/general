#pragma once

template<typename Data> class Array {
public:
	Array() {
		arr = nullptr;
		size = 0;
	};
	Array(size_t n) {
		size = n;
		arr = new Data[size];
		for (size_t i = 0; i < size; ++i) {
			*(arr + i) = 0;
		}
	};
	Array(const Array &original) {
		size = original.Size();
		arr = new Data[size];
		for (size_t i = 0; i < size; ++i)
			*(arr + i) = original.getValue(i);
	};
	~Array() {
		clear();
	};
	Data* first() {
		return arr;
	};
	Data* last() {
		return arr + this->size;
	};
	class Pointer {
	public:
		Pointer(Array* arr) {
			first = arr->first();
			current = arr->first();
			last = arr->last();
		};
		void rewind() {
			current = first;
		};
		bool canMoveNext()const {
			if (current != nullptr)
				return current != last;
			return false;

		};
		bool canMoveBack()const {
			if (current != nullptr)
				return current != first;
			return false;
		};
		Pointer& operator++() {
			if (this->canMoveNext())
				current = current + 1;
			return *this;
		};
		Pointer& operator++(int){
			if (this->canMoveNext())
			current = current + 1;
		return *this;
			};
		Pointer& operator--() {
			if (this->canMoveBack())
				current = current - 1;
			return *this;
		};
		Pointer& operator--(int) {
			if (this->canMoveBack())
				current = current - 1;
			return *this;
		};
		Data operator*() {
			if (current != nullptr)
				return *current;
			return -1;
		};
		Data& operator=(const Data& data) {
			*current = data;
			return *current;
		};

	private:
		Data * current;
		Data* last;
		Data* first;
	};
	void clear() {
		if (!isVoid())
			delete[] arr;
	};
	void addData(Array a, Data data) {
		Data* tmp = new Data[a.Size()];
		for (int i = 0; i < a.Size(); ++i)
			tmp[i] = a.getValue(i);
		arr = new Data[size + 1];
		for (int i = 0; i < a.Size(); ++i)
			arr[i] = tmp[i];
		arr[size] = data;
		size++;
	};
	Data* pointer()const {
		return arr;
	};
	size_t Size()const{
		return size;
    };
	Data getValue(size_t i)const {
		if (i < size)
			return *(arr + i);
	};
	void changeValue(size_t i, Data data) {
		if (i < Size())
			*(arr + i) = data;
	};
	void printArray() {
		for (size_t i = 0; i < Size(); ++i)
			cout << *(arr + i) << " ";
	};
	bool isVoid()const {
		return Size() == 0;
	};
	void deleteElement(size_t i) {
		if (i < Size()) {
			for (int j = i; j < Size() - 1; ++j)
				*(arr + i) = *(arr + j + 1);
			size--;
		}
	};
	Data operator[](int ind) {
		if ((ind < size) && (ind > -1))
			return *(arr + ind);
		return -123452;
	};
private:
	Data * arr;
	size_t size;
};