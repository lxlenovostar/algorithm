#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        std::map<char, int> s_count;
        std::map<char, bool> in_stack;
        std::stack<char> s_stack;
        std::string ret;

        for (int i = 0; i < s.size(); ++i) {
            s_count[s[i]] += 1;
            in_stack[s[i]] = false;
        }

        for (int i = 0; i < s.size(); ++i) {
            s_count[s[i]] --;

            if (in_stack[s[i]]) continue;

            while (!s_stack.empty() && s[i] < s_stack.top()) {
                if (s_count[s_stack.top()] == 0) {
                    break;
                }  else {
                    in_stack[s_stack.top()]  = false;
                    s_stack.pop();
                }
            }

            s_stack.push(s[i]);
            in_stack[s[i]]  = true;
        }

        while(!s_stack.empty()) {
            ret.insert(0, 1, s_stack.top());
            s_stack.pop();
        }

        return ret;
    }
};

int main() {
    //std::string s = "bcabc";
    //std::string s = "cbacdcbc";
    std::string s = "cdadabcc";
    Solution *test = new Solution();
    std::cout << test->smallestSubsequence(s) << std::endl; 
    return 0;
}