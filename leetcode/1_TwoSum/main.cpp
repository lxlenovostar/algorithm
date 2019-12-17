/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

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
		vector<int>	ret;
		map<int, int> index;
		if (nums.size() <= 1)
			return ret;

		for (size_t i = 0; i < nums.size(); i++) {
			index[nums[i]]	= i;
			std::cout << "key:" << nums[i] << " value:" << i << std::endl;
		}

		for (size_t i = 0; i < nums.size(); i++) {
			int key = target - nums[i];
			
			std::cout << "key value:" << key << std::endl;

			map<int, int>::iterator pos = index.find(key);
			if (pos != index.end() && pos->second != (int)i)  {
				ret.push_back(i);
				ret.push_back(pos->second);
				return ret;
			}
		}

		return ret;
    }
};

int main() {
	//vector<int> nums = {2, 7, 11, 15};
	vector<int> nums = {3, 2, 4};
	int k = 6; 

	Solution *obj = new Solution();
	vector<int> ret =  obj->twoSum(nums, k);

	for (size_t i = 0; i < ret.size(); i++) {
		std::cout << ret[i] << std::endl;
	}

	return 0;
}
