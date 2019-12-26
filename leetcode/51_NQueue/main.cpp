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
public:
	vector<vector<Point>> result;
	int N;

	void  helper(int n, vector<Point> points, set<int> vals_a, set<int> vals_b, set<int> vals_c) {
		if (n == 0) {
			std::cout << "what1" << std::endl;
			result.push_back(points);	
		}

		for (int i = 0; i < N; i++)  {
			int x = N-n;
			int y = i;

			int A = x + y;
			int B = abs(x-y);
			int C = i; 

			if (vals_a.find(A) != vals_a.end()) {
				std::cout << "what2" << std::endl;
				continue;
			} else {
				//TODO
				vals_a.insert(A);
			}
				
			if (vals_b.find(B) != vals_b.end()) {
				std::cout << "what3" << std::endl;
				continue;
			} else {
				//TODO
				vals_b.insert(B);
			}
				
			if (vals_c.find(C) != vals_c.end()) {
				std::cout << "what4" << std::endl;
				continue;
			} else {
				//TODO
				vals_c.insert(C);
			}
				
			struct Point p_t = {x, y};
			points.push_back(p_t);

			helper(n-1, points, vals_a, vals_b, vals_c);
			
		}

		std::cout << "end" << std::endl;
	}

    vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> ret;
		vector<Point> point_vector;
		set<int>      val_set_a;
		set<int>      val_set_b;
		set<int>      val_set_c;

		N = n;
		helper(n, point_vector, val_set_a, val_set_b, val_set_c);

		for (size_t i = 0; i < result.size(); i++) {
			for (size_t j = 0; j < result[i].size(); j++)
				std::cout << "x: " << result[i][j].x << " y: " << result[i][j].y << std::endl;
			std::cout << std::endl;
		}	

		return ret;	
		
    }
};

int main() {
	Solution *obj = new Solution();

	vector<vector<string>> ret = obj->solveNQueens(4);
	/*
	for (size_t i = 0; i < ret.size(); i++) {
		for (size_t j = 0; j < ret[i].size(); j++)
			std::cout << ret[i][j] << std::endl;
		std::cout << std::endl;
	}	
	*/

	return 0;
}

