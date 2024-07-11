#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;

        dfs(nums, 0, ret);
        return ret;
    }
private:
    void dfs(vector<int> nums, int cur, vector<vector<int>> &permute_values) {
        if (cur == nums.size() -1) {
            permute_values.push_back(nums);
            return;
        } else {
            for (int i = cur; i < nums.size(); ++i) {
                std::swap(nums[i], nums[cur]);
                dfs(nums, cur+1, permute_values);
                std::swap(nums[i], nums[cur]);
            }
        }

    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution *test = new Solution();
    for (auto item : test->permute(nums)) {
        for (auto it: item) {
            std::cout << it << " ";
        }
        std::cout << "\n";
    }
    return 0;
}