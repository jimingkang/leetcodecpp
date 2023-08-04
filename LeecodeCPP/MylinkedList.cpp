#include "MyLinkedList.h"
void MyLinkedList::addAtHead(int data) {
	MyNode * tmp = new MyNode();
	tmp->data = data;
	tmp->next = head;
	this->head = tmp;
}
void MyLinkedList::addAtTail(int data) {
	MyNode *curr = this->getHead();
	
	while (curr->next!=nullptr)
	{
		curr = curr->next;
	}

	MyNode * tmp = new MyNode();
	tmp->data = data;
	tmp->next = nullptr;
	curr->next = tmp;
	
}
void MyLinkedList::delAtTail(int index) {
}
void MyLinkedList::delAtHead(int index) {
}

MyNode * MyLinkedList::getHead() {
	return head;
}


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