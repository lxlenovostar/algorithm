#include <queue>
#include <iostream>

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        return helper(root->left, root->right);    
    }
private:
    bool helper(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr)
            return true;
        
        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }
        
        return (node1->val == node2->val) && helper(node1->left, node2->right) && helper(node1->right, node2->left);
    }
};

int main() {
    struct TreeNode *a1 = new TreeNode(1);
    struct TreeNode *a21 = new TreeNode(2);
    struct TreeNode *a22 = new TreeNode(2);
    struct TreeNode *a31 = new TreeNode(3);
    struct TreeNode *a32 = new TreeNode(4);
    struct TreeNode *a33 = new TreeNode(4);
    struct TreeNode *a34 = new TreeNode(3);

    a1->left = a21;
    a1->right = a22;
    a21->left = a31;
    a21->right = a32;
    a22->left = a33;
    a22->right = a34;
    /*
    struct TreeNode *a31 = new TreeNode(2);
    struct TreeNode *a32 = new TreeNode(2);

    a1->left = a21;
    a1->right = a22;
    a21->left = a31;
    a22->left = a32;
    */

    Solution *test = new Solution();
    std::cout << "ret: " << test->isSymmetric(a1) << std::endl;
    return 0;
}