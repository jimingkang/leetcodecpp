
#include "leetcode.h"
#include "MyLinkedList.h"
//#include <cmath>


/**/



int main() {
	/* example 1*/
	/* MyLinkedList *l = new MyLinkedList();
	l->addAtHead(1);
	l->addAtHead(2);
	l->print();

	l->addAtTail(3);
	l->print();


	return 0;
	*/

	/* example 2*/
	vector<int> v;
	v.push_back(10);
	v.push_back(5);
	v.push_back(4);
	v.push_back(0);
	v.push_back(8);
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it;
	}

	std::cout << maxWater(v) <<" " << std::endl;


	return 0;
}

