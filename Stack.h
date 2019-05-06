#pragma once
#include "Array.h"

enum Operators { SUM, SUB, MUL, DIV, OPEN_BRACKET, CLOSE_BRACKET};

template <typename T> class stakk {
public:

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
			throw std::logic_error("Stack is empty!");
	}
	void pop() {
		m_storage.deleteElement(m_storage.Size() - 1);
	}

private:
	Array<T> m_storage;
};