#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;

        if (intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        int len = intervals.size();
        int cur_start = intervals[0][0];
        int cur_end = intervals[0][1];

        for (int i = 1; i < len; ++i) {
            int next_start = intervals[i][0];
            int next_end = intervals[i][1];

            if (cur_end < next_start) {
                // 连接不成功
                ret.push_back(vector<int>({cur_start, cur_end}));
                cur_start = next_start;
                cur_end = next_end;
            } else {
                if (cur_end <= next_end) {
                    cur_end = next_end;
                } else {
                    // do nothing
                }
            } 
        }
        
        // 这个写的不够优雅
        ret.push_back(vector<int>({cur_start, cur_end}));

        return ret;
    }
};

void print(vector<vector<int>>& vec) {
    for (const auto& item: vec) {
        for (const auto& number: item) {
            std::cout << number << " "; 
        }
        std::cout << std::endl; 
    }
}

int main()
{
    //vector<vector<int>> intervals = {{2, 6}, {1, 3},  {8, 10}, {15, 18}};
    vector<vector<int>> intervals = {{1, 4}, {4, 5}};
    print(intervals);

    Solution * test = new Solution();
    vector<vector<int>> ret = test->merge(intervals);
    std::cout << "ret" << std::endl;
    print(ret);


    return 0;
}