#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        std::string ret_stack;
        vector<int> count_ch;
        count_ch.resize(26);
        vector<int> visible;
        visible.resize(26);

        for (char ch: s) {
            count_ch[ch - 'a'] += 1;
        }

        for (char ch: s) {
            if (!visible[ch - 'a']) {
            while(!ret_stack.empty() && count_ch[ret_stack.back() - 'a'] > 0) {
                if (ch < ret_stack.back()) {
                    visible[ret_stack.back() - 'a'] = 0;
                    ret_stack.pop_back();
                } else { 
                    break; 
                }
            }
            
            ret_stack.push_back(ch);
            visible[ch - 'a'] = 1;
            }

            count_ch[ch - 'a'] -= 1;

        }

        return ret_stack;
    }
};

int main() {
    //std::string s = "bcabc";
    std::string s = "cbacdcbc";
    //std::string s = "cdadabcc";
    Solution *test = new Solution();
    std::cout << test->removeDuplicateLetters(s) << std::endl; 
    return 0;
}