#pragma once
#include <iostream>
#include "MyNode.h"

using namespace std;
class MyLinkedList {
private :
	MyNode * head;
public:
	MyLinkedList() { head = nullptr; };
	void addAtHead(int data);
	void addAtTail(int data);
	void delAtTail(int index);
	void delAtHead(int index);
	MyNode * getHead();
	void print() {
		MyNode *curr = head;
		while (curr != nullptr)
		{
			cout << curr->data<<" ";
			curr = curr->next;
		}
	}

};




/*
int main() {
	MyLinkedList *l = new MyLinkedList();
	l->addAtHead(1);
	l->addAtHead(2);
	l->print();

	l->addAtTail(3);
	l->print();


	return 0;
}
*/
