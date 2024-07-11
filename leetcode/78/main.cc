#include <iostream>
#include <vector>
#include <map>
#include <algorithm> 
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> ret;
		dfs(nums, 0, ret);
		return sub_ret;
    }
private:
	void dfs(vector<int>& nums, int cur, vector<int>& ret) {
		if (cur == nums.size()) {
			sub_ret.push_back(ret);
		} else {
			ret.push_back(nums[cur]);
			dfs(nums, cur+1, ret);
			ret.pop_back();
			dfs(nums, cur+1, ret);
		}

	}
	vector<vector<int>> sub_ret;
};

int main() {
	vector<int> nums = {1,2,3};
	Solution *test = new Solution();
    for (auto item : test->subsets(nums)) {
        for (auto it: item) {
            std::cout << it << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
