/*
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <queue>
#include <iostream>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
    	obj_q.push(x); 
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
    	int ret = obj_q.back();

		//obj_q.resize(obj_q.size() - 1);	
	
  		std::cout << "ret: " << ret << std::endl; 

		queue<int> tmp_q;

		int size_q = obj_q.size();

		for (int i = 0; i < size_q - 1; ++i) {
			int tmp = obj_q.front();
			obj_q.pop();
			tmp_q.push(tmp);
		}

		obj_q = tmp_q;

		return ret;
    }
    
    /** Get the top element. */
    int top() {
		if (obj_q.size() > 0)
    		return obj_q.back(); 
		else 
			return -1;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return obj_q.empty();
    }

	queue<int> obj_q;
};

int main() 
{

  //Your MyStack object will be instantiated and called as such:
  MyStack* obj = new MyStack();
  int x = 3;
  obj->push(x);

  int param_2 = obj->pop();
  std::cout << "param_2: " << param_2 << std::endl; 

  int param_3 = obj->top();
  std::cout << "param_3: " << param_3 << std::endl; 

  bool param_4 = obj->empty();
  std::cout << "param_4: " << param_4 << std::endl; 


	return 0;
}



