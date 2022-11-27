#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void helper(vector<int>& cost, int index, vector<int>& dp) {
        if (index < 2) {
            std::cout << "what1 index: " << index << std::endl;
            dp[index] = cost[index];
        }
        else if (dp[index] == 0) {
            std::cout << "what2" << std::endl;
            helper(cost, index-2, dp);
            helper(cost, index-1, dp);
            dp[index] = std::min(dp[index-1], dp[index-2]) + cost[index];
        }
        
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);

        helper(cost, n-1, dp);

        std::cout << "dp[0]: " << dp[0] << " dp[1]:" << dp[1] << std::endl;
        return std::min(dp[n-1], dp[n-2]);
    }
};

int main() {
    vector<int> cost = {1, 100};
    Solution *test = new Solution();
    std::cout << test->minCostClimbingStairs(cost) << std::endl;
    return 0;
}