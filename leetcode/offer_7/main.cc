#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 */ 
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
private:
    TreeNode* NewTree(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
        int pre_root = pre_start;

        if (in_start > in_end || pre_start > pre_end)
            return nullptr;

        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[pre_root]];

        int distance = inorder_root - in_start; 
        TreeNode *node = new TreeNode(preorder[pre_root]);
        node->left = NewTree(preorder, inorder, pre_start+1, pre_start+distance, in_start, in_start+distance-1);
        node->right = NewTree(preorder, inorder, pre_start+distance+1, pre_end, in_start+distance+1, in_end);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }

        return NewTree(preorder, inorder, 0, n-1, 0, n-1);
    }
private:
    std::unordered_map<int ,int> index;
};

int main() 
{
    vector<int> preorder = {3,9,20,15,7}; 
    vector<int> inorder = {9,3,15,20,7};

    Solution *test = new Solution();
    test->buildTree(preorder, inorder);
    return 0;
}
