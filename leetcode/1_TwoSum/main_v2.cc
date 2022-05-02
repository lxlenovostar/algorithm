#include <iostream>
#include <vector>
#include <map>
using namespace std;
    
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::map<int, int> dict;
        
        for (int i = 0; i < nums.size(); ++i) {
           int key = target - nums[i];
           auto iter = dict.find(key);
           if (iter != dict.end()) {
               return {i, iter->second};
           } 
           dict[nums[i]] = i;
        }

        return {};
    }
};

int main() {

    vector<int> nums = {3,2,4};
    int target = 6;

    Solution *test = new Solution();
    const vector<int> &ret = test->twoSum(nums, target);
    for (const auto & item : ret) {
        std::cout << item << std::endl;
    }

}