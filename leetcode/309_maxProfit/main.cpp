/*
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
*/

#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit_1(vector<int>& prices) {
		int n = prices.size();

		if (n <= 1)
			return 0;

		//dp[0-n][0-1 j][0-1 k]
		// j have or not
		// k 1 cold
		//
		//
		//dp[i][1][0] =  max(dp[i-1][1][0], dp[i-1][0][0] - prices[i])
		//dp[i][1][1] = can't exist 
		//
		//dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][0][1])
		//dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][0]+prices[i])


  		int k = 2;
		int s = 2;
	
		vector<vector<vector<long>>> dp;
		dp.resize(n);

		for (int i = 0; i < n; ++i) { 
			dp[i].resize(k);

			for (size_t j = 0; j < dp[i].size(); ++j) {
				dp[i][j].resize(s);
			}
		}

		dp[0][0][1] = 0 - prices[0];
		dp[0][1][1] = INT_MIN;

		dp[0][0][0] = 0;
		dp[0][1][0] = INT_MIN;

		for (int i = 1; i < n; ++i) {
			/*
			dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0] - prices[i]); 
			dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][1][0] - prices[i]);
			
			dp[i][0][0] = dp[i-1][0][0]; 
			dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][1] + prices[i]); 
			dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][1][1] + prices[i]); 
			*/

			dp[i][1][0] =  max(dp[i-1][1][0], dp[i-1][0][0] - prices[i]);

			//dp[i][1][1] = can't exist 
			dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][0][1]);
			//dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][0]+prices[i])
			dp[i][0][1] = dp[i-1][1][0] + prices[i];

		}

		for (int i = 0; i < k; ++i) {
			//std::cout <<  dp[n-1][i][0] << " ";
		}

		//std::cout << std::endl;
 
		int ret_0 = dp[n-1][0][0];
        int ret_1 = dp[n-1][0][1];

        int ret = max(ret_0, ret_1);
		return ret;

    }

	//dp
	int maxProfit(vector<int>& prices) {
		int n = prices.size();

		if (n <= 1)
			return 0;

		//dp[-1][k][0] = dp[i][0][0] = 0
		//dp[-1][k][1] = dp[i][0][1] = -infinity
		
		//dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
		//dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
		
		int dp_i_0 = 0;
		int dp_i_1 = INT_MIN;
		int dp_pre_0 = 0;

		for (int i = 0; i < n; ++i) {
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
			dp_pre_0 = temp;
		}

		return dp_i_0;
	}


};

int main() {
	//std::vector<int> nums = {7,1,5,3,6,4};
	//std::vector<int> nums = {1,2,3,4,5};
	//std::vector<int> nums = {3,3,5,0,0,3,1,4};
	//std::vector<int> nums = {7,6,4,3,1};
	
	//std::vector<int> nums = {2, 1, 2, 0, 1};
	//std::vector<int> nums = {6, 1, 3, 2, 4, 7};
	//std::vector<int> nums = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
	//std::vector<int> nums = {3,3,5,0,0,3,1,4};
	std::vector<int> nums = {1,2,3,0,2};

	Solution *obj = new Solution(); 
	std::cout << "result: " << obj->maxProfit(nums) << std::endl;
	return 0;
}

