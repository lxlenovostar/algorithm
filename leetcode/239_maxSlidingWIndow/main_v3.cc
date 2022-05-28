#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
class Solution {
	public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return nums;

		std::vector<int> ret;
		std::deque<int> windows;

		for (int i = 0; i < k; ++i) {
			while (!windows.empty() && nums[i] >= nums[windows.back()]) {
                windows.pop_back();
            }
			windows.push_back(i);
		}	

		ret.emplace_back(nums[windows.front()]);
		
		for (int i = k; i < nums.size(); ++i) {
			if (!windows.empty() && windows.front() < (i-k+1)) {
				windows.pop_front();
			}

			while (!windows.empty() && nums[i] >= nums[windows.back()]) {
                windows.pop_back();
            }
			
			windows.push_back(i);
		
			ret.emplace_back(nums[windows.front()]);
		
		}
		
		return ret;
	}

};

int  main() {
	int k = 3;
	std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
	//std::vector<int> nums = {1,3,1,2,0,5};
	//int k = 0;
	//std::vector<int> nums;
 	Solution* obj = new Solution();
	std::vector<int> ret = obj->maxSlidingWindow(nums, k);
	for (const auto & item: ret) {
		std::cout << item << std::endl;
	}

	return 0;	
}

