#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 1;
        std::vector<char> str_count;
        
        str_count.resize(256);

        if (s.size() <= 1)
            return s.size();

        int right = 0;
        int left = 0;
        for (; right < s.size(); ++right) {
            str_count[s[right]]++;

            while (is_only(str_count) == false && left < right) {
                str_count[s[left]]--;
                left++;
            }
            
            ret = std::max(ret, right - left + 1);
            
        }


        return ret;
    }

private:
    bool is_only(const vector<char>& str_count) {
        for (const auto & item : str_count) {
            if (item > 1)
                return false;
        }

        return true;
    }
};

int main() {
    //std::string s = "abcabcbb";
    std::string s = "  ";
    //std::string s1 = "adc";
    //std::string s2 = "eidbaooo";
    //std::string s2 = "dcda";

    Solution *test = new Solution();
    std::cout << test->lengthOfLongestSubstring(s) << std::endl;

    return 0;
}