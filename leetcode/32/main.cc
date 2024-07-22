#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp;
        dp.resize(s.size(), 0);
        int max_len = 0;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2]: 0) + 2;
                    //std::cout << "what0  i: " << i  << " dp[i]: " << dp[i] << std::endl; 
                } else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(') {
                    int index = i - dp[i-1] - 1;
                    if (index - 1 >= 0)
                        dp[i] = 2 + dp[i-1] + dp[index - 1];
                    else 
                        dp[i] = 2 + dp[i-1];
                    //std::cout << "what1 index: " << index  << " i: " << i  << " dp[i]: " << dp[i] << std::endl; 
                }
            }
            max_len = std::max(max_len, dp[i]);
        } 

        return max_len;
    }

    int longestValidParentheses1(string s) {
        int max_len = 0;
        stack<int> check;
        check.push(-1);

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                check.push(i);
            }  else {
                check.pop();
                if (check.empty()) {
                    check.push(i);
                } else {
                    max_len = std::max(max_len, i - check.top());
                }
            }
        }

        return max_len;
    }
};

int main() {
    //string str = "(()";
    //string str = "()(())";
    string str = "(()())";

    Solution *test = new Solution();
    std::cout << test->longestValidParentheses(str) << std::endl;
    return 0;
}