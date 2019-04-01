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

	bool hasK(const K& k)const {

	}

	V operator[](const K& k)const {

	}


private:
	class Node {
	public:
		Node() : k(0), v(0), left(nullptr), right(nullptr) {}
	
		Node(K a, V b) : k(a), v(b), left(nullptr), right(nullptr) {}

		void AddData(const K& k1, const V& value) {
			if (k1 > k && right)
				right->AddData(k1, value);
			else if (k1 > k && !right)
				right = new Node(k1, v);
			else if (k1 < k && left)
				left->AddData(k1, value);
			else left = new Node(k1, value);
		}

		void clear() {
	
		}

		void print() {
			if (left) left->print();
			std::cout << k << " - " << v << "\n";
			if (right) right->print();
		}

	private:
		Node * left;
		Node * right;
		K k;
		V v;
	};

	Node *root;
};