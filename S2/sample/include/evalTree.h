#pragma once
#include <stdexcept>
#include <iostream>

struct evalNode{
  evalNode *left;
  evalNode *right;
  evalNode(): left(nullptr), right(nullptr) {}
  virtual double eval() { return 0;}
  virtual void print() {}
};


struct evalConst : public evalNode {
  evalConst(double v) :val(v) {}
  double eval() { return val; };
  void print() {std::cout << " " << val << " "; }
  double val;
};


enum opCode { OC_SUM, OC_SUB, OC_MUL, OC_DIV };
struct evalOp : public evalNode {
  evalOp(opCode c) :code(c) {}
  double eval() {
    if (left && right)
      switch (code) {
      case OC_SUB:
        return left->eval() - right->eval();
      case OC_SUM:
        return left->eval() + right->eval();
      case OC_MUL:
        return left->eval() * right->eval();
      case OC_DIV:
        return left->eval() / right->eval();
      }
    else
      throw std::runtime_error("Bad pointers");
  }
  void print() {
    if (left)
      left->print();
    if (right)
      right->print();
    switch (code) {
    case OC_SUB:
      std::cout << " - "; break;
    case OC_SUM:
      std::cout << " + "; break;
    case OC_MUL:
      std::cout << " * "; break;
    case OC_DIV:
      std::cout << " / "; break;
    }
  }
  opCode code;
};

// дерево для представления арифметического выражения
class evalTree {
public:
  evalTree();
  ~evalTree() { clear(m_pRoot); }
  double eval() {
    if (m_pRoot) {
      m_pRoot->print();
      return m_pRoot->eval();
    }
  };

private:
  evalNode * m_pRoot;
  void clear(evalNode* node);
};