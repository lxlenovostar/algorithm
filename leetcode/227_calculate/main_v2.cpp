#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
	public:
		int calculate(string s) {
			if (s.empty())
				return 0;

			vector<int> ret;
			int num = 0;
			char per_signal = '+';

			for (size_t i = 0; i < s.size(); ++i) {
				if (isdigit(s[i])) {
					//std::cout << "case 1:" << s[i] << std::endl; 
					num = num*10 + int(s[i] - '0'); 
					//std::cout << "case 1 num:" << num << std::endl; 
				}

				if((!isdigit(s[i]) && s[i] != ' ') || (i == s.size() - 1)) {
					//std::cout << "case 2:" << s[i] << std::endl; 

					switch(per_signal) {
						case '+': 
							ret.push_back(num);
							break;
						case '-':
							ret.push_back(0-num);
							break;
						case '*':
							ret.back() *= num;
							break;
						case '/':
							ret.back() /= num;
							break;
					}
					per_signal = s[i];
					num = 0;
				}
			}	
				
			return std::accumulate(ret.begin(), ret.end(), 0);

		}
};

int main() {
		Solution *test = new Solution();
		std::cout << test->calculate("42") << std::endl;
		std::cout << test->calculate("3+2*18") << std::endl;
		//std::cout << test->calculate("3+2") << std::endl;
		std::cout << test->calculate("3+2*2") << std::endl;
		//std::cout << test->calculate(" 3/2 ") << std::endl;
		std::cout << test->calculate("3+5 / 2 ") << std::endl;

		return 0;
}
