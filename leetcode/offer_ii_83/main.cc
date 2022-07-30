#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void dfs(vector<int>&nums, int cur, vector<vector<int>>& result) {
        if (cur == nums.size()-1) {
            result.push_back(nums);
        } else {
            for (int j = cur; j < nums.size(); ++j) {
                std::swap(nums[cur], nums[j]);
                dfs(nums, cur+1, result);
                std::swap(nums[cur], nums[j]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        dfs(nums, 0, ret);
        return ret;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution *test = new Solution();

    for (const auto& item: test->permute(nums)) {
        for (const auto& value: item) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}