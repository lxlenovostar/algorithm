#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

    void dfs(vector<int>&nums, int cur, vector<vector<int>>& result) {
        if (cur == nums.size()-1) {
            result.push_back(nums);
        } else {
            std::set<int> datas;
            for (int j = cur; j < nums.size(); ++j) {
                if (datas.find(nums[j]) == datas.end()) {
                    datas.insert(nums[j]);

                    std::swap(nums[cur], nums[j]);
                    dfs(nums, cur+1, result);
                    std::swap(nums[cur], nums[j]);
                }
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        dfs(nums, 0, ret);
        return ret;
    }
};

int main() {
    vector<int> nums = {1,1,2};
    Solution *test = new Solution();

    for (const auto& item: test->permuteUnique(nums)) {
        for (const auto& value: item) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}