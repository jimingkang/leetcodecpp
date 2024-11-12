#pragma once

struct Point {
	int x, y;
};
class MyNode {
public:
	Point *p;
	int data;
	MyNode *next; //for linked list
	MyNode* left; //for bin tree
	MyNode* right; //for bin tree
	MyNode(int data, int x, int y)  {
		this->data = data;
		p = new Point();
		this->p->x = x;
		this->p->y = y;
		this->left = nullptr;
		this->right = nullptr;
	}
	MyNode(int data) {
		this->data=data;
		this->p = new Point();
	}
	MyNode() {
	
	}
	~MyNode() {
		delete p;
	}
	
};
