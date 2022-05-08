#include <string>
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        unordered_map<char, int> need, window;
        for (char c : p) need[c]++;

        int left = 0;
        int right = 0;
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

            //std::cout << "1 left: " << left << " right: " << right << std::endl;
            //std::cout << "1 valid: " << valid << " need.size(): " << need.size() << std::endl;

            /* 左移滑动窗口 */
            while (right - left >= p.size()) {
                /*
                 * 统计最后结果
                 */
                //std::cout << "left: " << left << " right: " << right << std::endl;
                //std::cout << "valid: " << valid << " need.size(): " << need.size() << std::endl;
                //if (valid == need.size() && right - left == s1.size())
                if (valid == need.size() )
                    ret.push_back(left);

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

        return ret;
    }
};

int main() {
    //std::string str = "ADOBECODEBANC";
    //std::string str2 = "ABC";
    //std::string s1 = "ab";
    //std::string s2 = "eidboaooo";
    std::string s = "abab";
    std::string p = "ab";
    Solution * test = new Solution();
    const vector<int> &ret =  test->findAnagrams(s, p); 
    for (const auto & item : ret) {
        std::cout << item << std::endl;
    }

    return 0;
}