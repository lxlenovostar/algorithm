#include <string>
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> windows;
        int ret = 0;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            char d = s[right];
            windows[d]++;
            right++;

            while (windows[d] > 1) {
                char c = s[left];
                left++;
                windows[c]--; 
            }

            ret = std::max(ret, (right-left));
        }
        return ret;

    }
};

int main() {
    //std::string str = "ADOBECODEBANC";
    //std::string str2 = "ABC";
    //std::string s1 = "ab";
    //std::string s2 = "eidboaooo";
    std::string s = "bbcbbb";
    Solution * test = new Solution();
    std::cout << test->lengthOfLongestSubstring(s) << std::endl;; 

    return 0;
}