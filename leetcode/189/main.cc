#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1)
            return;

        int len = nums.size();
        vector<int> tmp;
        tmp.resize(len);

        for (int i = 0; i < len; ++i) {
            //tmp[i]  = nums[(i+(len-k))%len];
            tmp[(i+k)%len]  = nums[i];
        }
    

        nums.assign(tmp.begin(), tmp.end());
        for (auto & item : tmp) {
            std::cout << "what0: " << item << std::endl;
        }

    }
};

int main() {
    //vector<int> nums = {1,2,3,4,5,6,7};
    //int k = 3;
    vector<int> nums = {1,2};
    int k = 3;

    Solution *test = new Solution();
    test->rotate(nums, k);

    for (auto & item : nums) {
        std::cout << "ret: " << item << std::endl;
    }

    return 0;
}