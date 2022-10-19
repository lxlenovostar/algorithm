#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int index = -1;
        std::map<int , int> mp_left;
        int pre = 0;
        // 这一行很关键
        mp_left[0] = -1;
        for (int i = 0; i <= nums.size() - 1; ++i) {
            pre += nums[i];
            std::cout << "left pre: " << pre << std::endl;
            if (mp_left.find(pre) == mp_left.end()) {
                mp_left[pre] = i;
            }
            std::cout << "left pre: " << pre << " mp_left[pre]: " << mp_left[pre] << std::endl;
        }
 
        pre = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            pre += nums[i];
            std::cout << "right pre: " << pre << " i: " << i <<  std::endl;
            if (mp_left.find(pre) != mp_left.end() && (i-2) == mp_left[pre]) {
                std::cout << "find: " << pre << std::endl;
                index = i - 1;
                break;
            }
        }

        return index; 
    }
};

int main()
{
    vector<int> nums = {-1, -1, 0, -1, -1, 0}; 
    //vector<int> nums = {1, 7, 3, 6, 5, 6}; 
    //vector<int> nums = {1, 2, 1}; 

    Solution *test = new Solution;
    std::cout << test->pivotIndex(nums) << std::endl;

    return 0;
}