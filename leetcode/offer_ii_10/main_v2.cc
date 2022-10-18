#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        std::map<int , int> mp;
        int pre = 0;
        // 这一行很关键
        mp[0] = 1;
        for (int i = 0; i <= nums.size() - 1; ++i) {
            pre += nums[i];
            std::cout << "pre: " << pre << std::endl;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre-k];
                std::cout << "cout: " << count << std::endl;
            }
            mp[pre] += 1;
            std::cout << "pre: " << pre << " mp[pre]: " << mp[pre] << std::endl;
        }

        return count; 
    }
};

int main()
{
    vector<int> nums = {0}; 
    int k = 0;

    Solution *test = new Solution;
    std::cout << test->subarraySum(nums, k) << std::endl;

    return 0;
}