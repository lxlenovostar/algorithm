#include <string>
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0;
        int right = 0;
        int start = 0;
        int len =  INT_MAX;
        int valid = 0; 

        while (right < s.size()) {
            /* 右移滑动窗口 */
            char d = s[right];

            right++;

            if (need.count(d)) {
                window[d]++;
                if (need[d] == window[d])
                    valid++;
            } 

            //std::cout << "left: " << left << " right: " << right << std::endl;
            //std::cout << "valid: " << valid << " need.size(): " << need.size() << std::endl;

            /* 左移滑动窗口 */
            while (valid == need.size()) {
                /*
                 * 统计最后结果
                 */
                if (len > (right - left)) {
                    start = left;
                    len = right - left;
                    //std::cout << "2 left: " << left << " right: " << right << std::endl;
                    //std::cout << "start: " << start << " len: " << len << std::endl;
                }

                char l = s[left];
                left++;
                if (need.count(l)) {
                     if (window[l] == need[l]) {
                         valid--;
                     }
                     window[l]--;
                } 


            }

        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main() {
    //std::string str = "ADOBECODEBANC";
    //std::string str2 = "ABC";
    std::string str = "a";
    std::string str2 = "aa";
    Solution * test = new Solution();
    std::cout << test->minWindow(str, str2) << std::endl; 
    return 0;
}