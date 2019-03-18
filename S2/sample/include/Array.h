#pragma once

template<typename Data> class Array {
public:
	Array() {
		size = 0;
		arr = nullptr;
	}
	Array(size_t n) {
		if (n >= 0) {
			size = n;
			arr = new Data[size];
			for (size_t i = 0; i < n; ++i) {
				arr[i] = 0;//arr[i]
			}
		}
	}
	Array(const Array &original) {
		size = original.Size();
		arr = new Data[size];
		for (size_t i = 0; i < size; ++i) {
			arr[i] = original.GetValue(i);
		}
	}
	~Array() {
		if (!isVoid()) {
			delete[] arr;
		}
	}
	size_t Size() const {
		return size;
	}
	Data* Pointer() {
		return arr;
	}
	void AddData(Data value) {
		Data* tmp = new Data[Size()];
		for (size_t i = 0; i < Size(); ++i) {
			tmp[i] = GetValue(i);
		}
		arr = new Data[size + 1];
		for (size_t i = 0; i < Size(); ++i) {
			arr[i] = tmp[i];
		}
		arr[size] = value;
		size++;
	}
	Data GetValue(size_t i) const {//значение по номеру элемента
		if (i < size) {
			return arr[i];
		}
	}
	void ChangeValue(size_t i, Data value) {
		if (i < Size()) {
			arr[i] = value;
		}
	}
	void PrintArray() const {
		for (size_t i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}
	bool isVoid() const { return Size() == 0; }
	void DeleteElement(size_t i) {
		if (i < size) {
			for (size_t j = i; j < size - 1; j++) {
				arr[j] = arr[j + 1];
			}
		}
		size--;
	}
	Data operator[] (size_t ind) {
		return *(arr + ind);
	}

	class Pointer {
		Data current;
	public:
		Pointer(Data *a, size_t i) {
			current = a[i];
		}
		Pointer* operator++();
	};
private:
	size_t size;
	Data* arr;
};