#include "pch.h"
#include "evalTree.h"

evalTree::evalTree() {
  m_pRoot = nullptr;
  /*evalNode *cur = nullptr;
  cur = new evalConst(5);
  evalNode *tmp = new evalConst(2);

  evalNode *par = new evalOp(OC_MUL);
  par->left = cur;
  par->right = tmp;
  cur = par;
  tmp = new evalConst(3);
  par = new evalOp(OC_SUM);
  par->left = tmp;
  par->right = cur;

  m_pRoot = new evalOp(OC_SUB);
  m_pRoot->left = par;

  par = new evalOp(OC_DIV);
  tmp = new evalConst(4);
  cur = new evalConst(2);
  par->left = tmp;
  par->right = cur;
  m_pRoot->right = par;*/
}


evalNode* getNodePtr(const char& c) {
    if (c == '*')
      return new evalOp(OC_MUL);
    if (c == '/')
      return new evalOp(OC_DIV);
    if (c == '+')
      return new evalOp(OC_SUM);
    if (c == '-')
      return new evalOp(OC_SUB);
    return new evalConst(c);
};

evalTree::evalTree(std::string &expression) {

  Array<evalNode*> pSymbols(expression.length());
  for (int i = 0; i < pSymbols.Size(); ++i)
    pSymbols[i] = getNodePtr(expression[i]);


  for (int i = 0; i < pSymbols.Size(); ++i)
    if (pSymbols[i]->getSymbol() == '*' || pSymbols[i]->getSymbol() == '/')
      if (!pSymbols[i]->left && !pSymbols[i]->right) {
        pSymbols[i]->left = pSymbols[i - 1];
        pSymbols[i]->right = pSymbols[i + 1];
        pSymbols.deleteElement(i - 1);
        --i;
        pSymbols.deleteElement(i + 1);
      }

  for (int i = 0; i < pSymbols.Size(); ++i)
    if (pSymbols[i]->getSymbol() == '+' || pSymbols[i]->getSymbol() == '-')
      if (!pSymbols[i]->left && !pSymbols[i]->right) {
        pSymbols[i]->left = pSymbols[i - 1];
        pSymbols[i]->right = pSymbols[i + 1];
        pSymbols.deleteElement(i - 1);
        --i;
        pSymbols.deleteElement(i + 1);
      }
  m_pRoot = pSymbols[0];
}

evalTree::~evalTree() { 
  clear(m_pRoot); 
  /*std::cout << "evalTree deleted" << std::endl;*/
}


void evalTree::clear(evalNode *node) {
  if (!node)
    throw std::runtime_error("Bad pointers");
  else {
    if (!node->left && !node->right) {
      delete node;
      return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
  }
}

