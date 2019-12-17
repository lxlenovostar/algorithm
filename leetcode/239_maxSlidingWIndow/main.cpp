/*
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。



示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
解释:

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
*/

#include <iostream>
#include <queue>
#include <deque>
using namespace std;

class Solution {
public:
	/*
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			std::vector<int> ret;

			if (nums.size() <= 0)
				return ret;
	
			for (size_t i = 0; i < (nums.size() - k + 1); i++) {
    			//priority_queue<int, std::vector<int>, std::greater<int> > heap;
    			priority_queue<int> heap;
		
				for (int j = 0; j < k; j++) {
					heap.push(nums[j + i]);
				}		

				ret.push_back(heap.top());
			}

			return ret;
    }
	*/

	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			std::vector<int> ret;
			std::deque<int> de;

			if (nums.size() <= 0)
				return ret;

			for (int i = 0; i < k; i++) {
				if (!de.empty()) {
					if (nums[i] < de.front())
						de.push_back(nums[i]);
					else  {
						de.clear();
						de.push_back(nums[i]);
					}
				} else {
					de.push_back(nums[i]);
				}
			} 
			std::cout << "front:" << de.front() << std::endl;
			ret.push_back(de.front());
			
			for (size_t i = k; i < nums.size(); i++) {
				if (nums[i] > de.front()) {
					de.clear();
					de.push_back(nums[i]);
				} else {
					if (de.size() < k) {

						while (!de.empty() && nums[i] >= de.back()) {
							de.pop_back();
						}

						de.push_back(nums[i]);

					} else {
						// >= k
						de.pop_front();
						while (nums[i] >= de.back()) {
							de.pop_back();
						}
						de.push_back(nums[i]);
						
					} // < k
				
				}  // > de.front()

				std::cout << "front2:" << de.front() << std::endl;
				ret.push_back(de.front());
			}

			return ret;
    }



};


int main()
{
	int k = 3;
	//std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
	std::vector<int> nums = {1,3,1,2,0,5};
	//int k = 0;
	//std::vector<int> nums;
 	Solution* obj = new Solution();
	std::vector<int> ret = obj->maxSlidingWindow(nums, k);
	std::vector<int>::iterator pos;
	for ( pos = ret.begin(); pos != ret.end(); pos++) {
		std::cout << *pos << std::endl;
	}
	
	return 0;
}
