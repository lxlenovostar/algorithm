#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        dp.resize(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i  <= amount; ++i) {
            for (auto item : coins) {
                if (i - item >= 0) {
                    dp[i] = std::min(1 + dp[i - item], dp[i]);
                    std::cout << "what0 i:" << i << " dp[i]: " << dp[i] << std::endl;
                }
            } 
           std::cout << "what1 i:" << i << " dp[i]: " << dp[i] << std::endl;
        }

        return dp[amount] > amount ? -1: dp[amount];
    }
};

int main() {
    //vector<int> coins = {1, 2, 5};
    //int amount = 11;
    vector<int> coins = {2};
    int amount = 3;

    Solution *test = new Solution();
    std::cout << test->coinChange(coins, amount) << std::endl;

    return 0;
}