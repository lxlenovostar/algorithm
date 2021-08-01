#include <iostream>
#include <stack>

using namespace std;

class Solution {
	public:
		string add_sub(string a, string b, string type) {
			std::cout << "a:" << a  << " b: " << b << " type: " << type << std::endl;

			int ret = 0;
			if (type == "+") {
				ret = std::stoi(a) + std::stoi(b);	
			}

			if (type == "-") {
				ret = std::stoi(a) - std::stoi(b);	
			}

			std::cout << "add:" << ret << std::endl;

			return std::to_string(ret);
		}

		string mul(string a, string b, string type) {
			
			std::cout << "a:" << a  << " b: " << b << " type: " << type << std::endl;

			int ret = 0;
			if (type == "*") {
				ret = std::stoi(a) * std::stoi(b);	
			}

			if (type == "/") {
				ret = std::stoi(a) / std::stoi(b);	
			}

			std::cout << "mul:" << ret << std::endl;

			return std::to_string(ret);
		}

		bool is_digits(const std::string &str)
		{
				    return str.find_first_not_of("0123456789") == std::string::npos;
		}


		int calculate(string s) {
			if (s.empty())
				return 0;

			stack<string> add_stack;
			stack<string> end_stack;
			const char* const string_pointer = s.c_str();
			size_t string_len = s.size();

			for (size_t i = 0; i < string_len; ++i) {
					if (*(string_pointer + i) == ' ') {
						continue;
					}
					else if (*(string_pointer + i) >= '0' && *(string_pointer +i) <= '9') {
					if (add_stack.empty() == false && (add_stack.top() == "*" || add_stack.top() == "/")) {
						std::cout << "case 0" << std::endl;
			
						string type = add_stack.top();
						add_stack.pop();
						string left = add_stack.top();
						add_stack.pop();
					
						std::string str(1, *(string_pointer +i));
						add_stack.push(mul(left, str, type));	
					} else {
						std::cout << "case 1" << std::endl;
						std::string str(1, *(string_pointer +i));
						add_stack.push(str);	
					}
				} else if  (*(string_pointer + i) == '+' || *(string_pointer + i) == '-') { 
					std::cout << "case 2" << std::endl;
					std::string str(1, *(string_pointer +i));
					add_stack.push(str);	
				} else if  (*(string_pointer + i) == '*' || *(string_pointer + i) == '/') { 
					std::cout << "case 3" << std::endl;
					std::string str(1, *(string_pointer +i));
					add_stack.push(str);	
				} else  {
					std::cout << "case 4" << std::endl;
				}
			} // for

			while (add_stack.empty() == false) {
				string val = add_stack.top();
				add_stack.pop();

				std::cout << "val: " << val << std::endl;

				if (is_digits(val)) {
					if (end_stack.empty() == false && (end_stack.top() == "+" || end_stack.top() == "-")) {
						string type = end_stack.top();
						end_stack.pop();
						string left = end_stack.top();
						end_stack.pop();
						std::cout << "case 2.1" << std::endl;
						end_stack.push(add_sub(left, val, type));	
					}
					else {
						std::cout << "case 2.2" << std::endl;
							end_stack.push(val);
					}
				} else {
							end_stack.push(val);
					
				}
			}

			return std::stoi(end_stack.top());
		}
};

int main() {
		Solution *test = new Solution();
		std::cout << test->calculate("42") << std::endl;
		//std::cout << test->calculate("3+2*18") << std::endl;
		//std::cout << test->calculate("3+2") << std::endl;
		//std::cout << test->calculate("3+2*2") << std::endl;
		//std::cout << test->calculate(" 3/2 ") << std::endl;
		//std::cout << test->calculate("3+5 / 2 ") << std::endl;

		return 0;
}
