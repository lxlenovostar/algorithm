#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int right = nums[0];

        for (int i = 0; i <= right; ++i) {
            right = std::max(right, nums[i] + i);
            if (right >= len - 1)
                return true;
        }

        return false;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution *test = new Solution();

    std::cout << test->canJump(nums) << std::endl;
    return 0;
}