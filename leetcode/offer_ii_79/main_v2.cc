#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> tmp;
    vector<vector<int>> ret;

    void dfs(vector<int>& nums, int index) {
        if (index > nums.size() - 1) {
            ret.push_back(tmp);
            return;
        }
            
        dfs(nums, index+1);
        tmp.push_back(nums[index]);
        dfs(nums, index+1);
        tmp.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution *test = new Solution();
    for (const auto& item : test->subsets(nums)) {
        for (const auto& value: item) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}