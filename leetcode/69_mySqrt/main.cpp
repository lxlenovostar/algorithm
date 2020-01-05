/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
		if (x <= 1)
			return x;

		long lo = 1;
		long hi = x;
		long mid = (hi + lo)/2;
		int res = 0;

		while (lo <= hi) {
			mid = (hi + lo)/2;
			std::cout << "lo: " << lo << " hi: " << hi << " mid: " << mid << std::endl;
			if (mid == x/mid) {
				return mid;
			} else if (mid > x/mid) {
				hi = mid - 1;
				std::cout << " 1 lo: " << lo << " hi: " << hi << " mid: " << mid << std::endl;
			} else {
				res = mid;
				lo = mid + 1;
				std::cout << " 2 lo: " << lo << " hi: " << hi << " mid: " << mid << std::endl;
			}
		
		}

		return res;
    }
};

int main() {
	Solution *obj = new Solution();
	//std::cout << obj->mySqrt(4) << std::endl;
	std::cout << obj->mySqrt(8) << std::endl;
	std::cout << obj->mySqrt(3) << std::endl;
	return 0;
}
