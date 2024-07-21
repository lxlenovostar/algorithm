#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // 从后向前找升序 i, j
        int i = nums.size()-2;
        int j = nums.size()-1;
        while (i >= 0 && nums[i] >= nums[j]) {
            i--;
            j--;
        }
        //std::cout << "what0 i:" << i << " j: " << j << std::endl;

        // 在j,end 找到第一个 nums[k] > nums[i]， 并swap
        int k = nums.size()-1;
        if (i >= 0) {
        for (int index = nums.size() -1; index >= j; --index) {
            if (nums[index] > nums[i]) {
                k = index;
                break;
            }
        } 
            std::swap(nums[i], nums[k]);
        }
        //std::cout << "what1 k:" << k << std::endl;

        // 逆序 j, end
        int begin = j;
        int end = nums.size() - 1;
        while (begin < end) {
            swap(nums[begin], nums[end]);
            begin++;
            end--;
        }

    }
};

int main() {
    //vector<int> nums = {1,2,3};
    //vector<int> nums = {1,5,1};
    vector<int> nums = {1,1,5};
    //vector<int> nums = {1, 2, 3, 8, 5, 7, 6, 4};
    //vector<int> nums = {3, 2, 1};
    Solution *test = new Solution();
    test->nextPermutation(nums);

    for (auto item : nums) {
        std::cout << item << std::endl;
    }

    return 0;    
}