#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow_e_0 = 0;
        int fast_n_0 = 0;

        while(fast_n_0 < nums.size()) {
            if (nums[fast_n_0] != 0) {
                std::swap(nums[slow_e_0], nums[fast_n_0]);
                slow_e_0++;
            }
            fast_n_0++;
        }

        return;
    }
};

int main() {
    //vector<int> nums = {3,2,2,3};
    vector<int> nums = {0,1,0,3,12}; 
    Solution *test = new Solution(); 
    test->moveZeroes(nums);
    for (const auto & item : nums) {
        std::cout << item << std::endl;
    }
    return 0;
}