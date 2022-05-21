#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;

        if (nums.size() == 1)
            return ret;

        for (size_t i = 0; i < nums.size(); ++i) {
            while (nums[i] != nums[nums[i]-1]) {
                std::swap(nums[i], nums[nums[i]-1]);
            }

            /*
            std::cout << i << ": ";
            for (const auto& item : nums) {
                std::cout << item << " ";
            }
            std::cout << std::endl;
            */
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != (i+1)) {
                ret.emplace_back(nums[i]);
            }
        }

        return ret;
    }
};

int main() {
    vector<int> nums = {8, 7, 6, 5, 4, 3, 2, 1};
    //vector<int> nums = {1, 1, 2};
    //输出：[2,3]
    Solution *test = new Solution();
    for (const auto& item : test->findDuplicates(nums)) {
        std::cout << item << std::endl;
    }
    return 0;
}