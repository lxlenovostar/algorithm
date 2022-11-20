#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <stack>

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr)
            return nullptr;

        TreeNode *cur = root;
        TreeNode *prev = nullptr;

        while (cur) {
            if (cur->val > p->val) {
                prev = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }

        return prev;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    struct TreeNode *node1 = new struct TreeNode(8);
    struct TreeNode *node2 = new struct TreeNode(6);
    struct TreeNode *node3 = new struct TreeNode(10);
    struct TreeNode *node4 = new struct TreeNode(5);
    struct TreeNode *node5 = new struct TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    /*
    node3->left = node4;
    node3->right = node5;
    node4->left = node6;
    node4->right = node7;
    */
    

    Solution *test = new Solution(); 
    std::cout << test->inorderSuccessor(node1, node5)->val << std::endl;

    return 0;
}
