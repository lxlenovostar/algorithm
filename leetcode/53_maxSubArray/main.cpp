/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray_1(vector<int>& nums) {
		int max_value = INT_MIN;
		int len = nums.size();

		if (len == 0)
			return max_value;
		
		vector<int> dp;	
		dp.resize(len);

		dp[0] = max(nums[0], max_value);

		if (dp[0] > max_value)
			max_value = dp[0];

		std::cout << "i: 0" << " dp: " << dp[0] << std::endl;

		//dp[i+1] = max(nums[i], dp[i]+nums[i])
		for (int i = 1; i < len; ++i)	{

			dp[i] = max(nums[i], dp[i-1]+nums[i]);
		
			std::cout << "i: " << i  << " dp: " << dp[i] << " " << max_value <<  std::endl;

			if (dp[i] > max_value)
				max_value = dp[i];

		}

		return max_value;
	}

/*
	class Solution {
  	public int crossSum(int[] nums, int left, int right, int p) {
    	if (left == right) return nums[left];

    	int leftSubsum = Integer.MIN_VALUE;
    	int currSum = 0;
    	for(int i = p; i > left - 1; --i) {
      		currSum += nums[i];
      		leftSubsum = Math.max(leftSubsum, currSum);
    	}

    	int rightSubsum = Integer.MIN_VALUE;
    	currSum = 0;
    	for(int i = p + 1; i < right + 1; ++i) {
      		currSum += nums[i];
      		rightSubsum = Math.max(rightSubsum, currSum);
    	}

    	return leftSubsum + rightSubsum;
  	}

  	public int helper(int[] nums, int left, int right) {
    	if (left == right) return nums[left];

    	int p = (left + right) / 2;

    	int leftSum = helper(nums, left, p);
    	int rightSum = helper(nums, p + 1, right);
    	int crossSum = crossSum(nums, left, right, p);

    	return Math.max(Math.max(leftSum, rightSum), crossSum);
  	}

  	public int maxSubArray(int[] nums) {
    	return helper(nums, 0, nums.length - 1);
  	}
}
*/

	int crossSum(vector<int>& nums, int left, int right, int p, int level) {
		++level;
		std::cout << "cross left: " << left << " p: " << p << " right: " << right << " level: " << level << std::endl;

		if (left == right)
			return nums[left];

		int leftSubsum = INT_MIN;
		int currSum = 0;
		for (int i = p; i > left - 1; --i) {
			currSum += nums[i];
			leftSubsum = max(leftSubsum, currSum);
		}
	
		int rightSubsum = INT_MIN;
		currSum = 0;
		for (int i = p+1; i < right + 1; ++i) {
			currSum += nums[i];
			rightSubsum = max(rightSubsum, currSum);
		}

		return leftSubsum + rightSubsum;

	}

	int divide(vector<int>& nums, int left, int right, int level) {
		int p = (left + right) / 2;

		++level;
		std::cout << "divide left: " << left << " p: " << p << " right: " << right << " level: " << level << std::endl;

		if (left == right)
			return nums[left];

		int leftSum = divide(nums, left, p, level);
		int rightSum = divide(nums, p+1, right, level);
		int crosssum = crossSum(nums, left, right, p, level);


		int max_value = max(leftSum, rightSum);
		max_value = max(max_value, crosssum);

		return max_value; 
	}

    int maxSubArray(vector<int>& nums) {
		int len = nums.size();

		int level = 0;

		return divide(nums, 0, len-1, level);
	}
};

int main() {
	Solution *obj = new Solution();
	//vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	//vector<int> nums = {4,-1,2,1};
	vector<int> nums = {0, 1, 2, 3, 4, 5};

	std::cout << obj->maxSubArray(nums) << std::endl; 

	return 0;
}
