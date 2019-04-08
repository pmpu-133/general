#pragma once
#include<iostream>


template <typename Key, typename Data> class bintree {
public:
	bintree() : root(nullptr) {}

	bintree(Key& k, Data& value)  {
		root = new Node(k, value);
	}

	~bintree() {
		
	}
	
	void clear() {
	   //Node* p = findmin(root);

	}
			
	void push(const Key& k, const Data& value) {
		if (!root)
			root = new Node(k, value);
		else
			root = insert(root, k, value);
	}

	void DeleteElem(const Key& k) {
		if (root) 
		root = remove(root,k);
	}

  void print() {  
    root->print();
  }

  bool hasK(const Key& k)const {
    if (!root)
      return false;
    root->miniHasK(k);
  }

	Data operator[](const Key& k)const {
		Node* p = root;
		while (p->key != k && p != nullptr) {
			if (p->key > k)
				p = p->left;
			else
				p = p->right;
		}
		if (p != nullptr)
			return p->v;
		return 0;
	}
  
private:
	struct Node {
		Node() : height(0), key(0), v(0), left(nullptr), right(nullptr) {}

    Node(Key a, Data b) : height(1), key(a), v(b), left(nullptr), right(nullptr) {}


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
			std::cout << key << " - " << v << "\n";
			if (right) right->print();
		}

    unsigned char height;    //the height of the subtree (actually, the difference of heights)
		Node * left;
		Node * right;
		Key key;
		Data v;
	};
  Node *root;
	
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

	 Node* insert(Node *p, Key k, Data d) {
		 if (!p) return new Node(k, d);
		 if (k < p->key)
			 p->left = insert(p->left, k, d);
		 else
			 p->right = insert(p->right, k, d);
		 return balance(p);
	 }

	 Node* findmin(Node* p) {
		 return p->left ? findmin(p->left) : p;
	 }

	 Node* removemin(Node* p) {
		 if (p->left == 0)
			 return p->right;
		 p->left = removemin(p->left);
		 return balance(p);
	 }

	 Node* remove(Node* p, int k) {
		 if (!p) return 0;
		 if (k < p->key)
			 p->left = remove(p->left, k);
		 else if (k > p->key)
			 p->right = remove(p->right, k);
		 else //  k == p->key 
		 {
			 Node* q = p->left;
			 Node* r = p->right;
			 delete p;
			 if (!r) return q;
			 Node* min = findmin(r);
			 min->right = removemin(r);
			 min->left = q;
			 return balance(min);
		 }
		 return balance(p);
	 }
};