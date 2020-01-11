/*
 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

 在杨辉三角中，每个数是它左上方和右上方的数的和。

 示例:

 输入: 3
 输出: [1,3,3,1]
 进阶：

 你可以优化你的算法到 O(k) 空间复杂度吗？
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

	vector<int> getRow(int rowIndex) {
		vector<int> ret(rowIndex+1, 1);
       
	   	for (int i = 2; i <= rowIndex; ++i) {
			for(int j = i - 1; j >= 1; --j) {
				std::cout << "i: " << i << " j: " << j << std::endl;
				ret[j] =  ret[j] + ret[j-1];
			}
    	}

		return ret;
	}
};

int main() {
	Solution *obj = new Solution();	

	vector<int>	ret = obj->getRow(3);

	for (size_t i = 0; i < ret.size(); ++i) {
			std::cout << ret[i] << " ";
	}

	std::cout << std::endl;

	return 0;
}
