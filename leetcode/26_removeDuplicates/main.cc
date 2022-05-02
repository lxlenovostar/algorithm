#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 0; 

        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {
                nums[slow+1] = nums[fast];
                slow++;           
            }
            fast++;
        }

        return (slow+1);
    }
};

int main() 
{
    vector<int> nums = {0,0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    Solution *test = new Solution();
    std::cout << test->removeDuplicates(nums) << std::endl;
    for (const auto & item: nums)
        std::cout << item << std::endl;
}