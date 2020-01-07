/*
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]
示例 2:

输入: 5
输出: [0,1,1,2,1,2]
进阶:

给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
要求算法的空间复杂度为O(n)。
你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。
*/

#include <vector>
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

    vector<int> countBits_1(int num) {
		vector<int> ret;

		int prev_value = 0;

		for (int i = 0; i <= num; i++)
		{
			if (i%2 == 0) {
				prev_value = helper(i);
				ret.push_back(prev_value);
			}
			else  {
				ret.push_back(prev_value+1);
			}
		}

		return ret;
    }

 	vector<int> countBits(int num) {
		vector<int> ret(num+1, 0);

		for (int i = 1; i <= num; i++)
		{
			ret[i] += ret[i & (i-1)] + 1;
		}

		return ret;
    }

};


int main() {
	int n  = 1;

	Solution *obj = new Solution();
	vector<int> ret =  obj->countBits(n);

	for (size_t i = 0; i < ret.size(); i++)
		std::cout << ret[i] << std::endl;

	return 0;
}
