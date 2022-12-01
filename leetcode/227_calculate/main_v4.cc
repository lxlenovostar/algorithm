#include <string>
#include <stack>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        if (s.size() == 1)
            return stoi(s);
        
        int val = 0;
        char pre_op = '+';
        std::stack<int> m_num;
        for (int i = 0; i < s.size(); ++i) {
            char item = s[i];
            //std::cout << "item: " << item << std::endl;
            if (isdigit(item)) {
                val = val*10 + (item - '0');
            } 
            
            if ((!isdigit(item) && item != ' ') || i == s.size() - 1 ) {
                int top_num;
                switch(pre_op) {
                    case '+' :
                        //std::cout << "+ " << val << std::endl;
                        m_num.push(val);
                        break;
                    case '-':
                        //std::cout << "- " << val << std::endl;
                        m_num.push(-val);
                        break;
                    case '*':
                        top_num = m_num.top();
                        //std::cout << "* " << val << " top_num " << top_num << std::endl;
                        m_num.pop();
                        m_num.push(top_num*val);
                        break;
                    default:  
                        top_num = m_num.top();
                        //std::cout << "/ " << val << " top_num " << top_num << std::endl;
                        m_num.pop();
                        m_num.push(top_num/val);
                        break;
                }
                val = 0;
                pre_op = item;
            }
        }

        int sum = 0;
        while(!m_num.empty()) {
            sum += m_num.top();
            m_num.pop();
        }

        return sum;

    }
};

int main() {
    //std::string s = "3+2*2";
    std::string s = " 3/2";
    Solution *test = new Solution();
    std::cout << test->calculate(s) << std::endl;
    return 0;
}