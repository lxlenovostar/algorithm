#include <set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0; 
        int ret = 0;
        int product = 1;

        for (int right = 0; right <= nums.size() - 1; right++) {
            product *= nums[right];

            while (product >= k && left <= right) {
                product /= nums[left];
                left++;
            }

            //std::cout << "ret: " << ret << " right: " << right << " left: " << left << std::endl;
            ret += right >= left ? (right - left + 1) : 0;
        }

        return ret;
    }
};

int main() {
    vector<int> nums = {100, 10}; 
    int k = 100;

    Solution *test = new Solution();
    int val = test->numSubarrayProductLessThanK(nums, k);
    std::cout << val << std::endl;
    return 0;
}