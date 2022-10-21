#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        std::vector<int> ret;
        std::vector<int> str_count;

        if (s.size() < p.size())
            return ret;

        str_count.resize(26);

        for (int i = 0; i < p.size(); ++i) {
            str_count[p[i] - 'a']++;
            str_count[s[i] - 'a']--;
        }

        if (is_zero(str_count)) {
            ret.push_back(0);
        }

        for (int i = p.size(); i < s.size(); ++i) {
            str_count[s[i] - 'a']--;
            str_count[s[i - p.size()] - 'a']++;

            if (is_zero(str_count)) { 
                ret.push_back(i - p.size() + 1);
            }
        }

        return ret;
    }

private:
    bool is_zero(const vector<int>& str_count) {
        for (const auto & item : str_count) {
            if (item != 0)
                return false;
        }

        return true;
    }
};

int main() {
    std::string s = "abab";
    //std::string s1 = "adc";
    //std::string s2 = "eidbaooo";
    std::string p = "ab";
    //std::string s2 = "dcda";

    Solution *test = new Solution();
    for (const auto& item : test->findAnagrams(s, p))
        std::cout << item << std::endl;

    return 0;
}