#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        ret.resize(nums.size(), 1);
        vector<int> left;
        left.resize(nums.size(), 1);
        vector<int> right;
        right.resize(nums.size(), 1);

        for (int i  = 1; i < nums.size(); ++i) {
            left[i] = left[i-1] * nums[i-1];
            //std::cout << "what i:" << i << " left: " << left[i] << std::endl;
        }

        for (int i = nums.size() - 2; i >= 0; --i) {
            right[i] = right[i+1] * nums[i+1];
            //std::cout << "what right i:" << i << " right: " << right[i] << std::endl;
        }

        for (int i  = 0; i <= nums.size()-1; ++i) {
            ret[i] = left[i] * right[i];
        }

        return ret;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};

    Solution *test = new Solution();
    for (auto item: test->productExceptSelf(nums)) {
        std::cout << item << std::endl;
    }

    return 0;
}