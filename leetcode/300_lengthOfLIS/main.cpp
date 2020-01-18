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

/*
public class Solution {

    public int lengthOfLIS(int[] nums) {
        return lengthofLIS(nums, Integer.MIN_VALUE, 0);
    }

    public int lengthofLIS(int[] nums, int prev, int curpos) {
        if (curpos == nums.length) {
            return 0;
        }
        int taken = 0;
        if (nums[curpos] > prev) {
            taken = 1 + lengthofLIS(nums, nums[curpos], curpos + 1);
        }
        int nottaken = lengthofLIS(nums, prev, curpos + 1);
        return Math.max(taken, nottaken);
    }
}
*/

/*
public class Solution {
    public int lengthOfLIS(int[] nums) {
        int memo[][] = new int[nums.length + 1][nums.length];
        for (int[] l : memo) {
            Arrays.fill(l, -1);
        }
        return lengthofLIS(nums, -1, 0, memo);
    }
    public int lengthofLIS(int[] nums, int previndex, int curpos, int[][] memo) {
        if (curpos == nums.length) {
            return 0;
        }
        if (memo[previndex + 1][curpos] >= 0) {
            return memo[previndex + 1][curpos];
        }
        int taken = 0;
        if (previndex < 0 || nums[curpos] > nums[previndex]) {
            taken = 1 + lengthofLIS(nums, curpos, curpos + 1, memo);
        }

        int nottaken = lengthofLIS(nums, previndex, curpos + 1, memo);
        memo[previndex + 1][curpos] = Math.max(taken, nottaken);
        return memo[previndex + 1][curpos];
    }
}
*/

class Solution {
public:
	int N;
	int result;

	int recu(vector<int>& nums, int k, int maxvalue) {
		if (k == N) {
			return 0;
		}

		int taken = 0;	
		if (nums[k] > maxvalue)	{
			std::cout << "what1 k: " << k << " nums[k]: " << nums[k]  << " maxvalue: " << maxvalue << std::endl;

			taken = 1 + recu(nums, k+1, nums[k]);  // choice
		} 
			
		std::cout << "what2 k: " << k << " nums[k]: " << nums[k]  << " maxvalue: " << maxvalue << std::endl;

			
		int notaken = recu(nums, k+1, maxvalue);  // not choice

		return max(taken, notaken);
	}

	int recu_mem(vector<int>& nums, int k, int prev_index, vector<vector<int>> &mem) {
		if (k == N) {
			return 0;
		}

		if (mem[prev_index+1][k] != INT_MIN)
			return mem[prev_index+1][k];

		int taken = 0;	
		if (nums[k] > nums[prev_index])	{

			taken = 1 + recu_mem(nums, k+1, k, mem);  // choice
			
			std::cout << "what1 k: " << k  << " prev_index: " << prev_index << " nums[k]: " << nums[k]  << " taken: " << taken << std::endl;

			//mem[prev_index+1][k] = taken;
		} 
			

			
		int notaken;
		notaken = recu_mem(nums, k+1, prev_index,  mem);  // not choice
		
		std::cout << "what2 k: " << k << " prev_index: " << prev_index  << " nums[k]: " << nums[k]  << " notaken: " << notaken << std::endl;

			
		mem[prev_index+1][k] = max(taken, notaken);

		return mem[prev_index+1][k];
	}

    int lengthOfLIS_1(vector<int>& nums) {
		N = nums.size();

		if (N <= 1)
			return N;

		vector<vector<int>> mem;
		mem.resize(N+1);

		for (int i = 0; i < N+1; ++i) {
			mem[i].resize(N);

			for (int j = 0; j < N; ++j) {
				mem[i][j] = INT_MIN;
			}
		}

		return recu_mem(nums, 0, -1, mem);
		//return recu(nums, 0, INT_MIN);
	}

	//DP
    int lengthOfLIS(vector<int>& nums) {
		N = nums.size();
		int result = 1;

		if (N <= 1)
			return N;

		vector<int> ret(N, 1);

		for (int i = 1; i < N; ++i) {
			for (int j = 0; j < i; ++j) {
					if (nums[i] > nums[j])
						ret[i] = max(ret[i], ret[j]+1);
			}


			result = max(result, ret[i]);

		}

		return result;
    }
};

int main() {
	vector<int> nums = {10,9,2,5,3,7,101,18};
	//vector<int> nums = {2, 2};

	//vector<int> nums = {10,9,2,5,3,4};
	//vector<int> nums = {10,9,2,5};

	Solution *obj = new Solution();
	std::cout << obj->lengthOfLIS(nums) << std::endl;

	return 0;
}
