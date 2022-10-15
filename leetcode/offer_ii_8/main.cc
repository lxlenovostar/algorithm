#include <set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int begin = 0; 
        int end = 0;

        int ret = nums.size();
        bool find = false;
        int sum_val = nums[end];
        while (begin <= end && end <= nums.size() - 1) {
            //std::cout << "what" << " begin: " << begin << " end: " << end << " sum_val: " << sum_val << std::endl;
            if (sum_val >= target) {
                ret = std::min(ret, (end - begin + 1));
                find = true;
                sum_val -= nums[begin++];
                continue;
            }
            
            if (sum_val < target) {
                ++end;
                if (end >= nums.size()) {
                    break;
                } 
                sum_val += nums[end];
                continue;
            }

        }

        return find ? ret : 0;

    }
};

int main() {
    int target = 7; 
    //vector<int> numbers = {5,1,4,3};
    vector<int> numbers = {2,3,1,2,4,3};
    //vector<int> numbers = {1,1,1,1,1,1,1,1};

    Solution *test = new Solution();
    int val = test->minSubArrayLen(target, numbers);
    std::cout << val << std::endl;
    return 0;
}