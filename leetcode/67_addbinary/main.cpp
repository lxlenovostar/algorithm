#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
 * 不要数据结构重现写
 * */
class Solution {
		public:
			string addBinary(string a, string b) {
				if (a.empty())
					return b;
				if (b.empty())
					return a;


				std::string s_ret = "";
				int carry = 0;
				int size_a = a.size() - 1;
				int size_b = b.size() - 1;

				//std::cout << "size_a: " << size_a << std::endl;
				//std::cout << "size_b: " << size_b << std::endl;
				
				while (size_a >= 0 || size_b >= 0) {
					int ret = 0;

					if (size_a >= 0 && size_b >= 0) {
						ret = (a[size_a] - '0')	 + (b[size_b] - '0') + carry;
					}
					else if (size_a < 0) {
						ret =  (b[size_b] - '0') + carry;
					}
					 else if (size_b < 0) {
						ret =  (a[size_a] - '0') + carry;
					}

					carry = ret/2;
					char c_ret = ret%2 + '0';
					//std::cout << "ret: " << ret << " carry: " << carry << " c_ret:" << c_ret << std::endl;
					s_ret.insert(0, 1, c_ret);

					size_a--;
					size_b--;
					//std::cout << "size_a: " << size_a << " size_b: " << size_b << std::endl;
				}

				if (carry > 0) {
					s_ret.insert(0, 1, '1');
				}
			
				return s_ret;
				


			}
};

int main() {
		Solution *test = new Solution();
		//std::cout << test->addBinary("11", "00") << std::endl;
		//std::cout << test->addBinary("11", "10") << std::endl;
		std::cout << test->addBinary("1010", "1011") << std::endl;
		std::cout << test->addBinary("1010", "11") << std::endl;

		return 0;
}
