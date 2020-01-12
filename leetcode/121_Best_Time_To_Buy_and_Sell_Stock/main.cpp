/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/


#include <vector>
#include <iostream>
#include <limits.h>

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

		vector<int> buy(n, 0);	
		vector<int> sell(n, 0);	

		if (n <= 1)
			return 0;	

		buy[0] = prices[0];

		for (int i = 1; i < n; ++i) {
			std::cout << "what1 prices[i]: " << prices[i] << " buy[i-1] " << buy[i-1]  << " sell[i-1]: " << sell[i-1] << std::endl;

			if (prices[i] < buy[i-1]) { 
				buy[i] = prices[i];
				sell[i] = 0;
			
				std::cout << "what1 buy[i]: " << buy[i] << " sell[i]: " << sell[i] << std::endl;
			} else {
				buy[i] = buy[i-1]; 
				sell[i] = max(sell[i-1], prices[i]);
				
				std::cout << "what2 buy[i]: " << buy[i] << " sell[i]: " << sell[i] << std::endl;
			}	

			ret = max(ret, (sell[i] - buy[i]));

			std::cout << "ret: " << ret << std::endl;
		} // for 

		return ret;

	}
};

int main() {
	//std::vector<int> nums = {7,1,5,3,6,4};
	std::vector<int> nums = {1,2,3,4,5};
	//std::vector<int> nums = {7,6,4,3,1};
	Solution *obj = new Solution(); 
	std::cout << "result: " << obj->maxProfit_1(nums) << std::endl;
	return 0;
}

