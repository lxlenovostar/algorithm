#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
         f(i) = max(f(i-1), g(i-1))
         g(i) = f(i-1)+nums[i]

         f(0) = 0
         g(0) = nums[0]
         */

        int len = nums.size();
        vector<vector<int>> dp;
        dp.resize(2);
        for (auto& item : dp) {
            item.resize(2);
        }        

        dp[0][0] = 0;
        dp[1][0] = nums[0];

        for (int i = 1; i < len; ++i) {
            dp[0][i%2] = std::max(dp[0][(i-1)%2], dp[1][(i-1)%2]); 
            dp[1][i%2] = dp[0][(i-1)%2] + nums[i]; 
        }

        return std::max(dp[0][(len-1)%2], dp[1][(len-1)%2]);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution *test = new Solution();
    std::cout << test->rob(nums) << std::endl; 
    return 0;
}