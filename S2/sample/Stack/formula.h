#pragma once
#include "Stack.h"

enum opCode { OC_SUM, OC_SUB, OC_MUL, OC_DIV };

class FormulaNode {
public:
	FormulaNode(char c) {
		m_number = 0;
		m_oper = c;
		m_isOperator = true;
	}

	FormulaNode(double d) {
		m_number = d;
		m_oper = 0;
		m_isOperator = false;
	}

	bool isOperator()const {
		return m_isOperator;
	}

	bool isOperand()const {
		return m_isOperator;
	}

	double value()const {
		if (!m_isOperator)
			return m_number;
		else throw std::logic_error("It's not a number");
	}

	char setOp(char c) {
		m_oper = c;
	}

private:
	double m_number;
	char m_oper;
	bool m_isOperator;
};

template<typename Q> class FormulaParser {
public:
	void setResult(Q* q);

	void parse(const char* formula) {
		for (int i = 0; i < formula.size(); ++i) {
			double ch = 0;
			if (formula[i] >= 48 && formula[i] <= 57) {
				ch = ch * 10;
				ch += formula[i] - '0';
			}
			int counter = 0;
			if (formula[i] == ',') {
				++i;
				while (formula[i] != '+' || formula[i] != '-' || formula[i] != '*' || formula[i] != '/') {
					counter--;
					ch += (formula[i] - '0') * pow(10, counter);
				}
			}
			FormulaNode o(ch);
			m_qu.push(o);
		}
	}

private:
	Q* m_qu;
};


template<typename Q> class DijkstraSorter {
	void setInput(Q*);
	void setOutput(Q*);
	void run();
private:

};
template<typename Q>  double evaluate(Q& q) {
	while (!q.empty()) {

	}
};