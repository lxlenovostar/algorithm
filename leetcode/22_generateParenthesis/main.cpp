/*

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	void getParenthesis(vector<string> &ret, int left, int right, string str) {

		if (left == 0 && right == 0)  { 
			std::cout << "what1: " << str << std::endl;
			ret.push_back(str);
			return;
		}

		if (left > 0) {
			std::cout << "what2.1: " << right << std::endl;
			std::cout << "what2.1: " << str << std::endl;
			getParenthesis(ret, left-1, right, str+"(");
			std::cout << "what2.2: " << str << std::endl;
			std::cout << "what2.2: " << right << std::endl;
		}
		
		if (left < right && right > 0) {
		//if (right > 0) {
			std::cout << "what3.1: "  << str << std::endl;
			getParenthesis(ret, left, right-1, str+")");
			std::cout << "what3.2: "  << str << std::endl;
		}
			
		std::cout << "end" << std::endl;

	}

    vector<string> generateParenthesis(int n) {
		vector<string> ret;

		getParenthesis(ret, n, n, "");

		return ret;
    }
};

int main() {
	Solution *obj = new Solution();
	vector<string> ret = obj->generateParenthesis(3);

	for (size_t i = 0; i < ret.size(); i++) {
		std::cout << ret[i] << std::endl;
	}

	return 0;
}
