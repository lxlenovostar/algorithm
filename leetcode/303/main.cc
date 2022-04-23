#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums): m_array(nums) {
    }
    
    int sumRange(int left, int right) {
        if (left < 0 || right >= m_array.size())
            return 0;
        
        int ret = 0;
        for (int i = left; i <= right; ++i) {
            ret += m_array[i];
        }

        return ret;
    }
private:
    vector<int>& m_array;
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