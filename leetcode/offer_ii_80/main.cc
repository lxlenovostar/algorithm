#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ret;
    int limit;

    void dfs(vector<int>&nums, int cur) {
        /* 剪枝 */
        if (tmp.size() + (nums.size() - cur + 1) < limit) {
            return;
        }

        if (tmp.size() == limit) {
            ret.push_back(tmp);
            return;
        }

        /* 这里可以删除，由于上面的剪枝 */
        if (cur == nums.size()) {
            return;
        }

        tmp.push_back(nums[cur]);
        dfs(nums, cur+1);

        tmp.pop_back();
        dfs(nums, cur+1);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        limit = k;
        for (int i = 1; i <= n; ++i)
            nums.push_back(i);
        dfs(nums, 0);
        return ret;
    }
};

int main() {
    Solution *test = new Solution();

    for (const auto& item: test->combine(4, 2)) {
        for (const auto& value: item) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}