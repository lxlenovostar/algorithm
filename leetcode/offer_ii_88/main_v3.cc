#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i <= cost.size() - 1; ++i) {
            dp[i] = std::min(dp[i-2], dp[i-1]) + cost[i];
        }

        return std::min(dp[n-1], dp[n-2]);
    }
};

int main() {
    vector<int> cost = {1, 100};
    Solution *test = new Solution();
    std::cout << test->minCostClimbingStairs(cost) << std::endl;
    return 0;
}