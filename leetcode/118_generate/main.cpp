/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int> > vals;
		vals.resize(numRows);

		for(int i = 0; i < numRows; i++) {
			vals[i].resize(i + 1);
			vals[i][0] = 1;
			vals[i][vals[i].size() - 1] = 1;

			for(size_t j = 1; j < vals[i].size() - 1; j++) {
				vals[i][j] = vals[i - 1][j - 1] + vals[i - 1][j];
			}
		} 
		
		return vals;
    }
};

int main() {
	Solution *obj = new Solution();	

	vector<vector<int>>	 ret = obj->generate(4);

	for (size_t i = 0; i < ret.size(); ++i) {
		for (size_t j = 0; j < ret[i].size(); ++j) {
			std::cout << ret[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
