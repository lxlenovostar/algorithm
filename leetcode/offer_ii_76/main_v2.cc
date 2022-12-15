#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /* 时间复杂度算法导论9.2 */
    inline int randomPartition(vector<int>& nums, int left, int right) {
        /*随机选择*/
        int i = rand() % (right - left + 1) + left;
        swap(nums[i], nums[right]);
        return partition(nums, left, right);
    }

    int partition(vector<int>& nums, int left, int right) {
    }

    int quickSortFind(vector<int>& nums, int left, int right, int slot) {
        /* 分治的点  */
        int index = randomPartition(nums, left, right);

        if (index == slot) {
            return nums[index];
        } else if (index < slot) {
            return quickSortFind(nums, index+1, right, slot);
        } else {
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