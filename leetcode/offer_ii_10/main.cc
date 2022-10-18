#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        for (int i = 0; i <= nums.size() - 1; ++i) {
            int sum = 0;
            for (int j = i; j >= 0; --j) {
                sum += nums[j];

                if (sum == k)
                    ret++;

            }
        }

        return ret;
    }
};

int main()
{
    vector<int> nums = {1,2,3}; 
    int k = 3;

    Solution *test = new Solution;
    std::cout << test->subarraySum(nums, k) << std::endl;

    return 0;
}