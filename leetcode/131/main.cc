#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        string tmp_str;
        vector<string> tmp_ret;
        helper(tmp_ret, s, 0);

        return ret;
    }
private:
    void helper(vector<string>& tmp_ret, const string& str, int current) {
        if (current > str.size()-1) {
            if (check_right(tmp_ret)) {
                ret.push_back(tmp_ret);
            }
        }

        for (int i = current; i < str.size(); ++i) {
            string tmp_str = str.substr(current, i-current+1); // 可以在这里检查回文字符串
            tmp_ret.push_back(tmp_str);
            helper(tmp_ret, str, i+1);
            tmp_ret.pop_back();
        }

    }

    bool check_right(vector<string>& strs) {
        for (auto & str: strs) {
            int begin = 0;
            int end = str.size() - 1;

            while(begin < end) {
                if (str[begin] != str[end])
                    return false;

                begin++;
                end--;
            }
        }

        return true;
    }
private:
    vector<vector<string>> ret;
};

int main() {
    string s = "aab";
    Solution *test = new Solution();
    auto ret = test->partition(s);
    for (auto &item : ret) {
        for (auto &str : item) {
            std::cout << str << std::endl;
        }
    }
    return 0;
}