#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ret;
    int limit;

    void dfs(vector<int>&nums, int cur, int cur_value) {
        if (cur_value > limit || cur == nums.size()) {
            return;
        }

        if (cur_value == limit) {
            ret.push_back(tmp);
            return;
        }
        
        /* 不选 */
        dfs(nums, cur+1, cur_value);

        if (cur_value + nums[cur] <= limit) {
            tmp.push_back(nums[cur]);
            dfs(nums, cur, cur_value+nums[cur]);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        limit = target;
        dfs(candidates, 0, 0);
        return ret;
    }
};

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    Solution *test = new Solution();

    for (const auto& item: test->combinationSum(candidates, target)) {
        for (const auto& value: item) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}