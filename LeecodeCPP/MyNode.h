#pragma once

struct Point {
	int x, y;
};
class MyNode {
public:
	Point *p;
	int val;
	int idx;
	MyNode *next; //for linked list
	MyNode* left; //for bin tree
	MyNode* right; //for bin tree
	MyNode(int val, int x, int y)  {
		this->val = val;
		this->idx = val;
		p = new Point();
		this->p->x = x;
		this->p->y = y;
		this->left = nullptr;
		this->right = nullptr;
	}
	MyNode(int val,int idx, int x, int y) {
		this->val = val;
		this->idx = idx;
		p = new Point();
		this->p->x = x;
		this->p->y = y;
		this->left = nullptr;
		this->right = nullptr;
	}
	MyNode(int val) {
		this->val=val;
		this->p = new Point();
	}
	MyNode() {
		p = new Point();
	}
	~MyNode() {
		delete p;
	}
	
};
