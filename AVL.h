#pragma once
template<typename Key, typename Data>
class avl {		//Key должен иметь операторы (>; <; ==) и не должен повторяться
public:
	avl()
	{
		kor = nullptr;
	}
	avl(Key k, Data d)
	{
		kor = new node(k, d);
	}
	void push(Key k, Data d)
	{
		if (kor == nullptr)
			kor = new node(k, d);
		else
			kor = insert(kor, k, d);
	}
	void show()
	{
		pit(kor);
	}
	Data operator[](Key k)
	{
		node* p = kor;
		while (p->key != k && p != nullptr)
		{
			if (p->key > k)
				p = p->left;
			else
				p = p->right;
		}
		if (p != nullptr)
			return p->data;
	}


private:
	struct node // структура для представления узлов дерева
	{
		Key key;
		Data data;
		unsigned char height;
		node *left;
		node *right;
		node(Key k, Data d) 
		{ 
			key = k;
			data = d;
			left = right = nullptr;
			height = 1;
		}
	};

	node* kor;

	void pit(node *n)
	{
		if (n != nullptr) {
			std::cout << n->key << ' ';
			pit(n->left);
			pit(n->right);
		}
	}
	unsigned char height(node *p)
	{
		if (p)
			return p->height;
		else
			return 0;
//		return p ? p->height : 0;
	}
	int bfactor(node *p)
	{
		return height(p->right) - height(p->left);
	}
	void fixheight(node *p)
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		if (hl > hr)
			p->height = hl+1;
		else
			p->height = hr+1;
		//p->height = (hl > hr ? hl : hr) + 1;
	}
	node *rotateright(node *p) // малый правый поворот вокруг p
	{
		node *q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}
	node *rotateleft(node *q) // малый левый поворот вокруг q
	{
		node *p = q->right;
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}
	node *balance(node *p) // балансировка узла p (Большой левый или большой правый поворот)(из двух или одного малого)
	{
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p;
	}
	node *insert(node *p, Key k, Data d) // вставка ключа k в дерево с корнем p
	{
		if (!p) return new node(k, d);
		if (k < p->key)
			p->left = insert(p->left, k, d);
		else
			p->right = insert(p->right, k, d);
		return balance(p);
	}
};