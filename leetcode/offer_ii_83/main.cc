#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ret;

    void dfs(vector<int>&nums, int cur) {
        if (tmp.size() == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        
        /*  不选 */
        dfs(nums, cur+1);

        tmp.push_back(nums[cur]);
        dfs(nums, cur+1);
        tmp.pop_back();

    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
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