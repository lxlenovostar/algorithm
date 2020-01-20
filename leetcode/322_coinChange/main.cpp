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

using namespace std;

class Solution {
public:
	
	//gready 
    int coinChange(vector<int>& coins, int amount) {

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
};

int main() {
		//vector<int> coins = {1, 2, 5}; 
		//int amount = 0;
		//vector<int> coins = {2}; 
		//int amount = 3;
		vector<int> coins = {186, 419, 83, 408}; 
		int amount = 6249;  //ret 20

		Solution *obj = new Solution();
		std::cout << obj->coinChange(coins, amount) << std::endl;
		return 0;
}
