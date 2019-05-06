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


bool operator> (const Operators& op1, Operators& op2) {
  if (op1 == OPEN_BRACKET)
    return true;
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
public:
  DijkstraSorter() {
    m_input = nullptr;
    m_output = nullptr;
  }
  void setInput(Q*q) { m_input = q;}
  void setOutput(Q*q) { m_output = q;}
  void run() {
    while (!m_input->empty()) {
      FormulaNode node = m_input->getfirst();
      if (node.isOperand()) {
        m_output->push(node);
      }
      else {
        if (m_sta.empty())
          m_sta.push(node);
        else {

          switch (node.oper()) {

          case OPEN_BRACKET:
            m_sta.push(node);
            break;
          case CLOSE_BRACKET:
            while (!m_sta.empty() && node.oper() != OPEN_BRACKET) {
              m_output->push(m_sta.looktop());
              m_sta.pop();
            }
            m_sta.pop();
            m_input->getfirst();

          default:
            if (node.oper() > m_sta.looktop().oper()) {
              m_sta.push(node);
            }
            else {
              while (!m_sta.empty() && !(node.oper() > m_sta.looktop().oper())) {
                m_output->push(m_sta.looktop());
                m_sta.pop();
              }
            }

            break;
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
  stakk<FormulaNode> sta;

  while (!q.empty()) {
    FormulaNode node = q.getfirst();
    if (node.isOperand())
      sta.push(node);
    else {
      FormulaNode op1 = sta.looktop(); sta.pop();
      FormulaNode op2 = sta.looktop(); sta.pop();

      if (op1.isOperand() && op2.isOperand()) {
        double r = 0;
        switch (node.oper()) {
        case SUM: 
          r = op1.value() + op2.value();
          break;
        case SUB:
          r = op2.value() - op1.value();
          break;
        case MUL:
          r = op1.value() * op2.value();
          break;
        case DIV:
          r = op2.value() / op1.value();
          break;
        }
        sta.push(FormulaNode(r));
      }

    }
  }
  if (!sta.empty())
    return sta.looktop().value();
  else 
    throw std::logic_error("No evalution");

};




