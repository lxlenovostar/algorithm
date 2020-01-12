/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。

示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

示例 3:

输入: [7,6,4,3,1] 
输出: 0 
解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
*/


#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int ret = 0;	
	
		int buy = 0;
		int sell = 0;
		for (size_t i = 0; i < prices.size(); ++i)	{
			buy = prices[i];

			for (size_t j = i+1; j < prices.size(); ++j) {
				sell = prices[j];

				if (sell > buy) {
					int profit = sell - buy;
					if (profit > ret)
						ret = profit;
				}
				
			}
		}

		return ret;
        
    }
    
	int maxProfit_1(vector<int>& prices) {
		int n = prices.size();
		int ret = 0;

		vector<int> ret_max;
		vector<int> buy(n, 0);	
		vector<int> sell(n, 0);	

		if (n <= 1)
			return 0;	

		buy[0] = prices[0];

		for (int i = 1; i < n; ++i) {
			std::cout << "what0 prices[i]: " << prices[i] << " buy[i-1] " << buy[i-1]  << " sell[i-1]: " << sell[i-1] << std::endl;

			if (prices[i] < prices[i-1]) { 
				std::cout << "what 0.5 ret:" << ret << std::endl;
				ret_max.push_back(ret);

				buy[i] = prices[i];
				sell[i] = 0;
				ret = 0;
			
				std::cout << "what1 buy[i]: " << buy[i] << " sell[i]: " << sell[i] << std::endl;
			} else {
				buy[i] = buy[i-1]; 
				sell[i] = max(sell[i-1], prices[i]);
				
				std::cout << "what2 buy[i]: " << buy[i] << " sell[i]: " << sell[i] << std::endl;
			}	

			ret = max(ret, (sell[i] - buy[i]));

			std::cout << "ret: " << ret << std::endl;
		} // for 
				
		std::cout << "what 2.5 ret:" << ret << std::endl;
		ret_max.push_back(ret);

		sort(ret_max.begin(), ret_max.end(), std::greater<int>());

		int max_ret = 0; 
		int len = ret_max.size();
		int index = min(2, len);
		//for (int i = 0; i < index; ++i) {
		for (size_t i = 0; i < ret_max.size(); ++i) {
			std::cout <<  ret_max[i] << " ";
			max_ret += ret_max[i];
		}
		std::cout << endl;

		return max_ret;

	}

	int maxProfit_2(vector<int>& prices) {
	 	int n = prices.size();		
  		int k = 3;
		int s = 2;

        if (n <= 1)
            return 0;
            
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
		dp[0][2][1] = INT_MIN;

		dp[0][0][0] = 0;
		dp[0][1][0] = INT_MIN;
		dp[0][2][0] = INT_MIN;

		for (int i = 1; i < n; ++i) {
			dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0] - prices[i]); 
			dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][1][0] - prices[i]);
			
			dp[i][0][0] = dp[i-1][0][0]; 
			dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][1] + prices[i]); 
			dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][1][1] + prices[i]); 
		}

		for (int i = 0; i < k; ++i) {
			//std::cout <<  dp[n-1][i][0] << " ";
		}

		//std::cout << std::endl;
 
		int ret_0 = dp[n-1][0][0];
        int ret_1 = dp[n-1][1][0];
		int ret_2 = dp[n-1][2][0];

        int ret = max(ret_0, ret_1);
        ret = max(ret, ret_2);
		return ret;
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
	std::vector<int> nums = {1,2,3,4,5};

	Solution *obj = new Solution(); 
	std::cout << "result: " << obj->maxProfit_2(nums) << std::endl;
	return 0;
}

