#pragma once

#include "qu.h"
#include "stakk.h"


class FormulaNode {
public:
  FormulaNode() {
    m_number = 0;
    m_oper = SUM;
    m_isOperator = false;
  }
  
  FormulaNode(Operators c) {
    m_number = 0;
    m_oper = c;
    m_isOperator = true;
  }

  FormulaNode(double d) {
    m_number = d;
    m_oper = SUM;
    m_isOperator = false;
  }

  FormulaNode(char op) {
    switch (op) {
    case '+': m_oper = SUM; break;
    case '-': m_oper = SUB; break;
    case '*': m_oper = MUL; break;
    case '/': m_oper = DIV; break;
    case '(': m_oper = OPEN_BRACKET; break;
    case ')': m_oper = CLOSE_BRACKET; break;
    }
    m_number = 0;
    m_isOperator = true;
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

  Operators oper()const {
    if (m_isOperator)
      return m_oper;
    else
      throw std::logic_error("Not an operator");
  }

  

private:
  double m_number;
  Operators m_oper;
  bool m_isOperator;
};


std::ostream& operator<< (std::ostream& ost, const FormulaNode& node) {
  if (node.isOperand())
    ost << node.value();
  else {
    switch (node.oper()) {
    case SUM: ost << '+'; break;
    case SUB: ost << '-'; break;
    case MUL: ost << '*'; break;
    case DIV: ost << '/'; break;
    case OPEN_BRACKET: ost << '('; break;
    case CLOSE_BRACKET: ost << ')'; break;
    }
  }
  return ost;
}


bool operator<(const Operators& op1, const Operators& op2) {
  if (op1 == DIV || op1 == MUL)
    return true;
  if (op1 == SUM || op1 == SUB)
    if (op2 == DIV || op2 == MUL)
      return false;
    else
      return true;
}

template<typename Q> class FormulaParser {
public:
  FormulaParser() { m_qu = nullptr;}
  void setResult(Q *q) {  m_qu = q; }

 

  void parse(const char* formula) {
    if (m_qu == nullptr)
      throw std::runtime_error("FormulaParser: have no outpit queue");
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
      if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/' || formula[i] == ')' || formula[i] == '(')
      {
        FormulaNode node(formula[i]);
        m_qu->push(node);
      }
      else {
        FormulaNode node(ch);
        m_qu->push(node);
      }
    }
  }

private:
  Q * m_qu;
};


template<typename Q> class DijkstraSorter {
  void setInput(Q*q) { m_input = q;}
  void setOutput(Q*q) { m_output = q;}
  void run() {
    while (!m_input->empty()) {
      FormulaNode node = m_input->getFirst();
      if (node.isOperand) {
        m_output->push(node);
      }
      else {
        if (m_sta.empte())
          m_sta.push(node);
        else {
          if (node.oper() > m_sta.looktop().oper()) {
            m_sta.push(node);
          }
          else {
            while (m_sta.empty() && node.oper() > !(m_sta.looktop().oper())) {
              m_output->push(m_sta.looktop());
              m_sta.pop();
            }
          }
        }
      }
    }
  }
private:
  Q* m_input;
  Q* m_output;
  stakk<FormulaNode> m_sta;
};


template<typename Q>  double evaluate(Q&q) {
  while (!q.empty()) {
    
  }
};




