/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
	public:
    	bool canJump(vector<int>& nums) {
			if (nums.size() == 0)
				return false;

			//nums[0]

			for (size_t i = 0; i < nums.size(); ) {
				int jump_value = 0;
				size_t jump_index = 0;
				
				for (int j = i+1; j <= (i+nums[i]); ++j) {
					std::cout << "i: " << i << " j: " << j << " nums[i]:" << nums[i] << std::endl;

					if (nums[j] > jump_value) {
						jump_value = (j + nums[j]);			
						jump_index = j;
					} // if	

				} // for

				i += jump_index;	

				std::cout << "jump_value: " << jump_value << " jump_index: " << jump_index  << " i: " << i  << std::endl;

				if (jump_index >= nums.size())
					return true;
			}

			return false;
		}
};

int main() {
	vector<int> nums = {2,3,1,1,4};

	Solution *obj = new Solution();
	std::cout << obj->canJump(nums) << std::endl;

	return 0;

}

