#pragma once

class avl {
public:
	avl()
	{
		kor = nullptr;
	}
	avl(int k)
	{
		kor = new node(k);
	}
	void push(int k)
	{
		if (kor == nullptr)
			kor = new node(k);
		else
			kor = insert(kor, k);
	}
	void pit()
	{
		show(kor);
	}


private:
	struct node // ��������� ��� ������������� ����� ������
	{
		int key;
		unsigned char height;
		node *left;
		node *right;
		node(int k) 
		{ 
			key = k;
			left = right = nullptr;
			height = 1;
		}
	};

	node* kor;

	void show(node *n)
	{
		if (n != nullptr) {
			std::cout << n->key << ' ';
			show(n->left);
			show(n->right);
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
	node *rotateright(node *p) // ����� ������ ������� ������ p
	{
		node *q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}
	node *rotateleft(node *q) // ����� ����� ������� ������ q
	{
		node *p = q->right;
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}
	node* balance(node* p) // ������������ ���� p (������� ����� ��� ������� ������ �������)(�� ���� ��� ������ ������)
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
	node* insert(node* p, int k) // ������� ����� k � ������ � ������ p
	{
		if (!p) return new node(k);
		if (k < p->key)
			p->left = insert(p->left, k);
		else
			p->right = insert(p->right, k);
		return balance(p);
	}
};