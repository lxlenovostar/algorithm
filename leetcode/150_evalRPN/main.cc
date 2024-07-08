#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tmp_value;

        if (tokens.size() == 0)
            return 0;
        
        for (auto &it : tokens) {
            if (it == "+" || it == "-" || it == "*" || it == "/") {
                auto right_value = tmp_value.top();
                tmp_value.pop();
                auto left_value = tmp_value.top();
                tmp_value.pop();
                tmp_value.push(handle(left_value, right_value, it));
            } else {
               tmp_value.push(std::stoi(it));
            }
        }

        return tmp_value.top();
    }
private:
    int handle(int left_value, int right_value, const string& op) {
        //std::cout << "left:" << left_value << " right:" << right_value << " op:" << op << std::endl;
        if (op == "+")
            return left_value + right_value;
        else if (op == "-")
            return left_value - right_value;
        else if (op == "*")
            return left_value * right_value;
        else if (op == "/")
            return left_value / right_value;
        else 
            return 0;
    }
};

int main() {

    //vector<string> parameter = {"2","1","+","3","*"};
    vector<string> parameter = {"4","13","5","/","+"};
    Solution *test = new Solution();

    std::cout << "ret: " << test->evalRPN(parameter) << std::endl;
    return 0;
}