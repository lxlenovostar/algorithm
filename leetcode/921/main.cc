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

int minAddToMakeValid(string s) {
	if (s.empty())
		return 0;
	
	std::stack<char>  tmp_stack;
	int fix_num = 0;

	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			tmp_stack.push(s[i]);
		} else {
			if (tmp_stack.size() == 0)
				fix_num++; 
			else {
				char c = tmp_stack.top();
				if (c != getBrackets(s[i]))
					fix_num++;
				tmp_stack.pop();
			}
		}
	}

	return (fix_num + tmp_stack.size());
		
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
	std::cout << test->minAddToMakeValid("())") << std::endl;	
	std::cout << test->minAddToMakeValid("((((") << std::endl;	
	return 0;
}
