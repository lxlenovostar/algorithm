#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    std::string getPalindrome(const string & s, int i, int j) {
        while (i >= 0 && j <= s.size() -1 && s[i] == s[j]) {
            --i;
            ++j;
        }
        return std::string(s, i+1, j-i-1);
    }

    string longestPalindrome(string s) {
        std::string ret;
        for (int i = 0; i < s.size(); ++i) {
            std::string str_1 = getPalindrome(s, i, i);
            std::string str_2 = getPalindrome(s, i, i+1);

            std::string tmp = str_1.size() > str_2.size() ? str_1 : str_2;
            ret = tmp.size() > ret.size() ? tmp : ret; 
        }

        return ret;
    }
};

int main() {
    //std::string str = "babad";
    std::string str = "cbbd";
    Solution * test = new Solution();
    std::cout << test->longestPalindrome(str) << std::endl; 
    return 0;
}