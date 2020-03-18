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
		if (points.size() <= 1)	
			return points.size();

		int points_size = points.size();
		int max_value = 0;
		for (int i = 0; i < points_size; ++i) {
			map<double, int> point_count;

				double slope = 0.0f;
				for (int j = i+1; j < points_size; ++j) {
					double molecule    = points[j][1] - points[i][1];
					double denominator = points[j][0] - points[i][0];

					std::cout << "i: " << i << " j: " << j << std::endl;
					std::cout << "y1: " << points[j][1] << " x1: " << points[j][0] << " y: " << points[i][1] << " x: " << points[i][0] << std::endl; 
					std::cout << "molecule: " << molecule << " denominator: " << denominator << std::endl;

					if (points[j][1] == points[i][1] && points[j][0] == points[i][0]) {
						point_count[slope]++;
						continue;
					}

					if (denominator != 0)
		   				slope = molecule/denominator;
		
					point_count[slope]++;
					
					std::cout << "slope: " << slope << std::endl;
				} //for j


			for (auto it = point_count.begin(); it != point_count.end(); ++it)  {
				if (it->second >= max_value)	
					max_value = it->second;
			} //for auto
		} //for i


		return (max_value+1);
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
	
	/*
	vector<vector<int>> nums = {
		{1, 1}, 
		{3, 2}, 
		{5, 3},
		{4, 1},
		{2, 3},
		{1, 4}
	};
	*/

	/*
	vector<vector<int>> nums = {
		{0, 0}, 
		{0, 0} 
	};
	*/
	
	/*
	vector<vector<int>> nums = {
		{0, 0}, 
		{1, 1}, 
		{0, 0}
	};
	*/

	vector<vector<int>> nums = {
		{1, 1}, 
		{1, 1}, 
		{2, 3}
	};

	Solution *objs = new Solution();
	std::cout << "result: " << objs->maxPoints(nums) <<  std::endl;
}


