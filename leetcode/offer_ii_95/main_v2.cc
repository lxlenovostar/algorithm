#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        /*
         f(i, j) = f(i-1, j-1) + 1  if s[i] == s[j]
         f(i, j) = max(f(i-1, j), f(i, j-1)) if s[i] != s[j]
         */

        int len1 = text1.size();
        int len2 = text2.size();

        vector<vector<int>> dp;
        dp.resize(2);
        for (auto& item: dp) {
            item.resize(len2+1);
        }

        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (text1[i] == text2[j]) {
                    dp[(i+1)%2][j+1] = dp[i%2][j] + 1;
                } else {
                    dp[(i+1)%2][j+1] = std::max(dp[(i+1)%2][j], dp[i%2][j+1]);
                }
            }
        }

        return dp[len1%2][len2];
    }

};

int main() {
    std::string text2 = "ace"; 
    std::string text1 = "abcde";

    Solution *test = new Solution();
    std::cout << test->longestCommonSubsequence(text1, text2) << std::endl;

    return 0;
}

