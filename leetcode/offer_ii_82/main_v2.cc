#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
    int m_target;
    vector<vector<int>> ret;

    void dfs(vector<int>& candidates, int index, vector<int>& tmp, int value) {
        if (value == m_target) {
            ret.push_back(tmp);
            return;
        } 
        
        if (index > candidates.size() - 1) {
            return;
        }

        if (value > m_target) {
            return;
        }

        std::cout << "index: " << index << " cand:" << candidates[index] << " value:" << value << std::endl;
        tmp.push_back(candidates[index]);
        dfs(candidates, index+1, tmp, value+candidates[index]);
        tmp.pop_back();
        /* 跳过重复的值 */
        index = get_next(candidates, index);
        dfs(candidates, index, tmp, value);
    }

    int get_next(vector<int>& candidates, int index) {
        int cur_value = candidates[index];

        while(index <= candidates.size() -1  && candidates[index] == cur_value) {
            index++;
        }

        return index;

    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());

        m_target = target;

        vector<int> tmp;
        int index = 0;
        dfs(candidates, index, tmp, 0);

        return ret;
    }
};

int main() {
    //vector<int> candidates = {2, 2, 2, 4, 3, 3};
    vector<int> candidates = {1, 2, 2, 5};
    //vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 5;

    Solution *test = new Solution();

    for (const auto& items: test->combinationSum2(candidates, target)) {
        for (const auto& item: items) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }    
}