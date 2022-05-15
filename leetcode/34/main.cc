#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int left_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid-1;
            } else if (nums[mid] < target) {
                left = mid+1;
            } else if (nums[mid] > target) {
                right = mid-1;
            }
        }

        if (left >= nums.size() || nums[left] != target)
            return -1;
        
        return left;
    }
    
    int right_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid+1;
            } else if (nums[mid] < target) {
                left = mid+1;
            } else if (nums[mid] > target) {
                right = mid-1;
            }
        }

        if (right >= nums.size() || nums[right] != target)
            return -1;
        
        return right;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        return {left_bound(nums, target), right_bound(nums, target)};
    }
};

int main() {
    //vector<int> nums = {-1,0,3,5,9,12};
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Solution *test = new Solution();
    const std::vector<int> & ret = test->searchRange(nums, target);
    for (const auto & index: ret) {
        std::cout << index << std::endl;
    }
    return 0;
}