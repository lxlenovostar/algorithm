/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1

示例 2:

输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。
*/

#include <algorithm>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
	
	//gready 
    int coinChange_1(vector<int>& coins, int amount) {

		//sort coins
		sort(coins.begin(), coins.end(), greater<int>());

		int result = 0;
		int len = coins.size();

		vector<int> ret(len, 0);

		for (int i = 0; i < len; ++i) {
			if (amount == 0)
				break;

			int count = 0;

			while (amount >= 0) {
				amount -= coins[i];
				count++;
			}	

			if (amount < 0  && count >= 1) {
				count--;
				amount += coins[i];
			}

			std::cout << "i: " << i << " count: " << count << " amount: " << amount << std::endl;

			ret[i] = count;
		} 

		for (size_t i = 0; i < ret.size(); ++i) {
			std::cout << "end i: " << i << " ret[i]: " << ret[i] <<  " result:" << result << std::endl;
			result += ret[i];	
		}

		if (amount == 0)
			return result;
		else 
			return -1;
    }
    
	int coinChange(vector<int>& coins, int amount) {
		
		//dp[i] = dp[i]
		//
		//dp[11] = min( dp[10] + 1, dp [9] + 2,  dp[6] + 5  )
		//
		//dp[i] = min(dp[i - 1] + 1, dp[i - 2] + 1, dp[i - 5] + 1)
		//
		//dp[0] = -1;
		//dp[1] = 1;
		//dp[2] = 1;
		//dp[3] = 2;
		//dp[4] = 2;
		//dp[5] = 1;
		//dp[6] = 2;

		int Max = amount + 1;
		int coins_len = coins.size();

		vector<int> dp(amount+1, Max);
		dp[0]  = 0;	

		for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j < coins_len; ++j) {
				std::cout << " j: " << i << " coins[j]: " << coins[j] << std::endl;
				if (i >=  coins[j]) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				} // if

			} // for 
			
			std::cout << " i: " << i << " dp[i]: " << dp[i] << std::endl;
		}

		return dp[amount] > amount ? -1 : dp[amount];
	}
};

int main() {
		//vector<int> coins = {1, 2, 5}; 
		//int amount = 11;
		//vector<int> coins = {2}; 
		//int amount = 3;
		vector<int> coins = {186, 419, 83, 408}; 
		int amount = 6249;  //ret 20

		Solution *obj = new Solution();
		std::cout << obj->coinChange(coins, amount) << std::endl;
		return 0;
}


