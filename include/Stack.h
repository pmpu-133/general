#pragma once
#include "Array.h"

enum Operators { SUM, SUB, MUL, DIV, OPEN_BRACKET, CLOSE_BRACKET};

template <typename T> class stakk {
public:
	stakk() {}

	void print() {
		for (int i = 0; i < m_storage.Size(); ++i)
			cout << m_storage[i] << " ";
		cout << endl;
	}

	void push(const T& data) {
		m_storage.AddData(data);
	}
	size_t size()const {
		return m_storage.Size();
	}
	bool empty()const {
		return m_storage.isVoid();
	}
	const T& looktop()const {
		if (!m_storage.isVoid())
			return  m_storage.GetValue(m_storage.Size() - 1);
		else
			throw std::logic_error("1.Stack is empty!");
	}
	void pop() {
		if (!empty())
			m_storage.deleteElement(m_storage.Size() - 1);
		else
			throw std::logic_error("2.Stack is empty!");
	}

private:
	Array<T> m_storage;
};