/*
 给定一个整数 n，返回 n 皇后不同的解决方案的数量。

示例:

输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]

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
			//std::cout << "what0" << std::endl;
			result.push_back(points);	
		}

		for (int i = 0; i < N; i++)  {
			int x = N-n;
			int y = i;

			int A = x + y;
			//int B = abs(x-y);
			int B = y-x;
			int C = i; 
			int D = x;

			set<int>      new_vals_a(vals_a);
			set<int>      new_vals_b(vals_b);
			set<int>      new_vals_c(vals_c);
			vector<Point> new_points(points);

			//std::cout << "n: " << n << " i: " << i << std::endl;
			//std::cout << "A: " << A << " B: " << B << " C: " << C  << " D: " << D << std::endl;

			if (new_vals_a.find(A) != new_vals_a.end()) {
				//std::cout << "what1" << std::endl;
				continue;
			} else {
				//TODO
				new_vals_a.insert(A);
			}
				
			if (new_vals_b.find(B) != new_vals_b.end()) {
				//std::cout << "what2" << std::endl;
				continue;
			} else {
				//TODO
				new_vals_b.insert(B);
			}
				
			if (new_vals_c.find(C) != new_vals_c.end()) {
				//std::cout << "what3" << std::endl;
				continue;
			} else {
				//TODO
				new_vals_c.insert(C);
			}
				
			struct Point p_t = {x, y};
			//std::cout << "insert x: " << x << " y: " << y << std::endl;
			new_points.push_back(p_t);

			helper(n-1, new_points, new_vals_a, new_vals_b, new_vals_c);
			
		}

		//std::cout << "end" << std::endl;
	}

    int totalNQueens(int n) {
		vector<vector<string>> ret;
		vector<Point> point_vector;
		set<int>      val_set_a;
		set<int>      val_set_b;
		set<int>      val_set_c;

		N = n;
		helper(n, point_vector, val_set_a, val_set_b, val_set_c);

		return result.size();	
    }
};

int main() {
	Solution *obj = new Solution();

	//vector<vector<string>> ret = obj->solveNQueens(4);
	std::cout << obj->totalNQueens(4) << std::endl;
	//obj->totalNQueens(8) ;

	return 0;
}

