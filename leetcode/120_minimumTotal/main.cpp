/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int N; 
	int M;
	int dp(int i, int j, vector<vector<int>> &key, vector<vector<int>>& triangle) {
		if (i >= N)
			return 0;
					
		int ret_down = dp(i+1, j, key, triangle);
		
		int ret_xie =  dp(i+1, j+1, key, triangle);
		int ret_min = min(ret_down, ret_xie) + triangle[i][j];

		key[i][j] = ret_min;
		return ret_min;
	}
   
	int minimumTotal(vector<vector<int>>& triangle) {
		N = triangle.size();

		vector<vector<int>> key;
		for (int i = 0; i < N; ++i) {
			vector<int>	 tmp;
			for (size_t j = 0; j < triangle[i].size(); ++j) {
				tmp.push_back(0);
			}
			key.push_back(tmp);
		}

		dp(0, 0, key, triangle);

		for (size_t i = 0; i < key.size(); ++i) {
			for (size_t j = 0; j < key[i].size(); ++j) {
				std::cout << key[i][j] <<  " ";
			}
			std::cout << std::endl;
		}

		return key[0][0];
    }

    int minimumTotal_1(vector<vector<int>>& triangle) {
		N = triangle.size();

		vector<int> key;
		for (size_t i = 0; i < triangle[N-1].size(); ++i) {
			key.push_back(triangle[N-1][i]);	
		}


		for (int i = N-2; i >=  0; --i) {
			for (int j = 0; j <= (int)(triangle[i].size()-1); ++j) {
				std::cout << "i: " << i << " j: " << j << std::endl;
				//key[j] = min(triangle[i+1][j], triangle[i+1][j+1]) + key[j];
				key[j] = min(key[j], key[j+1]) + triangle[i][j];
				std::cout << "key[j]: " << key[j] << std::endl;
			}
		}

		for (size_t i = 0; i < key.size(); ++i) {
				std::cout << key[i] <<  " ";
		}
		std::cout << std::endl;

		return key[0];
    }
};

int main() {
	vector<vector<int>> nums = {
			{2},
			{3,4},
			{6,5,7},
			{4,1,8,3}
	};

	Solution *obj = new Solution();
	std::cout << obj->minimumTotal_1(nums) << std::endl;

	return 0;
}

