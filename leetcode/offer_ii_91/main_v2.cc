#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();

        if (n <= 1) {
            return std::min(std::min(costs[0][1], costs[0][2]), costs[0][0]);
        }

        vector<vector<int>> dp(3);
        for (int i = 0; i < dp.size(); ++i) {
            auto& item = dp[i];
            item.resize(2);
            item[0] = costs[0][i];
        }
    
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                int pre_1 = dp[(j+1)%3][(i-1)%2]; 
                int pre_2 = dp[(j+2)%3][(i-1)%2]; 
                dp[j][i%2] = std::min(pre_1, pre_2) + costs[i][j];
            }
        }

        int last = (costs.size() - 1)%2;
        return std::min(std::min(dp[0][last], dp[1][last]), dp[2][last]);
    }
};

int main() {
    vector<vector<int>> costs = {{17,2,17}, {16,16,5}, {14,3,19}};
    Solution *test = new Solution();
    std::cout << test->minCost(costs) << std::endl;
    return 0;
}