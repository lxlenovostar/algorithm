/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*/

#include <iostream>
#include <vector>

#include <limits.h>

using namespace std;

class Solution {
public:
	int ret_max;
	int N; 

	void recursion(vector<int>& nums, int pos, int val) {
		if (pos >= N) {
			std::cout << "pos0: " << pos << " val: " << val << " ret_max: " << ret_max << std::endl;
			if (val > ret_max)
				ret_max = val;
			return;
		}

		if (val > ret_max)
			ret_max = val;

		std::cout << "pos1: " << pos << " val: " << val << " ret_max: " << ret_max << std::endl;

		val = nums[pos]*val ;

		if (val > ret_max)
			ret_max = val;

		
		std::cout << "pos2: " << pos << " val: " << val << " ret_max: " << ret_max << std::endl;

		recursion(nums, pos+1, val);

		return;
	}
    
	int maxProduct(vector<int>& nums) {
		ret_max = INT_MIN;
		N = nums.size();

		if (nums.size() == 1)
			return nums[0];

		for (int i = 0; i < N; ++i) {
			recursion(nums, i+1, nums[i]);

			std::cout << std::endl;
		}

		return ret_max;

    }

    int maxProduct_2(vector<int>& nums) {
		 int n = nums.size();
        int ans = INT_MIN;
        int max_v = 1, min_v = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) swap(max_v, min_v);
            max_v = max(max_v * nums[i], nums[i]);
            min_v = min(min_v * nums[i], nums[i]);
            ans = max(max_v, ans);
        }
        return ans;
	}

    int maxProduct_1(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		
		N = nums.size();
		ret_max = INT_MIN;
	
		vector<int> dp_max;
		vector<int> dp_min;

		for (int i = 0; i < N; ++i) {
			dp_max.push_back(nums[i]);	
			dp_min.push_back(nums[i]);	
		}

		ret_max = max(ret_max, dp_max[0]);

		for (int i = 1; i < N; ++i) {
			std::cout << "before dp_max[i]: " << dp_max[i] << " dp_min[i]: " << dp_min[i] << " i: " << i << std::endl;

			/*
			if (nums[i] > ret_max)
				ret_max = nums[i];

			if (nums[i] == 0) {
				int val = max(dp_max[i-1], nums[i]);
				if (val > ret_max)
					ret_max = val;
				++i;
			} else if (nums[i] > 0) {
				dp_max[i] = dp_max[i-1] * nums[i];
				dp_min[i] = dp_min[i-1] * nums[i];
			} else {
				dp_max[i] = dp_min[i-1] * nums[i];
				dp_min[i] = dp_max[i-1] * nums[i];
			}	

			if (dp_max[i] > ret_max)
				ret_max = dp_max[i];
			*/
				
			dp_max[i] = max(dp_max[i-1] * nums[i], dp_min[i-1] * nums[i]);
			dp_max[i] = max(dp_max[i], nums[i]);
			dp_min[i] = min(dp_max[i-1] * nums[i], dp_min[i-1] * nums[i]);
			dp_min[i] = min(dp_min[i], nums[i]);

			ret_max = max(ret_max, dp_max[i]);
			
			std::cout << "after dp_max[i]: " << dp_max[i] << " dp_min[i]: " << dp_min[i]  << " ret_max: " << ret_max << std::endl;

		}

			return ret_max;
    }
};


int main() {
	//vector<int> nums = {2, 3, -2, 4};
	//vector<int> nums = {-2, 0, -1};
	//vector<int> nums = {2, 0, 1};
	//vector<int> nums = {2, 3, 4, 0, 1, 2};
	//vector<int> nums = {-2, 3, -4};
	//vector<int> nums = {0, 2};
	//vector<int> nums = {-3, 0, 1, -2};
	//vector<int> nums = {6, 3, -10, 0, 2};
	//vector<int> nums = {2, -5, -2, -4, 3};
	vector<int> nums = {2, -1, 1, 1};

	Solution *obj = new Solution();
	std::cout << obj->maxProduct_1(nums) << std::endl;

	return 0;
}

