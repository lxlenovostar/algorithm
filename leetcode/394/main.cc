#include <string>
#include <stack>
#include <iostream>

using namespace std;

// 别人的解法
class Solution {
public:
    string decodeString(string s) {
        stack<string> str_stack;
        stack<int> digit_stack;
        string current_str;
        int k;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                k = k * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                digit_stack.push(k);
                std::cout << "what0: " << current_str << std::endl;
                std::cout << "what1 k: " << k << std::endl;
                str_stack.push(current_str);
                current_str = "";
                k = 0;
            } else if (s[i] == ']') {
                std::cout << "what2: " << current_str << std::endl;
               auto temp = str_stack.top();
               str_stack.pop();
               int repeat = digit_stack.top();
               digit_stack.pop();
               for (int i = 0; i < repeat; ++i) {
                    temp += current_str;
               } 
               current_str = temp;
            } else {
                current_str += s[i];
            }

        }

        return current_str; 
    }
};

int main() {
    //string str = "3[a]2[bc]";
    string str = "3[a2[c]]";
    Solution *test = new Solution();
    std::cout << test->decodeString(str) << std::endl;
    return 0;
}