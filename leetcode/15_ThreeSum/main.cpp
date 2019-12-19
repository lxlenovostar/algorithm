/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		set<vector<int>> set_ret;

		if (nums.empty())
			return ret;

		std::sort(nums.begin(), nums.end());

		vector<int>::iterator pos = nums.begin();
		int old = *pos;

		for (; pos != nums.end(); pos++) {
			if (pos != nums.begin()) {
                if (*pos == old) {
                    old = *pos;
                    continue;
                }
            }

			vector<int>::iterator first = pos + 1;
			vector<int>::iterator end = nums.end() - 1;
			
		    while (first < end) {
				int value = *pos + *first + *end;

				std::cout << "*pos: " << *pos << " *first: " << *first << " *end: " << *end << " value:" << value << std::endl;;

				if (value == 0) {
					std::cout << "get it" << std::endl;
					vector<int> elem = {*pos, *first, *end};
					if (set_ret.find(elem) == set_ret.end())
						set_ret.insert(elem);
					end--;
					first++;
				} else if (value > 0) {
					end--;
				} else {
					first++;
				}
			}
		}

		for (set<vector<int>>::iterator it = set_ret.begin(); it != set_ret.end(); ++it)
			ret.push_back(*it);

		return ret;



    }
};

int main() {
	//vector<int> nums = {-2, -9, 11, 15};
	//vector<int> nums = {2, 11};
	//vector<int> nums = {-1, 0, 1, 2, -1, -4};
	//vector<int> nums = {14,4,6,-1,10,9,-8,7,-13,14,-13,-11,-8,-9,11,14,-8,-14,-13,7,-10,-15,-13,-11,-11,11,14,13,2,-14,1,-7,-2,14,-1,-15,9,7,-1,3,6,1,7,5,-1,-5,4,-2,-4,-1,-9,-7,-1,-7,-11,3,12,10,-7,-1,12,1,8,-13,1,14,9,-13,6,-7,-3,-11,2,-11,10,-14,-1,-9,0,2,5,6,3,-11,6,7,0,3,3,0,-12,-8,-13,3,-14,-5,2,10,-11,-14,-12,1,-10,5,5,7,-1,11,14,6,-10,-4,-3,8,-7,10,1,8,-1,-11,-15,-6,-12,-13,12,-11};
	//vector<int> nums = {0, 0, 0};
	vector<int> nums;

	Solution *obj = new Solution();
	vector<vector<int>> ret =  obj->threeSum(nums);

	if (!ret.empty()) {
		for (vector<vector<int>>::iterator pos = ret.begin(); pos != ret.end(); pos++) {
			for (vector<int>::iterator ppos = (*pos).begin(); ppos != (*pos).end(); ppos++)
				std::cout << *ppos << std::endl; 

			std::cout << std::endl; 
		}
	}

	return 0;
}
