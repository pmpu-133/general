#pragma once
#include <stdexcept>
#include <iostream>

#include "arr.h"

struct evalNode{
  evalNode *left;
  evalNode *right;
  evalNode(): left(nullptr), right(nullptr) {}
  virtual double eval() { return 0;}
  virtual double evalChar() { return 0; }
  virtual void print() {}
  virtual void printChar() {}
  virtual void printUsual() {}
  virtual ~evalNode() {/*std::cout << "evalNode deleted" << std::endl;*/}
  virtual char getSymbol() { return '^'; }
};


struct evalConst : public evalNode {
  evalConst(double v) :val(v) {}
  evalConst(char c) :sym(c) {}
  double eval() { return val; };
  double evalChar() { 
    switch (sym) {
    case '0':
      return 0; break;
    case '1':
      return 1; break;
    case '2':
      return 2; break;
    case '3':
      return 3; break;
    case '4':
      return 4; break;
    case '5':
      return 5; break;
    case '6':
      return 6; break;
    case '7':
      return 7; break;
    case '8':
      return 8; break;
    case '9':
      return 9; break;
    }
  };
  void print() {std::cout << " " << val << " "; }
  void printChar() { std::cout << " " << sym << " "; }
  void printUsual() { std::cout << " " << val << " "; }
  char getSymbol() { return sym; }
  double val; 
  char sym;
  ~evalConst() { /*std::cout << "evalConst deleted with value " << val << std::endl;*/ }
};


enum opCode { OC_SUM, OC_SUB, OC_MUL, OC_DIV };
struct evalOp : public evalNode {
  evalOp(opCode c) :code(c) {}
  char getSymbol() { 
    switch (code) {
    case OC_SUB:
      return '-';
    case OC_SUM:
      return '+';
    case OC_MUL:
      return '*';
    case OC_DIV:
      return '/';
    }
  }
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


  //???
  double evalChar() {
    if (left && right)
      switch (code) {
      case OC_SUB:
        return left->evalChar() - right->evalChar();
      case OC_SUM:
        return left->evalChar() + right->evalChar();
      case OC_MUL:
        return left->evalChar() * right->evalChar();
      case OC_DIV:
        return left->evalChar() / right->evalChar();
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

  void printChar() {
    if (left)
      left->printChar();
    if (right)
      right->printChar();
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

  void printUsual(){
    if (left)
      left->printUsual();
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
    if (right)
      right->printUsual();
  }
  opCode code;
  ~evalOp() { /*std::cout << "evalOp deleted with code " << code << std::endl;*/ }
};

// дерево для представления арифметического выражения
class evalTree {
public:
  evalTree();
  evalTree(std::string &expression); //???
  ~evalTree();

  double eval() {
    if (m_pRoot) {
      m_pRoot->print();
      return m_pRoot->eval();
    }
  }

  double evalChar() {
    if (m_pRoot) {
      m_pRoot->printChar();
      std::cout << "  = ";
      return m_pRoot->evalChar();
    }
  }

  void getUsualForm() {
    if (m_pRoot) {
      m_pRoot->printUsual();
      std::cout << "  = ";
    }
  }

private:
  evalNode * m_pRoot;
  void clear(evalNode* node);
};


