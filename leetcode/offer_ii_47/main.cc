#include <iostream>
#include <queue>

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
private:
    bool dfs(TreeNode* root) {
        if (root != nullptr) {
            bool left_ret = dfs(root->left);
            bool right_ret = dfs(root->right);

            if (!left_ret)
                root->left = nullptr;

            if (!right_ret)
                root->right = nullptr;
            
            bool ret = root->val ? true : false; 
            return ret || left_ret || right_ret;
        }
        return false;
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        return dfs(root) ? root : nullptr;
    }
};

int main()
{
    struct TreeNode *node1 = new struct TreeNode(1);
    struct TreeNode *node2 = new struct TreeNode(0);
    struct TreeNode *node3 = new struct TreeNode(1);
    struct TreeNode *node4 = new struct TreeNode(0);
    struct TreeNode *node5 = new struct TreeNode(0);
    struct TreeNode *node6 = new struct TreeNode(0);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;

    Solution* test = new Solution();
    test->pruneTree(node1);

    return 0;
}
