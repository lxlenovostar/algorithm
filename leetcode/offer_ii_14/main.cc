#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::vector<int> str_count;

        if (s1.size() > s2.size())
            return false;

        str_count.resize(26);

        for (int i = 0; i < s1.size(); ++i) {
            str_count[s1[i] - 'a']++;
            str_count[s2[i] - 'a']--;
        }

        if (is_zero(str_count))
            return true;


        for (int i = s1.size(); i < s2.size(); ++i) {
            str_count[s2[i] - 'a']--;
            str_count[s2[i - s1.size()] - 'a']++;

            if (is_zero(str_count))
                return true;
        }

        return false;
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
    std::string s1 = "ab";
    //std::string s1 = "adc";
    //std::string s2 = "eidbaooo";
    std::string s2 = "a";
    //std::string s2 = "dcda";

    Solution *test = new Solution();
    std::cout << test->checkInclusion(s1, s2) << std::endl;

    return 0;
}