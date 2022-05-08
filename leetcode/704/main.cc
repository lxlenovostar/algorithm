#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid+1;
            } else if (nums[mid] > target) {
                right = mid-1;
            }
        }

        return -1;
    }
};

int main() {
    //vector<int> nums = {-1,0,3,5,9,12};
    vector<int> nums = {5};
    int target = 5;
    Solution *test = new Solution();
    std::cout << test->search(nums, target) << std::endl;
    return 0;
}