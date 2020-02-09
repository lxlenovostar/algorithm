/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	//greedy
    int maxProfit_1(vector<int>& prices) {
		int ret = 0;	
	
		for (size_t i = 1; i < prices.size(); ++i)	{
			if (prices[i] > prices[i-1]) 
				ret += (prices[i] - prices[i-1]);
		}

		return ret;
    }

	//dp
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();

		if (n <= 1)
			return 0;

		//dp[-1][k][0] = dp[i][0][0] = 0
		//dp[-1][k][1] = dp[i][0][1] = -infinity
		
		//dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
		//dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
		
		int dp_i_0 = 0;
		int dp_i_1 = INT_MIN;

		for (int i = 0; i < n; ++i) {
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, temp - prices[i]);
		}

		return dp_i_0;
	}



};

int main() {
	//std::vector<int> nums = {7,1,5,3,6,4};
	//std::vector<int> nums = {1,2,3,4,5};
	std::vector<int> nums = {7,6,4,3,1};
	Solution *obj = new Solution(); 
	std::cout << "result: " << obj->maxProfit(nums) << std::endl;
	return 0;
}

