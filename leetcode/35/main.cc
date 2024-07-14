#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int begin = 0;
        int end = len - 1;

        while (begin < end) {
            int index = (end + begin) / 2;

            if (nums[index] == target) {
                return index;
            } else if (nums[index] > target) {
                end = index - 1;
            } else {
                begin = index + 1;
            }
        }

        //std::cout << "begin: " << begin << " end: " << end << endl;
        return  target > nums[begin] ? begin + 1: begin;
    }
};

int main() {
    //vector<int> nums = {1,3,5,6};
    //int target = 5;
    vector<int> nums = {1,3,5,6};
    int target = 2;
    Solution *test = new Solution();

    std::cout << test->searchInsert(nums, target) << std::endl;

    return 0;
}