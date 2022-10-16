#include <iostream>
#include <vector>
#include <algorithm>?

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 0;

        while (right <= nums.size() - 1) {
            if (nums[left] != nums[right]) {
                nums[++left] = nums[right];
            }
            right++;
        }

        return left+1;
    }
};

int main() 
{
    //vector<int> nums = {0,0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    //vector<int> nums = {1,1,2};
    vector<int> nums = {1};

    Solution *test = new Solution();
    std::cout << test->removeDuplicates(nums) << std::endl;
    for (const auto & item: nums)
        std::cout << item << std::endl;
}