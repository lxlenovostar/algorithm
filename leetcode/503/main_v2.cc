#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::vector<int> ret;    
        ret.resize(nums.size(), -1);
        std::stack<int> bigger_one;
        int len = nums.size();

        for (int i = 0; i <= 2*len - 1; ++i) {
            while (!bigger_one.empty() && nums[bigger_one.top()] < nums[i%len]) {
                ret[bigger_one.top()] = nums[i%len];
                bigger_one.pop();
            }

            bigger_one.push(i%len);
        }

        return ret;
    }
};

int main()
{
    //vector<int >nums1 = {4,1,2};
    //vector<int >nums1 = {2,4};
    //vector<int >nums1 = {1,3,5,2,4};
    //vector<int> nums2 = {1,3,4,2};
    //vector<int> nums2 = {6,5,4,3,2,1,7};
    //vector<int> nums = {1,2,3,4};
    //vector<int> nums = {1,2,1};
    vector<int> nums = {100,1,11,1,120,111,123,1,-1,-100};
    Solution *test = new Solution();

    for (const auto & item : test->nextGreaterElements(nums)) {
        std::cout << item << std::endl;
    }

    return 0;
}