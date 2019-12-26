/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	double ret;
    double myPow(double x, int n) {
		if (n == 0) {
			std::cout  << "what1" << std::endl;
			return 1;
		}
		else if (n > 0) {
			std::cout  << "what2" << std::endl;
			ret = x*(this->myPow(x, n-1));
		} else {
			std::cout  << "what3" << std::endl;
			ret = (1/x)*(this->myPow(x, n+1));
			std::cout  << "what3:" << ret << std::endl;
		}

		return ret;
    }

 	double myPow1(double x, int n) {
		double result = 0.0f;
		if (n > 0) {
			result = helper(x, n);	
		} else if (n < 0) {
			result = 1/helper(x, abs(n));
		} else {
			return 1;
		}
			
		return result;
	}

 	double helper(double x, int n) {
		if (n == 1)
			return x;
		
		if (n % 2 == 0) {
			double tmp = helper(x, n/2);
			ret = tmp*tmp;
		} else {
			double tmp = helper(x, n/2);
			ret = x*tmp*tmp;
		}

		return ret;
    }


};

int main() {
	Solution *obj = new Solution();
	
	/*
	double x = 2.10000;
	int y = 3;
	*/

	double x = 2.00000;
	int y = -2;
	//double x = 0.00001;
	//double x = 2;
	//int y = 2147;
	//int y = 2147483647;
	std::cout << "ret:" << obj->myPow1(x, y) << std::endl; 

	return 0;
}
