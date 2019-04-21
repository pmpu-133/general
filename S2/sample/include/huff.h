#pragma once

#include "arr.h"
#include "AVLtree.h"
#include <iostream>

struct HuffNode {
  unsigned val;
  HuffNode *left, *right;
};

template<typename T1, typename T2> struct para {
  T1 v1;
  T2 v2;
};


bool elemIsIn(int elem, int* arr, size_t n) {
  for (int i = 0; i < n; ++i)
    if (elem == arr[i])
      return true;
  return false;
}

Array <para<unsigned char, size_t> > calcStats(std::istream& ist) {

}

HuffNode* buildHufftree(Array< para<unsigned char, size_t> > &symbols_w_freq) {
  for (int k = 0; k < symbols_w_freq.getSize(); ++k)
    for (int j = 0; j < symbols_w_freq.getSize(); ++j) {
      if (symbols_w_freq[k].v2 > symbols_w_freq[j].v2) {
        para<unsigned char, size_t> temp;
        temp.v1 = symbols_w_freq[k].v1;
        temp.v2 = symbols_w_freq[k].v2;
        symbols_w_freq[k] = symbols_w_freq[j];
        symbols_w_freq[j] = temp;
      }
    }
  // sorted array
  Array<HuffNode*> temp;
  int k = 0;

  while (!symbols_w_freq.isVoid()) {
    HuffNode node;
    temp[k] = new HuffNode;
    if (symbols_w_freq.getSize() != 1) {
      temp[k]->val = symbols_w_freq[0].v2 + symbols_w_freq[1].v2;
      temp[k]->left->val = symbols_w_freq[0].v1;
      temp[k]->right->val = symbols_w_freq[1].v1;
      ++k;
      symbols_w_freq.deleteElement(0);
      symbols_w_freq.deleteElement(1);
    }
    else {
      temp[k]->val = symbols_w_freq[0].v2;
      temp[k]->left->val = symbols_w_freq[0].v1;
      temp[k]->right = temp[0];
      ++k;
      temp.deleteElement(0);
      symbols_w_freq.deleteElement(0);
    }
  }
  //get sorted array with nodes
  Array<HuffNode*> tree;
  while (tree.getSize() != 1)
    tree = getTree(tree);
  HuffNode* Rtree = tree[0];
  return Rtree;
};

Array<HuffNode*> getTree(Array<HuffNode*> tree) {
  Array<HuffNode*> newtree;
  int i = 0;
  while (!tree.isVoid()) {
    if (tree.getSize() != 1) {
      newtree[i] = new HuffNode;
      newtree[i]->left = tree[0];
      newtree[i]->right = tree[1];
      newtree[i]->val = tree[0]->val + tree[1]->val;
      tree.deleteElement(0);
      tree.deleteElement(1);
      i++;
    }
    else {
      newtree[i] = new HuffNode;
      newtree[i]->left = tree[0];
      newtree[i]->right = newtree[0];
      newtree.deleteElement(0);
      tree.deleteElement(0);
      i++;
    }
  }
  return newtree;
}

AVLtree<unsigned char, Array<bool> >  tree2table(HuffNode*);