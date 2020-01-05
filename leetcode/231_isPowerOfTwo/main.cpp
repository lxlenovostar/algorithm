/*
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true

解释: 20 = 1

示例 2:

输入: 16
输出: true
解释: 24 = 16

示例 3:

输入: 218
输出: false
*/

#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int helper(int n) {
		int ret = 0;

		while (n != 0) {
			//X = X & (X-1)
			n = n &(n-1);
			ret++;
		}

		return ret;
    }

	bool isPowerOfTwo(int n) {
		if (n <= 0)
        	return false;

		if (helper(n) == 1)
			return true;
		else 
			return false;
    }

};

int main() {
	int n  = 11;
	
	std::cout << "n: " << n << std::endl;

	Solution *obj = new Solution();
	std::cout << obj->isPowerOfTwo(n) << std::endl;
	n  = 1;
	std::cout << obj->isPowerOfTwo(n) << std::endl;
	n  = 16;
	std::cout << obj->isPowerOfTwo(n) << std::endl;
	n  = -16;
	std::cout << obj->isPowerOfTwo(n) << std::endl;
	return 0;
}
