
#include <vector>
#include <iostream>
using namespace std;
int maxWater(vector<int> & v) {
	int left = 0;
	int right = v.size()-1;
	int result;
	while (left < right) {
		if (v[left] > v[right])
		{
			result = max(result, v[right] * (right - left));
			
			right--;
		}
		else {
			result = max(result, v[left] * (right - left));
			left++;
		}

			
	
	}
	return result;
}
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

