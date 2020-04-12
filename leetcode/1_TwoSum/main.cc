/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
	public:
    	vector<int> twoSum(vector<int>& nums, int target) {
			map<int, int> key_sum;
			vector<int> ret;

			for (size_t i = 0; i < nums.size(); ++i) {
				std::cout << "nums[i]: " << nums[i] << std::endl;
				int find_value = target - nums[i];

				if (key_sum.find(find_value) == key_sum.end()) {
					std::cout << "find_value: " << find_value << std::endl;
					key_sum[nums[i]] = i;
				} else {
					ret.push_back(key_sum[find_value]);			
					ret.push_back(i);			
					return ret;
				}
			
			} // for

			return ret;
		}
};

int main() {
	vector<int> nums = {2, 7, 11, 15}; 
	int target = 9;

	Solution *obj = new Solution();

	vector<int> ret = obj->twoSum(nums, target);

	for (size_t i = 0; i < ret.size(); ++i) {
		std::cout << ret[i] << std::endl;	
	}

	return 0;
}
