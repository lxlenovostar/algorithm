#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> ret_num;
        std::string ret;
        for (const auto& item: num) {
            while(!ret_num.empty() && ret_num.back() > item && k) {
                ret_num.pop_back();
                k--;
            }

            ret_num.push_back(item);
        }

        for (; k>0; k--) {
            ret_num.pop_back();
        }

        bool is_learding_zero  = true;

        for (const auto& item: ret_num) {
            if (is_learding_zero && item == '0')
                continue;
            is_learding_zero = false;
            ret += item;
        }

        return ret.size() == 0 ? "0" : ret;
    }
};

int main() {
    std::string num = "1432219";
    int k = 3;
    Solution *test = new Solution();
    std::cout << test->removeKdigits(num, k) << std::endl;
    return 0;
}