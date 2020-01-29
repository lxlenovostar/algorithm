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
    vector<vector<int>> threeSum_1(vector<int>& nums) {
		vector<vector<int>> ret;
		//set<vector<int>> set_ret;

		if (nums.empty())
			return ret;

		std::sort(nums.begin(), nums.end());

		vector<int>::iterator pos = nums.begin();
		int old = *pos;

		for (; pos != nums.end(); pos++) {
			if (pos != nums.begin()) {
				std::cout << "1 new:" << *pos << " old:" << old << std::endl;
                if (*pos == old) {
					std::cout << "2 new:" << *pos << " old:" << old << std::endl;
                    old = *pos;
                    continue;
                }
				old = *pos;
            }

			vector<int>::iterator first = pos + 1;
			vector<int>::iterator end = nums.end() - 1;
			
		    while (first < end) {
				int value = *pos + *first + *end;

				std::cout << "*pos: " << *pos << " *first: " << *first << " *end: " << *end << " value:" << value << std::endl;;

				if (value == 0) {
					std::cout << "get it" << std::endl;
					vector<int> elem = {*pos, *first, *end};
					//if (set_ret.find(elem) == set_ret.end())
					//	set_ret.insert(elem);
					ret.push_back(elem);

					end--;
					while (first < end && *end == *(end+1)) {
						std::cout << "end--" << std::endl;
						end--;
					}

					first++;
					while (first < end && *first == *(first-1))  {
						std::cout << "first++" << std::endl;
						first++;
					}

				} else if (value > 0) {

					end--;
				} else {

					first++;
				}
			}
		}

		//for (set<vector<int>>::iterator it = set_ret.begin(); it != set_ret.end(); ++it)
		//	ret.push_back(*it);

		return ret;

    }

	/*
	class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return []

        nums.sort()
        res = set()

        for i, v in enumerate(nums[:-2]):
            if i >= 1 and v == nums[i-1]:
                continue
            
            d = {}
            for x in nums[i+1:]:
                if x not in d:
                    d[-v-x] = 1
                else:
                    res.add((v, -v-x, x))

        return map(list, res)
	*/

    vector<vector<int>> threeSum_2(vector<int>& nums) {
		vector<vector<int>> ret;
		
		set<vector<int>> set_ret;
		
		if (nums.size() < 3)
			return ret;

		std::cout << "what1" << std::endl;

		sort(nums.begin(), nums.end());

		for (size_t i = 0; i < nums.size() - 2; ++i) {
			set<int> check_i;

			std::cout << "what2" << std::endl;

			if (i >= 1 && nums[i] == nums[i-1]) {
				std::cout << "what2.5" << std::endl;
				continue;
			}

			for (size_t j = i+1; j < nums.size(); ++j)	{

				int value = 0 - nums[i] -  nums[j];
				auto search = check_i.find(nums[j]);
				if (search != check_i.end()) {
					std::cout << "what3" << std::endl;

					vector<int> r;
					r.push_back(nums[i]);			
					r.push_back(nums[j]);			
					r.push_back(value);			

					set_ret.insert(r);

					std::cout << "what3.5: erase: " << value << " set size: " << check_i.size() << std::endl;


				} else {

					check_i.insert(value);	
					std::cout << "what4: insert: " << value <<  " set size: " << check_i.size() << std::endl;
				}
			
			} // for j
		} // for i

		set<vector<int>>::iterator pos = set_ret.begin();

		for (; pos != set_ret.end(); ++pos)
			ret.push_back(*pos);

		return ret;
	}
    
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		//set<vector<int>> set_ret;

		if (nums.size() < 3)
			return ret;

		sort(nums.begin(), nums.end());

		for (size_t i = 0; i < nums.size() - 2; ++i) {
			int start = i + 1;
			int end = nums.size() - 1;

			int value; 

			//this two while loop is used to skip the duplication solution
			if (i >= 1 && nums[i] == nums[i-1]) {
				std::cout << "what2.5" << std::endl;
				continue;
			}

			while(start < end) {
				std::cout << "i: " << i << " start: " << start << " end: " << end << std::endl;
				value = nums[i] + nums[start] + nums[end]; 
				std::cout << "nums[i]: " << nums[i] << " nums[start]: " << nums[start] << " nums[end]: " << nums[end] << " value: " << value << std::endl;

				if (value > 0) {
					--end;
				} else if (value < 0) {
					++start;	
				} else {
					vector<int> r;
					r.push_back(nums[i]);			
					r.push_back(nums[start]);			
					r.push_back(nums[end]);			

					//set_ret.insert(r);
					ret.push_back(r);

					++start;
					--end;

					//this two while loop is used to skip the duplication solution
					while (start < end && nums[start-1] == nums[start])
						++start;

					while (start < end && nums[end+1] == nums[end])
						--end;

				} // if 

			} // while

		} // for

		/*
		set<vector<int>>::iterator pos = set_ret.begin();

		for (; pos != set_ret.end(); ++pos)
			ret.push_back(*pos);
		*/

		return ret;
	}
};

int main() {
	//vector<int> nums = {-2, -9, 11, 15};
	//vector<int> nums = {2, 11};
	//vector<int> nums = {-1, 0, 1, 2, -1, -4};
	//vector<int> nums = {14,4,6,-1,10,9,-8,7,-13,14,-13,-11,-8,-9,11,14,-8,-14,-13,7,-10,-15,-13,-11,-11,11,14,13,2,-14,1,-7,-2,14,-1,-15,9,7,-1,3,6,1,7,5,-1,-5,4,-2,-4,-1,-9,-7,-1,-7,-11,3,12,10,-7,-1,12,1,8,-13,1,14,9,-13,6,-7,-3,-11,2,-11,10,-14,-1,-9,0,2,5,6,3,-11,6,7,0,3,3,0,-12,-8,-13,3,-14,-5,2,10,-11,-14,-12,1,-10,5,5,7,-1,11,14,6,-10,-4,-3,8,-7,10,1,8,-1,-11,-15,-6,-12,-13,12,-11};
	//vector<int> nums = {0, 0, 0};
	//vector<int> nums = {-2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0};
	//vector<int> nums = {0, 0, 0, 0};
	vector<int> nums = {-2, 0, 1, 1, 2};
	//vector<int> nums = {-2, 0, 0, 2, 2};
	//vector<int> nums = {0, 0, 0, 0};

	Solution *obj = new Solution();
	vector<vector<int>> ret =  obj->threeSum(nums);

	if (!ret.empty()) {
		for (vector<vector<int>>::iterator pos = ret.begin(); pos != ret.end(); pos++) {
			for (vector<int>::iterator ppos = (*pos).begin(); ppos != (*pos).end(); ppos++)
				std::cout << *ppos << " "; 

			std::cout << std::endl; 
		}
	}

	return 0;
}
