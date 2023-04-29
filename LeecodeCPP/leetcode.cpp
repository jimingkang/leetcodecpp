/*#include <algorithm>
#include <vector>
#include <iostream>
int maxWater(vector<int> & v) {
	int left = 0;
	int right = v.size() - 1;
	int result;
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
*/