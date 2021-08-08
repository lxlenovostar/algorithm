#include <string>
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
		public:
			/** Initialize your data structure here. */
		    MyQueue() {

			}

			void trans() {
				while(!input.empty()) {
						int tmp = input.top();
						input.pop();
						output.push(tmp);
					}
			}
					    
			/** Push element x to the back of queue. */
			void push(int x) {
				input.push(x);
			}
						    
			/** Removes the element from in front of queue and returns that element. */
			int pop() {
				if (output.empty()) {
					trans();

					if (!output.empty()) {
						int tmp = output.top();
						output.pop();
						return tmp;
					}
	 				
				} else {
					int tmp = output.top();
					output.pop();
					return tmp;
				}

				return -1;
			}
							    
			/** Get the front element. */
		    int peek() {
				if (output.empty()) {
					trans();
					
					if (!output.empty()) {
						return output.top();
					}
					
				} else {
					return output.top();
				}

				return -1;
		    }
								    
		    /** Returns whether the queue is empty. */
			bool empty() {
				return input.empty() && output.empty();
		    }

		private:
			stack<int> input;
			stack<int> output;
};

/**
 ** Your MyQueue object will be instantiated and called as such:
 */
int main() {
 	MyQueue* obj = new MyQueue();
	obj->push(1);
	obj->push(2);
	obj->push(3);
	obj->push(4);
 	std::cout << obj->pop() << std::endl;;
 	std::cout << obj->peek() << std::endl;
 	std::cout << obj->empty() << std::endl;

	return 0;
}


