#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }
};

int main() {
    //vector<int> nums = {3,2,2,3};
    vector<int> nums = {0,1,2,2,3,0,4,2}; 
    int val = 2;
    Solution *test = new Solution(); 
    std::cout << test->removeElement(nums, val) << std::endl;
    return 0;
}