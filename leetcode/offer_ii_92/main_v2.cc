#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        if (n <= 1) {
            return 0;
        }

        vector<vector<int>> dp(2);
        for (int i = 0; i < dp.size(); ++i) {
            auto& item = dp[i];

            item.resize(2);
        }

        if (s[0] == '0') {
            dp[0][0] = 0;
            dp[1][0] = 1;
        } else {
            dp[0][0] = 1;
            dp[1][0] = 0;
        } 

        for (int i = 1; i < n; ++i) {
            dp[0][i%2] = dp[0][(i-1)%2] + (s[i] == '0' ? 0 : 1);
            dp[1][i%2] = std::min(dp[0][(i-1)%2], dp[1][(i-1)%2]) + (s[i] == '1' ? 0 : 1); 
            std::cout << "i: " << i << " val:" << int(s[i] - '0') << std::endl;
            std::cout << "dp[0][i%2]: " << dp[0][i%2] << " dp[1][i%2]:" << dp[1][i%2] << std::endl;
        }

        int last = (s.size() - 1)%2;
        return std::min(dp[0][last], dp[1][last]);
    }
};

int main() {
    //std::string s = "00110";
    std::string s = "010110";
    Solution *test = new Solution();
    std::cout << test->minFlipsMonoIncr(s) << std::endl;
    return 0;
}