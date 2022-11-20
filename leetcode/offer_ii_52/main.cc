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
    void dfs(TreeNode* root, std::queue<TreeNode*> &q) {
        if (root == nullptr) {
            return ;
        } 
        dfs(root->left, q);
        TreeNode* right = root->right;
        root->left = root->right = nullptr;
        q.push(root);
        dfs(right, q);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        std::queue<TreeNode*> q;
        dfs(root, q);

        TreeNode dump_root;
        TreeNode *new_root = &dump_root;

        while (!q.empty()) {
            new_root->right = q.front();
            q.pop();
            new_root = new_root->right;
        }

        return dump_root.right;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    struct TreeNode *node1 = new struct TreeNode(4);
    struct TreeNode *node2 = new struct TreeNode(2);
    struct TreeNode *node3 = new struct TreeNode(5);
    struct TreeNode *node4 = new struct TreeNode(1);
    struct TreeNode *node5 = new struct TreeNode(3);
    struct TreeNode *node6 = new struct TreeNode(6);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;
    /*
    node3->left = node4;
    node3->right = node5;
    node4->left = node6;
    node4->right = node7;
    */
    

    Solution *test = new Solution(); 
    test->increasingBST(node1);

    return 0;
}
