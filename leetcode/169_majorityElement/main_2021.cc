#include <iostream>
#include <vector>

using namespace std;

class Solution {

	public:
		int majorityElement(vector<int>& nums) {

			return helper(nums, 0, nums.size()-1);		

		}

	private:
		 int count_in_range(vector<int>& nums, int target, int lo, int hi) {
			int count = 0;
		    for (int i = lo; i <= hi; ++i)
		    	if (nums[i] == target)
			     	++count;
			return count;
		}

		int helper(vector<int>& nums, unsigned begin_pos, unsigned end_pos) {
			if (begin_pos == end_pos) {
				std::cout << "begin_pos: " << begin_pos << std::endl;
				return nums[begin_pos];
			} 

        	//int mid = (end_pos - begin_pos)/2 + begin_pos;
        	int mid = (end_pos + begin_pos)/2;
			std::cout << "left begin_pos: " << begin_pos << " end_pos:" << mid << std::endl;
			int left_value = helper(nums, begin_pos, mid);
			std::cout << "right begin_pos: " << mid+1 << " end_pos:" << end_pos << std::endl;
			int right_value = helper(nums, mid+1, end_pos);

			if (count_in_range(nums, left_value, begin_pos, end_pos) > (end_pos - begin_pos + 1) / 2)
				return left_value;
			if (count_in_range(nums, right_value, begin_pos, end_pos) > (end_pos - begin_pos+ 1) / 2)
				return right_value;
			return -1;

		}
};

int main() {
	Solution *obj = new Solution();
	vector<int> nums = {2,2,1,1,1,2,2};
	//vector<int> nums = {8,9,8,9,8};
	std::cout << obj->majorityElement(nums) << std::endl;
		
	return 0;
}

