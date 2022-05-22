#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:

int minInsertions(string s) {
	if (s.empty())
		return 0;
	
	std::stack<char>  tmp_stack;
	int num = 0;  /* 插入数目 */
	int need_right = 0;  /* 需要右边次数 */

	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			need_right += 2;

			if (need_right % 2 == 1) {
				num++;
				need_right--;
			}

		} else {
			need_right--;

			if (need_right == -1)
			{
				need_right = 1;
				num++;
			}
		}
	}


	return (need_right + num);
		
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
	//std::cout << test->minInsertions("((((((") << std::endl;	
	//std::cout << test->minInsertions("))())(") << std::endl;	
	//std::cout << test->minInsertions("))))))))))") << std::endl;	
	//std::cout << test->minInsertions(")))))))") << std::endl;	
	std::cout << test->minInsertions("(()))(()))()())))") << std::endl;	
	//std::cout << test->minInsertions("(()))") << std::endl;	
	return 0;
}
