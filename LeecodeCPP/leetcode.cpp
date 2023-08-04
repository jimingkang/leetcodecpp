#include "leetcode.h"
int maxWater(vector<int> & v) {
	int left = 0;
	int right =v.size() - 1;
	int result=0;
	while (left < right) {
		if (v[left] > v[right])
		{
			result = std::max(result, v[right] * (right - left));

			right--;
		}
		else {
			result = std::max(result, v[left] * (right - left));
			left++;
		}



	}
	return result;
}


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