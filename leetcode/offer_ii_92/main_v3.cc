#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int len = s.size();
        if (len == 0)
            return 0;


        vector<vector<int>> dp;
        dp.resize(2);
        for (auto & item: dp) {
            item.resize(2);
        }

        /*
            if s[i] == 0
                f[i] = f[i-1]
            else 
                f[i] = f[i-1] + 1

            if s[i] == 0
                g[i] = min(g[i-1], f[i-1]) + 1
            else 
                g[i] = min(g[i-1], f[i-1])
         */

        if (s[0] == '0') {
            dp[0][0] = 0;
            dp[1][0] = 1; 
        } else {
            dp[0][0] = 1; 
            dp[1][0] = 0; 
        }

        std::cout << "0 " << dp[0][0] << " " << dp[1][0] << std::endl;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                dp[0][i%2] = dp[0][(i-1)%2];
                dp[1][i%2] = std::min(dp[1][(i-1)%2], dp[0][(i-1)%2]) + 1;
            } else {
                dp[0][i%2] = dp[0][(i-1)%2] + 1;
                dp[1][i%2] = std::min(dp[1][(i-1)%2], dp[0][(i-1)%2]);
            }
        
            std::cout << i << " " << dp[0][i%2] << " " << dp[1][i%2] << std::endl;
        }

        return std::min(dp[0][(len-1)%2], dp[1][(len-1)%2]);
    }
};

int main() {
    std::string s = "00110";
    Solution *test = new Solution();
    std::cout << test->minFlipsMonoIncr(s) << std::endl;
    return 0;
}