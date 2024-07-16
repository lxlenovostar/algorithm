#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.resize(nums.size(), 1);
        int max = 1;

        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j]+1);
                }
            }
            max = std::max(max, dp[i]);
        }

        return max;
    }
};

int main() {
    //vector<int> nums = {10,9,2,5,3,7,101,18};
    //vector<int> nums = {0,1,0,3,2,3};
    vector<int> nums = {7,7,7,7,7,7,7}; 

    Solution *test = new Solution();
    std::cout << test->lengthOfLIS(nums) << std::endl;

    return 0;
}