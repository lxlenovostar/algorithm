/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();

		vector<int> res(len, 0);
		int sum = 0;
		int one = 1;
		
		for (int i = len - 1; i >= 0; --i) {
			sum = one + digits[i];
			one = sum / 10;
			res[i] = sum % 10;
		}

		if (one > 0)
			res.insert(res.begin(), one);

		return res;
    }
};

int main() {
	vector<int> nums = {1,2,3};
	Solution *obj = new Solution();

	vector<int> ret = obj->plusOne(nums);

	for (size_t i = 0; i < ret.size(); ++i)
		std::cout << ret[i] << " ";

	std::cout << std::endl;
	return 0;
}


