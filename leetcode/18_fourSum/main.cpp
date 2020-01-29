/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int N;
	vector<vector<int>> result;

	bool check(vector<int> ret) {
		for (size_t i = 0; i < result.size(); ++i) {
			bool flag = true;
			for (size_t j = 0; j < result[i].size(); ++j) {
				if (result[i][j] != ret[j]) {
					flag = false;
					continue;
				}
			}

			if (flag == true)
				return true;
		}
	
		return false;
	}

	void dfs(vector<int>& nums, int index, int target, vector<int> ret) {
		if (target == 0 && ret.size() == 4) {
			if (check(ret) == false)
				result.push_back(ret);
			return;
		}

		if (index >= N) {
			std::cout << "target: " << target << std::endl;
			return ;
		}

		//case 1  choice it.
		vector<int> new_ret = ret;
		new_ret.push_back(nums[index]);

		std::cout << "what1" << std::endl;
		dfs(nums, index+1, target - nums[index], new_ret);

		std::cout << "what2" << std::endl;

		//case 2 
		dfs(nums, index+1, target, ret);
		
		std::cout << "what3" << std::endl;

	}
	
	vector<vector<int>> fourSum_1(vector<int>& nums, int target) {
    		if (nums.size() <= 0)	
				return result;

			N = nums.size();

			sort(nums.begin(), nums.end());

			vector<int> ret;
			dfs(nums, 0, target, ret);

			return result;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;

    	if (nums.size() < 4)	
			return result;

		N = nums.size();
		sort(nums.begin(), nums.end());

		for (size_t i = 0; i < nums.size() - 3; ++i) {
			//this two while loop is used to skip the duplication solution
			if (i >= 1 && nums[i] == nums[i-1]) {
				continue;
			}

			for (size_t j = i+1; j < nums.size() - 2; ++j) {
				int start = j + 1;
				int end = nums.size() - 1;
				int value; 
			
				if (j > i+1 && nums[j] == nums[j-1]) {
					continue;
				}
		
				while(start < end) {
					std::cout << "i: " << i << " j: " << j << " start: " << start << " end: " << end << std::endl;
					value = nums[i] + nums[j] + nums[start] + nums[end]; 
					std::cout << "nums[i]: " << nums[i] << "nums[j]: " << nums[j] << " nums[start]: " << nums[start] << " nums[end]: " << nums[end] << " value: " << value << std::endl;

				if (value > target) {
					--end;
				} else if (value < target) {
					++start;	
				} else {
					vector<int> r;
					r.push_back(nums[i]);			
					r.push_back(nums[j]);			
					r.push_back(nums[start]);			
					r.push_back(nums[end]);			

					result.push_back(r);

					++start;
					--end;

					//this two while loop is used to skip the duplication solution
					while (start < end && nums[start-1] == nums[start])
						++start;

					while (start < end && nums[end+1] == nums[end])
						--end;

				} // if 

			} // while


			//this two while loop is used to skip the duplication solution
			/*
			size_t tmp_j = j + 1;
			if (tmp_j < nums.size()-2 && nums[tmp_j] == nums[j]) {
				++j;
			}
			*/
			
			} // for j
		} // for i


		return result;
    }

};

int main() {
	
	//vector<int> nums = {1, 0, -1, 0, -2, 2};
	//vector<int> nums = {-2, -1, 0, 0, 1, 2};
	vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
	//vector<int> nums = {0, 0, 0, 0};
	//vector<int> nums = {-3, -3, -2, -2, 0, 0, 4};
	int target = 0;
	//int target = -1;

	Solution *obj = new Solution();
	vector<vector<int>> ret = obj->fourSum(nums, target);

	for (size_t i = 0; i < ret.size(); ++i) {
		for (size_t j = 0; j < ret[i].size(); ++j) {
			std::cout << ret[i][j] << " "; 	
		}
		std::cout << std::endl;
	}

	return 0;
}

