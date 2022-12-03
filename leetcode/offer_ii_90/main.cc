#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int helper(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        vector<int> dp(n);

        if (n < 2)
            return nums[start];

        dp[0] = nums[start];
        dp[1] = std::max(nums[start], nums[start+1]);

        for (int i = start+2; i <= end; ++i) {
            int j = i - start;
            dp[j] = std::max(dp[j-2] + nums[i],  dp[j-1]);
        }

        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
         int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }

        int start_0 = helper(nums, 0, length-2);
        int start_1 = helper(nums, 1, length-1);

        return std::max(start_0, start_1);
    }
};

int main() {
    //vector<int> nums = {2,3,2};
    vector<int> nums = {1, 2, 3, 1};
    //vector<int> nums = {200, 3, 140, 20, 10};
    Solution *test = new Solution();
    std::cout << test->rob(nums) << std::endl;
    return 0;
}