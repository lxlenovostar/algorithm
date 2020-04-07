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

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
	public:
		int climbStairs_dp(int n) {
			if (n <= 2)
				return n;

			vector<int> step_values;
			step_values.resize(n+1);

			step_values[0] = 0;
			step_values[1] = 1;
			step_values[2] = 2;

			for (int i = 3; i <= n; ++i) {
				step_values[i] = step_values[i-1] + step_values[i-2];
			}

			return step_values[n];
		}
	
		int recursive(int n, std::map<int, int> &mem_d) {
			if (n <= 2) {
				return n;
			}	
	
			int step_reduce_1, step_reduce_2;
			if (mem_d.find(n-1) != mem_d.end())
				step_reduce_1 = mem_d[n-1];
			else {
				step_reduce_1 = recursive(n-1, mem_d);
				mem_d[n-1] = step_reduce_1;
			}
		
			if (mem_d.find(n-2) != mem_d.end())
				step_reduce_2 = mem_d[n-2];
			else {
				step_reduce_2 = recursive(n-2, mem_d);
				mem_d[n-2] = step_reduce_2;
			}
			
			int steps = (step_reduce_1 + step_reduce_2);
			if (mem_d.find(n) == mem_d.end())
				mem_d[n] = steps;

			return steps;
		
		}	

		int climbStairs_recursive(int n) {
			if (n <= 2)
				return n;

			std::map<int, int> mem_steps;

			return recursive(n, mem_steps);

		}
};

int main() {
	Solution *obj = new Solution();

	//std::cout << obj->climbStairs(2) << std::endl; 
	//std::cout << obj->climbStairs(3) << std::endl; 
	std::cout << obj->climbStairs_recursive(4) << std::endl; 

	return 0;
}




