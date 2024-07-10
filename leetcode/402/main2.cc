#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.size();
        stack<int> tmp_stack;

        if (len < k)
            return ""; 
        
        for (int i = 0; i < len; ++i) {
            while(!tmp_stack.empty() && k > 0 && (num[i] - '0') < tmp_stack.top()) {
                tmp_stack.pop();
                k--;
            }

            tmp_stack.push(num[i] - '0');
        }

        while (k > 0 && !tmp_stack.empty()) {
            k--;
            tmp_stack.pop();
        } 

        stack<int> ret_stack;
        while(!tmp_stack.empty()) {
            ret_stack.push(tmp_stack.top());
            tmp_stack.pop();
        }
        
        std::string ret;
        bool is_lead_zero = true;
        while(!ret_stack.empty()) {
            if (ret_stack.top() == 0 && is_lead_zero) {
                ret_stack.pop();
                continue;
            }

            is_lead_zero = false;
            auto tmp = std::to_string(ret_stack.top());
            ret += tmp;
            ret_stack.pop();
        }

        return ret.size() == 0 ? "0" : ret;

    }
};

int main() {
    //string num = "10";
    //int k = 2;
    string num = "123456789";
    int k = 1;
    //string num = "1432219";
    //int k = 3;
    //string num = "10200";
    //int k = 1;
    Solution *test = new Solution();
    std::cout << "ret: " << test->removeKdigits(num, k) << std::endl; 
    return 0;
}