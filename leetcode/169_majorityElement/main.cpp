/*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

		sort(nums.begin(), nums.end());

		int max_val = 0;
		int val = nums[0];
		int max_count = 0; 
		int current_count = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			if (val == nums[i]) {
				current_count++;
			} else {
				current_count = 1;
				val = nums[i];
			}
			
			if (current_count > max_count) {
				max_val = val;
				max_count = current_count;
			}
			
		}

		return max_val;
    }
};

int main() {
	Solution *obj = new Solution();
	vector<int> nums = {2,2,1,1,1,2,2};
	std::cout << obj->majorityElement(nums) << std::endl;

}
