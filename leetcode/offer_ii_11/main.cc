#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_len = 0;
        std::map<int , int> mp;
        int pre = 0;
        // 这一行很关键
        mp[0] = -1;
        for (int i = 0; i <= nums.size() - 1; ++i) {
            pre += nums[i] == 0 ? -1 : 1;
            std::cout << "pre: " << pre << std::endl;
            if (mp.find(pre) != mp.end()) {
                max_len = std::max(max_len, i - mp[pre]); 
                std::cout << "max_len: " << max_len << std::endl;
            } else {
                mp[pre] = i;
            }

            std::cout << "pre: " << pre << " mp[pre]: " << mp[pre] << std::endl;
        }

        return max_len; 
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 1}; 

    Solution *test = new Solution;
    std::cout << test->findMaxLength(nums) << std::endl;

    return 0;
}