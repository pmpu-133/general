#pragma once
#define K int
#define V double
#include<iostream>


class bintree {
public:
	bintree() : root(nullptr) {}

	~bintree() {
		if (root)
			root->clear();
	}
			
	void AddData(const K& k, const V& value) {
		if (!root)
			root = new Node(k, value);
		else
			root->AddData(k, value);
	}

	void DeleteElem() {}

	void print() {
		root->print();
	}

	bool hasK(const K& k)const {}

	V operator[](const K& k)const {}


private:
	class Node {
	public:
		Node() : height(0), k(0), v(0), left(nullptr), right(nullptr) {}
	
    Node(K a, V b) : height(1), k(a), v(b), left(nullptr), right(nullptr) {}

		void AddData(const K& k1, const V& value) {
			if (k1 > k && right)
				right->AddData(k1, value);
			else if (k1 > k && !right)
				right = new Node(k1, v);
			else if (k1 < k && left)
				left->AddData(k1, value);
			else left = new Node(k1, value);
		}

		void clear() {}

 
    unsigned char height(Node* p) {
      return p ? p->height : 0;
    } 


    int bfactor(Node* p) {   // balanceFactor - difference of heights of the right and left subtree (balanced: -1,0,1)
      return height(p->right) - height(p->left);
    }
    
    void fixHeight(Node* p) {
      unsigned char hl = height(p->left);
      unsigned char hr = height(p->right);
      p->height = (hl > hr ? hl : hr) + 1;
    }

    Node* rotateRight(Node* p) {  // right turn around p
      Node* q = p->left;
      p->left = q->right;
      q->right = p;
      fixHeight(p);
      fixHeight(q);
      return q;
    }

   Node* rotateLeft(Node* q) {  // left turn around q
      Node* p = q->right;
      q->right = p->left;
      p->left = q;
      fixHeight(q);
      fixHeight(p);
      return p;
    }

   Node* balance(Node* p) {  // balancing node p
     fixHeight(p);
     if (bfactor(p) == 2) {
       if (bfactor(p->right) < 0)
         p->right = rotateright(p->right);
       return rotateleft(p);
     }
     if (bfactor(p) == -2) {
       if (bfactor(p->left) > 0)
         p->left = rotateleft(p->left);
       return rotateright(p);
     }
     return p;
   }

		void print() {
			if (left) left->print();
			std::cout << k << " - " << v << "\n";
			if (right) right->print();
		}

	private:
    unsigned char height;    //the height of the subtree
		Node * left;
		Node * right;
		K k;
		V v;
	};
  Node *root;
};