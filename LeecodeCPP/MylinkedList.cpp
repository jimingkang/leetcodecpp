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