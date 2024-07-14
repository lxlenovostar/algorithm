#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> check_dict;
        for (auto item: wordDict) {
            check_dict.insert(item);
        }

        vector<bool> dp;
        dp.resize(s.size() + 1);
        dp[0] = true;

        for (size_t i = 1; i <= s.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (dp[j] && check_dict.find(s.substr(j, i-j)) != check_dict.end()) {
                    dp[i] = true;
                }
            }
        }

        return dp[s.size()];
    }
};

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution *test = new Solution();
    std::cout << "ret: " << test->wordBreak(s, wordDict) << std::endl;
    return 0;
}