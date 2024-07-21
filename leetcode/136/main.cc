#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;

        for (auto item: nums) {
            ret ^= item;
        }

        return ret;
    }
};

int main() {
    //vector<int> nums = {2,2,1};
    vector<int> nums = {1};

    Solution *test = new Solution();
    std::cout << test->singleNumber(nums) << std::endl;
}