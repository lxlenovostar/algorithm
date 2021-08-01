#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
   char getBrackets(char left) {
	switch(left) {
		case ')':
			return '(';	
		case ']':
			return '[';
		case '}':
			return '{';
		default:
			//std::cout << "error" << std::endl;
			return left;
	}
	
}

    bool isValid(string s) {
	if (s.empty())
		return true;
	
	const char* const tmp = s.c_str();
	size_t len = s.size();
	std::stack<char>  tmp_stack;

	//std::cout << "len: " << len << std::endl;
	
	for (size_t i = 0; i < len; ++i) {
		if (*(tmp+i) == '(') {
			tmp_stack.push(')');
		} else if (*(tmp+i) == '[') {
			tmp_stack.push(']');
		} else if (*(tmp+i) == '{') {
			tmp_stack.push('}');
		} else {
			if (*(tmp+i) == tmp_stack.top()) {
				tmp_stack.pop();	
			} else {
				return false;	
			}
		}			
	}	

	/*
	for (size_t i = 0;   i < len; ++i)	 {
		if (tmp_stack.size() == 0) {
			//std::cout << "case1" << std::endl;
			tmp_stack.push(*(tmp + i));
		} else if (*(tmp + i) == tmp_stack.top()) {
			tmp_stack.push(*(tmp + i));
		} else if (getBrackets(*(tmp + i)) == tmp_stack.top()) {
			//std::cout << "case2" << std::endl;
			tmp_stack.pop();
		} else {
			//std::cout << "case3" << std::endl;
			tmp_stack.push(*(tmp + i));
		 } 	
	} // for
	*/

	return (tmp_stack.size() == 0);
		
    }
};

int main() 
{
	Solution *test = new Solution();
	std::cout << test->isValid("()") << std::endl;	
	std::cout << test->isValid("()[]{}") << std::endl;	
	std::cout << test->isValid("([{}])") << std::endl;	
	std::cout << test->isValid("({[}])") << std::endl;	
	std::cout << test->isValid("((") << std::endl;	
	return 0;
}
