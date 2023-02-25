#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int len = arr.size();
        if (len == 0)
            return 0;


        std::map<int , int> dict_index;
        for (int i = 0; i < arr.size(); ++i) {
            dict_index[arr[i]] = i;
        }

        /*
            f(i, j) = f(j, k) + 1
        */

        vector<vector<int>> dp;
        dp.resize(len);
        for (auto & item: dp) {
            item.resize(len);
        }

        int result = 2;
        for (int i = 1; i <= len - 1; ++i) {
            for (int j = 0; j < i; ++j) {
                int k = dict_index.find(arr[i] - arr[j]) == dict_index.end() ? -1 : (dict_index.at(arr[i] - arr[j]));
                dp[i][j] = k >= 0 && k < j ? dp[j][k]  + 1 : 2;
                result = std::max(result, dp[i][j]);
            }
        }

        return result >= 3 ? result : 0;
    }
};

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution *test = new Solution();
    std::cout << test->lenLongestFibSubseq(a) << std::endl;
    return 0;
}