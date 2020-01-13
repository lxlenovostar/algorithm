/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。

示例 2:

输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
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

	int maxProfit(int k, vector<int>& prices) {
       	int n = prices.size();		
  		int w = k+1;
		int s = 2;

        if (n <= 1)
            return 0;
            
		vector<vector<vector<long>>> dp;
		dp.resize(n);

		for (int i = 0; i < n; ++i) { 
			dp[i].resize(w);

			for (size_t j = 0; j < dp[i].size(); ++j) {
				dp[i][j].resize(s);
			}
		}

		dp[0][0][1] = 0 - prices[0];
		dp[0][0][0] = 0;
		for (int i = 1; i < w; ++i) {
			dp[0][i][1] = INT_MIN;

			dp[0][i][0] = INT_MIN;
		}
		
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < w; ++j) {
				dp[i][j][1] = max(dp[i-1][j-1][1], dp[i-1][j-1][0] - prices[i]); 

				dp[i][j][0] = max(dp[i-1][j-1][0], dp[i-1][j-1][1] + prices[i]); 

				std::cout << "i: " << i << " j: " << j << " [j][1]: " << dp[i][j][1] << " [j][0]: " << dp[i][j][0] << std::endl;
 			}
		}

		/*
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
		*/

		for (int i = 0; i < w; ++i) {
			std::cout <<  dp[n-1][i][0] << " ";
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
	std::cout << "result: " << obj->maxProfit(2, nums) << std::endl;
	return 0;
}

