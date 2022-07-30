#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isPalindrome(const std::string& str, int begin, int end) {
        while(begin < end) {
            if (str[begin++] != str[end--])
                return false;
        }
        return true;
    }

    void helper(const std::string& str, int index, vector<std::string> ret, vector<vector<string>>& result) {
        if (index == str.size()) {
            result.push_back(ret);
        } else {
            for (int j = index; j < str.size(); ++j) {
                if (isPalindrome(str, index, j)) {
                    ret.emplace_back(str.substr(index, j - index + 1));
                    helper(str, j+1, ret, result);
                    ret.pop_back();
                }
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> rets;
        vector<string> ret;
        helper(s, 0, ret, rets);
        return rets;
    } 
    
};

int main() {
    Solution *test = new Solution();

    for (const auto& items: test->partition("google")) {
        for (const auto& item: items) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}