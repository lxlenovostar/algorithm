/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int count;

	int helper(int n) {
		/*
		if (n == 0) {
			std::cout << "what0" << std::endl;
			count++;
		}

		if (n >= 2) {	
			std::cout << "what 2: " << n << std::endl;
			helper(n-2);
		}

		if (n >= 1) {
			std::cout << "what 1: " << n << std::endl;
			helper(n-1);
		}
		*/

		if (n == 0)
			return 0;

		if (n == 1)
			return 1;

		return ( (helper(n-1) + 1),  (helper(n-2) + 1) );

	}

    int climbStairs_1(int n) {
		if (n <= 1)
			return n;

		helper(n);

		return count;
    }

	int dp(int n) {
		if (n == 0)
			return 0;

		if (n == 1) 
			return 1;

		 
		return dp(n-1) + dp(n-2);
	
	}
  
	int climbStairs(int n) {
		vector<int> ret(n+1, 1);

		for (int i = 2; i <= n; ++i) {
			ret[i] = ret[i-1] + ret[i-2];
			std::cout << " ret[i-1]: " << ret[i-1] << " ret[i-2]: " << ret[i-2] << std::endl;
			std::cout << "i: " << i << " ret[i]: " << ret[i] << std::endl;
		}

		return ret[n];

    }


};

int main() {
	Solution *obj = new Solution();

	std::cout << obj->climbStairs(2) << std::endl;
	//std::cout << obj->climbStairs(3) << std::endl;
	//std::cout << obj->climbStairs(44) << std::endl;

	return 0;
}


