#pragma once
#include<iostream>


template <typename K, typename V> class bintree {
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

	void DeleteElem(const K& k) {}

  void print() {  
    root->print();
  }

  bool hasK(const K& k)const {
    if (!root)
      return false;
    root->miniHasK(k);
  }

	V operator[](const K& k)const {}
  
private:
	class Node {
	public:
		Node() : height(0), key(0), v(0), left(nullptr), right(nullptr) {}

    Node(K a, V b) : height(1), key(a), v(b), left(nullptr), right(nullptr) {}

		void AddData(const K& k, const V& value) {
			if (k > key && right)
				right->AddData(k, value);
			else if (k > key && !right)
				right = new Node(k, v);
			else if (k <= key && left)
				left->AddData(k, value);
			else left = new Node(k, value);
		}

    bool miniHasK(const K& k)const {
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

		void clear() {}

 
    unsigned char getHeight(Node* p)const {
      if (p != nullptr)
        return p->height;
       else
         return 0;
    } 


    int bfactor(Node* p)const {   // balanceFactor - difference of heights of the right and left subtree (balanced: -1,0,1)
      return getHeight(p->right) - getHeight(p->left);
    }
    
    void fixHeight(Node* p) {
      unsigned char hl = getHeight(p->left);
      unsigned char hr = getHeight(p->right);
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
         p->right = rotateRight(p->right);
       return rotateLeft(p);
     }
     if (bfactor(p) == -2) {
       if (bfactor(p->left) > 0)
         p->left = rotateLeft(p->left);
       return rotateRight(p);
     }
     return p;
   }


  
		void print()const {
			if (left) left->print();
			std::cout << key << " - " << v << "\n";
			if (right) right->print();
		}

	private:
    unsigned char height;    //the height of the subtree (actually, the difference of heights)
		Node * left;
		Node * right;
		K key;
		V v;
	};
  Node *root;
};