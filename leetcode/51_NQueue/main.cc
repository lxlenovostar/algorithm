/*
输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

class Solution {
	private: 
			int N;
			vector<vector<string>> ret;	
	private:
	void vector_int_to_string(vector<int> ret_row) {
		string str_ret;
		for (size_t i = 0; i < ret_row.size(); ++i)	 {
			if (ret_row[i] == 0)
				str_ret += ".";
			else
				str_ret += "Q";
		} //for

		return str_ret;
	}

	void recurisive(int level, vector<vector<int>> ret_queue) {
		if (level == N) {
			//get the right result;	
			vector<string>  ret_vec;

			for (size_t i = 0; i < ret_queue.size(); ++i) {
				ret_vec.push_back(vector_int_to_string(ret_queue[i]));
			}

			ret.push_back(ret_vec);
			return;
		}

		for (int i = 0; i < N; ++i) {
			if (ret_queue[level][i] == 0) {
				ret_queue[level][i]	 = 1;

				//set row
				//set xie
				recurisive(level+1, ret_queeue);
			}
		}


	
	}

	public:
    vector<vector<string>> solveNQueens(int n) {
		vector<vector<int>> layout;

		N = n;

		for (int i = 0; i < n; ++i) {
			vector<int>  inline_layout(n, 0);
			layout.push_back(inline_layout);
		}

		recurisive(0, layout);

	}
};

int main() {
	Solution *obj = new Solution();

	vector<vector<string>> ret = obj->solveNQueens(4);
	//vector<vector<string>> ret = obj->solveNQueens(8);
	for (size_t i = 0; i < ret.size(); i++) {
		for (size_t j = 0; j < ret[i].size(); j++)
			std::cout << ret[i][j] << std::endl;
		std::cout << std::endl;
	}	

	return 0;
}

