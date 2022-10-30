#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target, bool equal) {
        int left = 0;
        int right = nums.size() - 1;
        int ret = (int)nums.size();

        while (left <= right) {
            int mid = (left + right) >> 1;

            if (nums[mid] > target || (equal && nums[mid] >= target)) {
                right = mid - 1;
                ret = mid;
            } else {
                left = mid + 1;
            }
        }

        return ret;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // 开始位置就是相等的位置， 结束位置就是第一个大于target的位置
        int left = search(nums, target, true);
        int right = search(nums, target, false) - 1;

        if (left <= right && right <= nums.size() -1 && nums[left] == target && nums[right] == target) {
            return vector<int>{left, right};
        }

        return vector<int>{-1, -1};
    }
};

int main() {
    //vector<int> nums = {-1,0,3,5,9,12};
    vector<int> nums = {1};
    //vector<int> nums = {5,7,7,8,8,10};
    int target = 1;
    Solution *test = new Solution();
    const std::vector<int> & ret = test->searchRange(nums, target);
    for (const auto & index: ret) {
        std::cout << index << std::endl;
    }
    return 0;
}