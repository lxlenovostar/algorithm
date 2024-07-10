#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int len = s.size();
        int longest = 0;
        unordered_map<char, int> windows_map;

        while (right < len) {
            char c = s[right];
            windows_map[c]++;
            right++;

            while (windows_map[c] > 1) {
                char c = s[left];
                //清理有重复字符的情况
                windows_map[c]--;
                left++;
            }

            longest = std::max(longest, right - left);
        }

        return longest;

    }
};

int main() {
    string str = "abcabcbb";

    Solution *test = new Solution();
    std::cout << "ret: " << test->lengthOfLongestSubstring(str) << std::endl;
    return 0;
}