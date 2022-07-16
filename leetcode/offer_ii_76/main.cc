#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    inline int randomPartition(vector<int>& nums, int left, int right) {
        int i = rand() % (right - left + 1) + left;
        swap(nums[i], nums[right]);
        return partition(nums, left, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int p1 = left - 1;
        int p = nums[right];
        for (int i = left; i < right; ++i) {
            if (nums[i] <= p) {
                swap(nums[++p1], nums[i]);
            }
        }
        swap(nums[p1+1], nums[right]);
        return p1+1;
    }

    int quickSortFind(vector<int>& nums, int left, int right, int slot) {
        int index = randomPartition(nums, left, right);

        if (index == slot) {
            return nums[index];
        } else if (index < slot) {
            //std::cout << "right index: " << index << " slot:" << slot << std::endl;
            //std::cout << "right index+1: " << index+1 << " right:" << right << std::endl;
            return quickSortFind(nums, index+1, right, slot);
        } else {
            //std::cout << "left index: " << index << " slot:" << slot << std::endl;
            //std::cout << "left left: " << left << " index-1:" << index-1 << std::endl;
            return quickSortFind(nums, left, index-1, slot);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = n-k;
        srand(time(0));

        return quickSortFind(nums, 0, n-1, ret);
    }
};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    Solution *test = new Solution();
    std::cout << test->findKthLargest(nums, 2);

    return 0;
}