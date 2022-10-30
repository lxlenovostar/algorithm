#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = nums[nums.size() - 1];

        int left = 0;
        int right = nums.size()/2;

        while (left <= right) {
            int mid = (left + right) >> 1;
            int i = mid * 2;

            std::cout << "left: " << left << " right: " << right << " mid: " << mid << " i: " << i << std::endl;

            if (i < nums.size() -1 && nums[i] != nums[i+1])  {
                if (i == 0 || i-1 >= 0 && i - 2 >= 0 && nums[i-1]  == nums[i-2]) {
                    return nums[i]; 
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ret;
    }
};

int main() {
    //vector<int> nums = {1, 2, 2, 3, 3};
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    Solution *test = new Solution();
    std::cout << test->singleNonDuplicate(nums) << std::endl;

    return 0;
}

