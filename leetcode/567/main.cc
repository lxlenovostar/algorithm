#include <string>
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c : s1) need[c]++;

        int left = 0;
        int right = 0;
        int valid = 0; 

        while (right < s2.size()) {
            /* 右移滑动窗口 */
            char d = s2[right];

            right++;

            if (need.count(d)) {
                window[d]++;
                if (need[d] == window[d])
                    valid++;
            } 

            //std::cout << "1 left: " << left << " right: " << right << std::endl;
            //std::cout << "1 valid: " << valid << " need.size(): " << need.size() << std::endl;

            /* 左移滑动窗口 */
            while (right - left >= s1.size()) {
                /*
                 * 统计最后结果
                 */
                //std::cout << "left: " << left << " right: " << right << std::endl;
                //std::cout << "valid: " << valid << " need.size(): " << need.size() << std::endl;
                //if (valid == need.size() && right - left == s1.size())
                if (valid == need.size() )
                    return true;

                char l = s2[left];
                left++;
                if (need.count(l)) {
                     if (window[l] == need[l]) {
                         valid--;
                     }
                     window[l]--;
                } 

            }

        }

        return false;
    }
};

int main() {
    //std::string str = "ADOBECODEBANC";
    //std::string str2 = "ABC";
    //std::string s1 = "ab";
    //std::string s2 = "eidboaooo";
    std::string s1 = "abcdxabcde";
    std::string s2 = "abcdeabcdx";
    Solution * test = new Solution();
    std::cout << test->checkInclusion(s1, s2) << std::endl; 
    return 0;
}