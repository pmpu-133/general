#include "stdafx.h"
#include "evalTree.h"

evalTree::evalTree() {
  evalNode *cur = nullptr;
  cur = new evalConst(2);
  evalNode *tmp = new evalConst(5);

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
  m_pRoot->right = par;

}


void evalTree::clear(evalNode *node) {
  if (!node) {
    if (!node->left && !node->right) {
      delete node;
      return;
    }
    clear(node->left);
    clear(node->right);
  }
  throw std::runtime_error("Bad pointers");
}
