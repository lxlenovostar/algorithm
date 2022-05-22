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
	
	if (s.size() == 1)
		return false;
	
	std::stack<char>  tmp_stack;

	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			tmp_stack.push(s[i]);
		} else {
			if (tmp_stack.size() == 0)
				return false;

			char c = tmp_stack.top();
			if (c != getBrackets(s[i]))
				return false;
			tmp_stack.pop();
		}
	}


	return (tmp_stack.size() == 0);
		
    }
};

int main() 
{
	Solution *test = new Solution();
	/*
	std::cout << test->isValid("()") << std::endl;	
	std::cout << test->isValid("()[]{}") << std::endl;	
	std::cout << test->isValid("([{}])") << std::endl;	
	std::cout << test->isValid("({[}])") << std::endl;	
	std::cout << test->isValid("((") << std::endl;	
	*/
	std::cout << test->isValid("){") << std::endl;	
	return 0;
}
