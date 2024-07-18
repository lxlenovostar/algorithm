#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
private:
    TreeNode* helper(vector<int>&nums, int begin, int end)
    {
        if (begin > end) {
            return nullptr;
        }

        int mid = (begin + end)/2;
        TreeNode *node = new struct TreeNode(nums[mid]);
        node->left = helper(nums, begin, mid-1);
        node->right = helper(nums, mid+1, end);

       return node; 
    }
};

int main() {
    vector<int> nums = {-10,-3,0,5,9};

    Solution *test = new Solution();
    std::cout << test->sortedArrayToBST(nums) << std::endl;
    return 0;
}

