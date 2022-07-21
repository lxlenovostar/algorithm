#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> tmp;
    vector<pair<int, int>> freq;
    vector<vector<int>> ret;

    void dfs(int cur, int cur_value) {
        if (cur_value == 0) {
            ret.push_back(tmp);
            return;
        }

        /* 剪枝 */
        if (cur == freq.size() || cur_value < freq[cur].first) {
            return;
        }

        /* 不选 */
        dfs(cur + 1, cur_value);

        int most = std::min(freq[cur].second, cur_value/freq[cur].first); 

        for (int i = 1; i <= most; ++i) {
            tmp.push_back(freq[cur].first);
            dfs(cur + 1, cur_value - i*freq[cur].first);
        }

        for (int i = 1; i <= most; ++i) {
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        for (const auto& num: candidates) {
            if (freq.empty() || num != freq.back().first) {
                freq.emplace_back(num, 1);
            } else {
                ++freq.back().second;
            }
        }

        dfs(0, target);
        return ret;
    }
};

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5}; 
    int target = 8;

    Solution *test = new Solution();


    for (const auto& item: test->combinationSum2(candidates, target)) {
        for (const auto& value: item) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}