#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(2);

        if (n < 2)
            return nums[0];

        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i <= nums.size() - 1; ++i) {
            dp[i%2] = std::max(dp[(i-2)%2] + nums[i],  dp[(i-1)%2]);
            //std::cout << "i: " << i << " dp[i]: " << dp[i] << std::endl; 
        }

        int last = (nums.size() - 1) % 2;
        return dp[last];
    }
};

int main() {
    vector<int> nums = {1,2,3,1};
    //vector<int> nums = {0};
    Solution *test = new Solution();
    std::cout << test->rob(nums) << std::endl;
    return 0;
}