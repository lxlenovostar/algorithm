#include <iostream>
#include <queue>
#include <string>
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
private:
    long dfs(TreeNode* root, long target) {
        if (root == nullptr) {
            return 0;
        } 

        long ret = 0;

        if (target == root->val)
            ret = 1;
        
        ret += dfs(root->left, target - root->val);
        ret += dfs(root->right, target - root->val);

        return ret;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return 0;
        
        int ret = dfs(root, targetSum); 

        return ret + pathSum(root->left, targetSum) + pathSum(root->right, targetSum); 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    struct TreeNode *node1 = new struct TreeNode(10);
    struct TreeNode *node2 = new struct TreeNode(5);
    struct TreeNode *node3 = new struct TreeNode(-3);
    struct TreeNode *node4 = new struct TreeNode(3);
    struct TreeNode *node5 = new struct TreeNode(2);
    struct TreeNode *node6 = new struct TreeNode(11);
    struct TreeNode *node7 = new struct TreeNode(3);
    struct TreeNode *node8 = new struct TreeNode(-2);
    struct TreeNode *node9 = new struct TreeNode(1);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;
    node4->left = node7;
    node4->right = node8;
    node5->right = node9;
    /*
    node3->left = node4;
    node3->right = node5;
    node4->left = node6;
    node4->right = node7;
    */
    

    Solution *test = new Solution(); 
    std::cout << test->pathSum(node1, 8) << std::endl;

    return 0;
}
