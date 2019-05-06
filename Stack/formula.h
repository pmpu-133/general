#pragma once
#include "Stack.h"
#include <iostream>

class FormulaNode {
public:
	FormulaNode() {
		m_number = 0;
		m_oper = SUM;
		m_isOperator = true;
	}
	FormulaNode(Operators c) {
		m_number = 0;
		m_oper = c;
		m_isOperator = true;
	}

	FormulaNode(double d) {
		m_number = d;
		m_isOperator = false;
	}

	bool isOperator()const {
		return m_isOperator;
	}

	bool isOperand()const {
		return !m_isOperator;
	}

	double value()const {
		if (!m_isOperator)
			return m_number;
		else throw std::logic_error("It's not a number");
	}

	void setOper(Operators s) {
		m_oper = s;
		m_isOperator = true;
	}

	Operators oper()const {
		if (m_isOperator) {
			return m_oper;
		}
	}

private:
	double m_number;
	Operators m_oper;
	bool m_isOperator;
};


std::ostream& operator << (std::ostream& ost, const FormulaNode& node) {
	if (node.isOperand())
		ost << node.value();
	else {
		switch (node.oper()) {
		case SUM:
			ost << "+"; break;
		case DIV:
			ost << "/"; break;
		case MUL:
			ost << "*"; break;
		case SUB:
			ost << "-";
		}
	}
	return ost;
}




template<typename Q> class FormulaParser {
public:
	FormulaParser() { m_qu = nullptr; };

	void setResult(Q* q) {
		m_qu = q;
	};

	void parse(const char* formula) {
		if (m_qu == nullptr)
			throw std::runtime_error("FormulaParser have no output queue");
		for (int i = 0; i < strlen(formula); ++i) {
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
			if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/') {
				FormulaNode o;
				switch (formula[i]) {
				case '+':
					o.setOper(SUM);
					m_qu->push(o);
					break;
				case '/':
					o.setOper(DIV);
					m_qu->push(o);
					break;
				case '-':
					o.setOper(SUB);
					m_qu->push(o);
					break;
				case '*':
					o.setOper(MUL);
					m_qu->push(o);
					break;
				case '(':
					o.setOper(OPEN_BRACKET);
					m_qu->push(o);
					break;
				case ')':
					o.setOper(CLOSE_BRACKET);
					m_qu->push(o);
					break;
				}
			}
			else {
				FormulaNode o(ch);
				m_qu->push(o);
			}
		}
	}

private:
	Q* m_qu;
};

bool operator>(const Operators & op1, const Operators & op2) {
	if (op1 == DIV || op1 == MUL)
		return true;
	if (op1 == SUM || op1 == SUB)
		if (op2 == DIV || op2 == MUL)
			return false;
		else
			return true;
}



template<typename Q> class DijkstraSorter {
	void setInput(Q* q) { m_input = q; }
	void setOutput(Q* q) { m_output = q; }
	void run() {
		while (!m_input->empty()) {
			FormulaNode node = m_input->getFirst();
			if (node.isOperand)
				m_output->push(node);
			else {
				if (m_sta.empty())
					m_sta.push(node);
				else {
					if (node.oper() > m_sta.looktop().oper()) {
						m_sta.push(node);
					}
					else {
						while (!m_sta.empty() && !(node.oper() > m_sta.looktop().oper())) {
							m_output->push(m_sta.looktop());
							m_sta.pop();
						}
					}
				}
			}
		}
	};
private:
	Q* m_input;
	Q* m_output;
	stakk<FormulaNode> m_sta;
};


template<typename Q>  double evaluate(Q & q) {
	while (!q.empty()) {

	}
};



/*void fromBaseToPost(string str) {
  stakk<Operators> stack;
  qu<FormulaNode> queue;
  for (int i = 0; i < str.size(); ++i) {
	double ch = 0;
	if (str[i] >= 48 && str[i] <= 57) {
	  ch = ch * 10;
	  ch += str[i] - '0';
	}
	int counter = 0;
	if (str[i] == ',') {
	  ++i;
	  while (str[i] != '+' || str[i] != '-' || str[i] != '*' || str[i] != '/') {
		counter--;
		ch += (str[i] - '0') * pow(10, counter);
	  }
	}
	FormulaNode o(ch);
	queue.push(o);
	if (str[i] != '+' || str[i] != '-' || str[i] != '*' || str[i] != '/' || str[i] == '(' || str[i] == ')') {
	  if (stack.empty())
		switch (str[i]) {
		case'+':
		  stack.push(SUM);
		case'-':
		  stack.push(SUB);
		case'*':
		  stack.push(MUL);
		case'/':
		  stack.push(DIV);
		case'(':
		  stack.push(OPEN_BRACKET);
		}
	  else {
		switch (str[i]) {
		case'+':
		  if (Compare(SUM, stack.looktop()))
			stack.push(SUM);
		  else
			while (!stack.empty()) {
			  FormulaNode o;
			  o.setOp(stack.looktop());
			  queue.push(o);
			  stack.pop();
			}
		case'-':
		  if (Compare(SUB, stack.looktop()))
			stack.push(SUB);
		  else
			while (!stack.empty()) {
			  FormulaNode o;
			  o.setOp(stack.looktop());
			  queue.push(o);
			  stack.pop();
			}
		case'*':
		  if (Compare(MUL, stack.looktop()))
			stack.push(MUL);
		case'/':
		  if (Compare(MUL, stack.looktop()))
			stack.push(DIV);
		case'(':
		  stack.push(OPEN_BRACKET);
		case')':
		  while (stack.looktop() != ')') {
			FormulaNode o;
			o.setOp(stack.looktop());
			queue.push(o);
			stack.pop();
		  }
		  stack.pop();
		}
	  }
	}
  }
  while (!stack.empty()) {
	FormulaNode o;
	o.setOp(stack.looktop());
	queue.push(o);
	stack.pop();
  }
}*/