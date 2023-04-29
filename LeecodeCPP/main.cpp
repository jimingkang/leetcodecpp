
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

#include "MyLinkedList.h"
//#include <cmath>
//#include "leecode.h"
using namespace std;
/*
int maxWater(vector<int> & v);
int main() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(5);
	v.push_back(4);
	v.push_back(25); 
	v.push_back(8);
	v.push_back(1);
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it;
	}

	std::cout <<maxWater(v) << std::endl;


	return 0;
}
*/

int main() {
	MyLinkedList *l = new MyLinkedList();
	l->addAtHead(1);
	l->addAtHead(2);
	l->print();

	l->addAtTail(3);
	l->print();


	return 0;
}
