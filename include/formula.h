#pragma once
#pragma once

enum opCode { OC_SUM, OC_SUB, OC_MUL, OC_DIV };

class FormulaNode {
public:
	bool isOperator()const;
	bool isOperand()const;

	double value()const;

};

template<typename Q> class FormulaParser {
public:
	void setResult(Q* q);
	void parse(const char* formula);
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