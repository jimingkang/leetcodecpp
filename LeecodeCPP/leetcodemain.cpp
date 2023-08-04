#include "leetcode.h"



int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(5);
	v.push_back(4);
	v.push_back(0);
	v.push_back(8);
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it;
	}

	std::cout << maxWater(v) << std::endl;


	return 0;
}
