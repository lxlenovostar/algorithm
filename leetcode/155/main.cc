#include <stack>
#include <iostream>

using namespace std;

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        data_stack.push(val);

        if (min_stack.empty()) {
            min_stack.push(val);
        } else {
            if (min_stack.top() >= val) {
                min_stack.push(val);
            }
        }
    }
    
    void pop() {
        int val = data_stack.top();
        data_stack.pop();

        if (val == min_stack.top())
            min_stack.pop();
    }
    
    int top() {
        return data_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }

private:
    stack<int> data_stack;
    stack<int> min_stack;
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    std::cout << obj->getMin() << std::endl;
    obj->pop();
    std::cout << obj->top() << std::endl;
    std::cout << obj->getMin() << std::endl;
    return 0;
}