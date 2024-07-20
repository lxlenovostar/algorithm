#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        int current = 0;
        vector<int> tmp;

        helper(candidates, target, current, ret, tmp);

        return ret; 
    }
private:
    void helper(vector<int>& candidates, int target, int index, vector<vector<int>> &ret, vector<int> &tmp) {
        if (target == 0) {
            ret.push_back(tmp);
            return;
        }

        if (index >= candidates.size() || target < 0) {
            return;
        }

        std::cout << "index: " << index << std::endl;
        tmp.push_back(candidates[index]);
        //helper(candidates, target - candidates[index], index + 1, ret, tmp);
        helper(candidates, target - candidates[index], index, ret, tmp);
        tmp.pop_back();
        helper(candidates, target, index + 1, ret, tmp);
    }
};

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    Solution *test = new Solution();
    auto items = test->combinationSum(candidates, target);
    for (auto item : items) {
        for (auto it: item) {
            std::cout << it << " ";
        }
        std::cout << "\n";
    }
    return 0;
}