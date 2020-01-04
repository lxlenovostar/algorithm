/*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

		sort(nums.begin(), nums.end());

		int max_val = 0;
		int val = nums[0];
		int max_count = 0; 
		int current_count = 0;
		for (size_t i = 0; i < nums.size(); i++) {
			if (val == nums[i]) {
				current_count++;
			} else {
				current_count = 1;
				val = nums[i];
			}
			
			if (current_count > max_count) {
				max_val = val;
				max_count = current_count;
			}
			
		}

		return max_val;
    }

	int countInRange(vector<int>& nums, int num, int lo, int hi) {
		int count = 0;

		for (int i = lo; i <= hi; ++i) {
			if (nums[i] == num)
				count++;
		}

		return count;
	}

	int helper(vector<int>& nums, int lo, int hi) {
        // base case; the only element in an array of size 1 is the majority
        // element.
        if (lo == hi) {
			std::cout << "lo == hi: " << nums[lo] <<  " lo: " << lo << " hi: " << hi << std::endl;
            return nums[lo];
        }

        // recurse on left and right halves of this slice.
        int mid = (hi-lo)/2 + lo;
		std::cout << "lo: " << lo << " mid: " << mid << " hi: " << hi << std::endl;
		std::cout << "begin left" <<  " lo: " << lo << " hi: " << mid << std::endl;
        int left = helper(nums, lo, mid);
		std::cout << "begin right" <<  " lo: " << (mid+1) << " hi: " << hi << std::endl;
        int right = helper(nums, mid+1, hi);

        // if the two halves agree on the majority element, return it.
        if (left == right) {
            return left;
        }

        // otherwise, count each element and return the "winner".
        int leftCount = countInRange(nums, left, lo, hi);
        int rightCount = countInRange(nums, right, lo, hi);

        int ret = leftCount > rightCount ? left : right;
		std::cout << "ret: " << ret << " leftCount: " << leftCount << " rightCount: " << rightCount << " lo: " << lo << " hi: " << hi << std::endl;
		return ret;
    }


    
	int majorityElement_1(vector<int>& nums) {
		return helper(nums, 0, nums.size()-1);
	}
};

int main() {
	Solution *obj = new Solution();
	//vector<int> nums = {2,2,1,1,1,2,2};
	vector<int> nums = {8,9,8,9,8};
	std::cout << obj->majorityElement_1(nums) << std::endl;

}
