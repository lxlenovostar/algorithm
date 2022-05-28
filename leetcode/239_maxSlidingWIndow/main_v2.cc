#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
class Solution {
	public:
	/*
		struct Status {
        int val;
        struct ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

	*/
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return nums;

    	std::priority_queue<std::pair<int, int>> q;
		std::vector<int> ret;

		for (int i = 0; i < k; ++i) {
			q.push(std::make_pair(nums[i], i));
		}

		ret.emplace_back(q.top().first);
		for (int i = k; i < nums.size(); ++i) {
			q.push(std::make_pair(nums[i], i));

			while (q.top().second < (i-k+1)) {
				q.pop();
			}
			ret.emplace_back(q.top().first);
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

