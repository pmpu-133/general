#pragma once

#include "pch.h"
#include <iostream>


template <typename Key, typename Data> class RBtree {
public:
  RBtree(): root(nullptr) {}
  RBtree(Key& k, Data& value) {
    root = new Node(k, value);
    //root->color = BLACK;
  }
  ~RBtree();

  bool hasK(const Key& k)const {
    if (!root)
      return false;
    root->miniHasK(k);
  }
  void print()const {
      if (root)
        root->print();
      else std::cout << "No tree" << std::endl;
    }

private:
  struct Node {
    Node() : height(0), key(0), data(0), left(nullptr), right(nullptr) {}
    Node(Key a, Data b) : height(1), key(a), data(b), left(nullptr), right(nullptr) {}

    bool miniHasK(const Key& k)const {
      if (k == key)
        return true;
      if (k > key && right)
        right->miniHasK(k);
      else if (k > key && !right)
        return false;
      else if (k < key && left)
        left->miniHasK(k);
      else
        return false;
    }

    void print()const {
      if (left) left->print();
      else std::cout << "No tree" << std::endl;
      std::cout << key << " - " << data << "\n";
      if (right) right->print();
    }

    unsigned char height;   //the height of the subtree 
    Node* left;
    Node* right;
    Key key;
    Data data;
    union color {
      int BLACK : 1;
      int RED : 1;
    };
  };

  Node* root;

  Node* ucle(Node *n) {
    Node *g = grandparent(n);
    if (!g)
      return nullptr; // No grandparent means no uncle
    if (n->parent == g->left)
      return g->right;
    else
      return g->left;
  }

  Node* grandparent(Node *n) {
     if (n && n->parent)
      return n->parent->parent;
    else
      return nullptr;
  }

  void rotate_left(Node *n) {
    Node *pivot = n->right;

    pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
    if (n->parent != nullptr) {
      if (n->parent->left == n)
        n->parent->left = pivot;
      else
        n->parent->right = pivot;
    }

    n->right = pivot->left;
    if (pivot->left != nullptr)
      pivot->left->parent = n;

    n->parent = pivot;
    pivot->left = n;
  }

  void rotate_right(Node *n) {
    Node *pivot = n->left;

    pivot->parent = n->parent;  /* при этом, возможно, pivot становится корнем дерева */
    if (n->parent != nullptr) {
      if (n->parent->left == n)
        n->parent->left = pivot;
      else
        n->parent->right = pivot;
    }

    n->left = pivot->right;
    if (pivot->right != nullptr)
      pivot->right->parent = n;

    n->parent = pivot;
    pivot->right = n;
  }

 /* void insert_case1(Node *n) {
    if (n->parent == nullptr)
      n->color = BLACK;
    else
      insert_case2(n);
  }

  void insert_case2(Node *n) {
    if (n->parent->color == BLACK)
      return; // Tree is still valid 
    else
      insert_case3(n);
  }

  void insert_case3(Node *n) {
    struct Node *u = uncle(n), *g;

    if ((u != nullptr) && (u->color == RED)) {
      // && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
      n->parent->color = BLACK;
      u->color = BLACK;
      g = grandparent(n);
      g->color = RED;
      insert_case1(g);
    }
    else {
      insert_case4(n);
    }
  }

  void insert_case4(Node *n) {
    struct Node *g = grandparent(n);

    if ((n == n->parent->right) && (n->parent == g->left)) {
      rotate_left(n->parent);

    
       //* rotate_left может быть выполнен следующим образом, учитывая что уже есть *g =  grandparent(n)
       //*
       //* struct node *saved_p=g->left, *saved_left_n=n->left;
       //* g->left=n;
       //* n->left=saved_p;
       //* saved_p->right=saved_left_n;
       //*
     

      n = n->left;
    }
    else if ((n == n->parent->left) && (n->parent == g->right)) {
      rotate_right(n->parent);

      
       //* rotate_right может быть выполнен следующим образом, учитывая что уже есть *g =  grandparent(n)
       //*
       //* struct node *saved_p=g->right, *saved_right_n=n->right;
       //* g->right=n;
       //* n->right=saved_p;
       //* saved_p->left=saved_right_n;
       //*
      n = n->right;
    }
    insert_case5(n);
  }

  void insert_case5(Node *n) {
    struct Node *g = grandparent(n);

    n->parent->color = BLACK;
    g->color = RED;
    if ((n == n->parent->left) && (n->parent == g->left)) {
      rotate_right(g);
    }
    else { // (n == n->parent->right) && (n->parent == g->right) 
      rotate_left(g);
    }
  }

  Node * sibling( Node *n) {
    if (n == n->parent->left)
      return n->parent->right;
    else
      return n->parent->left;
  }

  void delete_one_child(Node *n) {
    
    // Условие: n имеет не более одного ненулевого потомка.
     
    Node *child = is_leaf(n->right) ? n->left : n->right;

    replace_node(n, child);
    if (n->color == BLACK) {
      if (child->color == RED)
        child->color = BLACK;
      else
        delete_case1(child);
    }
    free(n);
  }

  void delete_case2(Node *n) {
    Node *s = sibling(n);

    if (s->color == RED) {
      n->parent->color = RED;
      s->color = BLACK;
      if (n == n->parent->left)
        rotate_left(n->parent);
      else
        rotate_right(n->parent);
    }
    delete_case3(n);
  }

  void delete_case3(Node *n) {
    Node *s = sibling(n);

    if ((n->parent->color == BLACK) &&
      (s->color == BLACK) &&
      (s->left->color == BLACK) &&
      (s->right->color == BLACK)) {
      s->color = RED;
      delete_case1(n->parent);
    }
    else
      delete_case4(n);
  }

  void delete_case4(Node *n) {
    Node *s = sibling(n);

    if ((n->parent->color == RED) &&
      (s->color == BLACK) &&
      (s->left->color == BLACK) &&
      (s->right->color == BLACK)) {
      s->color = RED;
      n->parent->color = BLACK;
    }
    else
      delete_case5(n);
  }

  void delete_case5(Node *n) {
    Node *s = sibling(n);

    if (s->color == BLACK) { // this if statement is trivial,
  //due to case 2 (even though case 2 changed the sibling to a sibling's child,
  //the sibling's child can't be red, since no red parent can have a red child).
  // the following statements just force the red to be on the left of the left of the parent,
   //  or right of the right, so case six will rotate correctly. 
      if ((n == n->parent->left) &&
        (s->right->color == BLACK) &&
        (s->left->color == RED)) { // this last test is trivial too due to cases 2-4.
        s->color = RED;
        s->left->color = BLACK;
        rotate_right(s);
      }
      else if ((n == n->parent->right) &&
        (s->left->color == BLACK) &&
        (s->right->color == RED)) {// this last test is trivial too due to cases 2-4.
        s->color = RED;
        s->right->color = BLACK;
        rotate_left(s);
      }
    }
    delete_case6(n);
  }
  
  void delete_case6(Node *n) {
    Node *s = sibling(n);

    s->color = n->parent->color;
    n->parent->color = BLACK;

    if (n == n->parent->left) {
      s->right->color = BLACK;
      rotate_left(n->parent);
    }
    else {
      s->left->color = BLACK;
      rotate_right(n->parent);
    }
  }
  */
  
};

