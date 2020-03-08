/*
给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

示例 1:

输入: [[1,1],[2,2],[3,3]]
输出: 3
解释:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
示例 2:

输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出: 4
解释:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
*/

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
		if (points.size() <= 0)	
			return 0;

		map<int, int> point_count;
		int points_size = points.size();
		for (int i = 0; i < points_size; ++i) {
			int tmp;
			if (points[i][1] != 0)
		   		tmp = points[i][0]/points[i][1];
			else 
				tmp = 0;
		
			point_count[tmp]++;
		}

		int max_value = 0;

		for (auto it = point_count.begin(); it != point_count.end(); ++it)  {
			if (it->second >= max_value)	
				max_value = it->second;
		}

		return max_value;
    }
};

int main() {
	/*
	vector<vector<int>> nums = {
		{1, 1}, 
		{2, 2}, 
		{3, 3}
	};
	*/
	
	vector<vector<int>> nums = {
		{1, 1}, 
		{3, 2}, 
		{5, 3},
		{4, 1},
		{2, 3},
		{1, 4}
	};


	Solution *objs = new Solution();
	std::cout << "result: " << objs->maxPoints(nums) <<  std::endl;
}


