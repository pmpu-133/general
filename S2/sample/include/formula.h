#pragma once

#include "qu.h"
#include "stakk.h"


enum Operators {SUM, SUB, MUL, DIV, OPEN_BRACKET, CLOSE_BRACKET};


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

// imenno >, ne >= !!!
bool operator> (Operators op1, Operators op2) {
  if (op2 == OPEN_BRACKET)
    return true;
  if (op1 == OPEN_BRACKET)
    return false; 
  if ((op1 == DIV || op1 == MUL) && (op2 == SUM || op2 == SUB))
    return true;
  return false;

}

template<typename Q> class FormulaParser {
public:
  FormulaParser() { m_qu = nullptr;}
  void setResult(Q *q) {  m_qu = q; }

  void parse(const char* formula) {
    if (m_qu == nullptr)
      throw std::runtime_error("FormulaParser: have no output queue");
    for (int i = 0; i < strlen(formula); ++i) {
      if (formula[i] == ' ')
        continue;
      double ch = 0;

      if (formula[i] >= 48 && formula[i] <= 57) {
        while (formula[i] != '+' && formula[i] != '-' && formula[i] != '*' && formula[i] != '/' && formula[i] != ')' && formula[i] != '(' && i != strlen(formula) && formula[i] != ' ') {
          ch = ch * 10;
          ch += formula[i] - '0';
          ++i;

          if (formula[i] == ',') {
            int counter = 0;
            ++i;
            while (formula[i] != '+' && formula[i] != '-' && formula[i] != '*' && formula[i] != '/' && formula[i] != ')' && formula[i] != '(' && i != strlen(formula) && formula[i] != ' ') {
              counter--;
              ch += (formula[i] - '0') * pow(10, counter);
              ++i;
            }
            break;
          }
        }
        i--;
      }
      if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/' || formula[i] == ')' || formula[i] == '(') {
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

  ~DijkstraSorter() {}

  void setInput(Q*q) { m_input = q;}
  void setOutput(Q*q) { m_output = q;}
  void run() {
    while (!m_input->empty()) {
      FormulaNode node = m_input->getfirst();

      if (node.isOperand())
        m_output->push(node); 

      else {
        if (m_sta.empty())
          m_sta.push(node);

        else {
          switch (node.oper()) {
          case OPEN_BRACKET: m_sta.push(node); break;
          case CLOSE_BRACKET:
            while (!m_sta.empty() && m_sta.looktop().oper() != OPEN_BRACKET) {
              m_output->push(m_sta.looktop());
              m_sta.pop();
            }
            if (!m_sta.empty())
              m_sta.pop(); // pop '(' if it exists
            break;

          default:
            if (node.oper() > m_sta.looktop().oper())
              m_sta.push(node); 

            else {
              while (!m_sta.empty() && !(node.oper() > m_sta.looktop().oper()) && m_sta.looktop().oper() != OPEN_BRACKET ) {
                m_output->push(m_sta.looktop());
                m_sta.pop();
              }
              m_sta.push(node);
            }
            break;
          }
        }
      }
    }
    //push all that weren't pushed
    while (!m_sta.empty()) {
      m_output->push(m_sta.looktop());
      m_sta.pop();
    }
    //whitout this ne rabotaet, because y Hac CloMaH arr.h (clear() do not clear actually idk why)
    FormulaNode someTrashLol;
    //m_sta.push(someTrashLol); 
    //print the result
    m_output->print() ;
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
      if (node.oper() == OPEN_BRACKET || node.oper() == CLOSE_BRACKET) {
        std::cout << "Wrong ammount of brackets" << std::endl;
        exit(-1);
      }
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
      else {
        throw std::runtime_error("It's not Polskii notation");
        exit(-1);
      }
    }
  }
  return sta.looktop().value();
};