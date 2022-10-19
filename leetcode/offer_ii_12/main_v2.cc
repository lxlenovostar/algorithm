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
        int sum = 0;


        for (int i = 0; i <= nums.size() - 1; ++i) {
            sum += nums[i];
        }
 
        pre = 0;
        for (int i = 0; i <= nums.size() - 1; ++i) {
            if (nums[i] == (sum - 2*pre)) {
                index = i;
                break;
            }
            pre += nums[i];
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