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
#include <map>

using namespace std;

class Solution {
public:
	//int count;
	int N; 


	int dp(int n, vector<int> &mem) {
		/*
		for (size_t i = 0; i < mem.size(); i++) {
			std::cout << mem[i];
		}
		std::cout << std::endl;
		*/

		if (n == N) {
			std::cout << "what0.2" << std::endl;
			return 1;	
		}

		if (n > N) {
			std::cout << "what0.3" << std::endl;
			return 0;
		}
		 
		if (mem[n] != -1)  {
			std::cout << "what0.1 n:" << n << " mem[n]: " << mem[n] << std::endl;
			return mem[n];
		}

		std::cout << "what0.4 n: " << n  << std::endl;
		int a_1 = dp(n+1, mem);
		std::cout << "what0.4 a_1: " << a_1  << std::endl;
		int a_2 = dp(n+2, mem);
		std::cout << "what0.4 a_2: " << a_2  << std::endl;
		mem[n] = a_1 + a_2;
		return mem[n];
	}
   
	int climbStairs_1(int n) {
		if (n <= 1)
			return n;

		vector<int> mem(n+1, -1);
		N = n;
		return dp(0, mem);

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

	//std::cout << obj->climbStairs_1(2) << std::endl;
	//std::cout << obj->climbStairs_1(3) << std::endl;
	std::cout << obj->climbStairs_1(44) << std::endl;

	return 0;
}


