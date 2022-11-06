#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ret = 0;
        std::stack<int> s;

        for (const auto& item : tokens) {
            if (item != "+" && item != "-" && item != "*" && item != "/") {
                std::cout << "what1 item:" << item << std::endl;
                s.push(stoi(item));
            } else {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(get_val(left, right, item));
                std::cout << "what2 item:" << item << std::endl;
            }            
        }

        return  s.top();
    }

private:
    int get_val(int left, int right, const string& op) {
            if (op == "+")
                return left + right;

            if (op == "-")
                return left - right;

            if (op == "*")
                return left * right;

            if (op == "/")
                return left / right;
            
            return 0;
    }
};

int main() {
    Solution *test = new Solution();
    //std::vector<std::string> token = {"2","1","+","3","*"};
    //std::vector<std::string> token = {"4","13","5","/","+"};
    std::vector<std::string> token = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    std::cout << test->evalRPN(token) << std::endl;
    return 0;
}