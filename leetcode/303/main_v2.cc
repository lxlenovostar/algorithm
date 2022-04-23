#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        pre_sum.resize(nums.size()+1);

        for (size_t i = 1; i <= nums.size(); ++i) {
            pre_sum[i] = pre_sum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return pre_sum[right+1] - pre_sum[left];
    }
private:
    vector<int> pre_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    int ret = obj->sumRange(0, 2);
    std::cout << ret << std::endl;

    ret = obj->sumRange(2, 5);
    std::cout << ret << std::endl;

    ret = obj->sumRange(0, 5);
    std::cout << ret << std::endl;

    return 0;
}