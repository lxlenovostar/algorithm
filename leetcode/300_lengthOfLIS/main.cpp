/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
*/

#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
	int N;
	int result;

	void recu(vector<int>& nums, int k, int maxvalue, int ret) {
		if ((k+1) >= N) {
			result = max(result, ret);
			return;
		}

		if (nums[k+1] > maxvalue) {
			maxvalue = max(maxvalue, nums[k+1]);
		
			std::cout << "what1 k: " << k << " nums[k+1]: " << nums[k+1]  << " maxvalue: " << maxvalue << " ret: " << ret << std::endl;
		
			recu(nums, k+1, nums[k+1], 1); //new start

			recu(nums, k+1, maxvalue, ret+1); // choice

		} else {
			std::cout << "what2 k: " << k << " nums[k+1]: " << nums[k+1]  << " maxvalue: " << maxvalue << " ret: " << ret << std::endl;

			recu(nums, k+1, nums[k+1], 1);  //new start

			recu(nums, k+1, maxvalue, ret);  // not choice
		}


	}

    int lengthOfLIS_1(vector<int>& nums) {
		N = nums.size();

		if (N <= 1)
			return N;

		recu(nums, 0, nums[0], 1);

		return result;
	}

    int lengthOfLIS(vector<int>& nums) {
     	int n = nums.size();

		if (n <= 1)
			return 1;

		vector<int> ret;
		ret.resize(n);

		ret[0] = 1;
		int result = INT_MIN;

		for (int i = 1; i < n; ++i) {
			std::cout << "before i: " << i << " ret[i]: " << ret[i]  << " result: " << result << std::endl;
			if (nums[i] >= nums[i-1])
				ret[i] = ret[i-1] + 1;
			else  {
				ret[i] = 1;
			}	
			
			result = max(result, ret[i]);
			
			std::cout << "after i: " << i << " ret[i]: " << ret[i]  << " result: " << result << std::endl;
		}

		return result;
    }
};

int main() {
	//vector<int> nums = {10,9,2,5,3,7,101,18};
	//vector<int> nums = {2, 2};

	vector<int> nums = {10,9,2,5,3,4};

	Solution *obj = new Solution();
	std::cout << obj->lengthOfLIS_1(nums) << std::endl;

	return 0;
}
