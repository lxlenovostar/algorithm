#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //size_t nums_len = nums.size()  + 1;
        //pre_sum.resize(nums_len);

        /*
        for (size_t i = 1; i < nums_len; ++i) {
            pre_sum[i] = pre_sum[i-1] + nums[i-1];
        }

        int count = 0;
        map<int, int> dict_sum;

        for (size_t i = 1; i < nums_len; ++i) {
            for (size_t j = 0; j < i; ++j) {
                // ⼦数组 nums[j..i-1] 的元素和
                if (pre_sum[i] - pre_sum[j] == k)
                    count++;
            }
        }
        */

        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;

    }
private:
    vector<int> pre_sum;
};

int main()
{
    vector<int> nums = {1,2,3}; 
    int k = 3;

    Solution *test = new Solution();
    std::cout << test->subarraySum(nums, k) << std::endl;
    return 0;
}