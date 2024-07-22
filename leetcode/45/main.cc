#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;

        int right = 0;
        int end = 0;
        for (int i = 0; i < nums.size()-1; ++i) {

            if (right >= i) {
                right = std::max(right, i + nums[i]);
                if (i == end) {
                    end = right;
                    ret++;
                }
            }

            std::cout << "what i:" << i << " right: " << right  << " ret: " << ret << std::endl;

        }

        return ret;   
    }
};

int main() {
    //vector<int> nums = {2,3,1,1,4};
    //vector<int> nums = {2,3,0,1,4};
    //vector<int> nums = {4,1,1,3,1,1,1};
    vector<int> nums = {2,0,2,0,1};

    Solution *test = new Solution();
    std::cout << test->jump(nums) << std::endl;
    return 0;
}