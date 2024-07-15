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
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_len;
    }
private:
    int dfs(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int left_len = dfs(node->left);
        int right_len = dfs(node->right);

        if (left_len + right_len > max_len) 
            max_len = left_len + right_len;

        return std::max(left_len, right_len) + 1;
    }
private:
    int max_len;
};

int main() {
    struct TreeNode *a1 = new TreeNode(1);
    struct TreeNode *a2 = new TreeNode(2);
    struct TreeNode *a3 = new TreeNode(3);
    struct TreeNode *a4 = new TreeNode(4);
    struct TreeNode *a5 = new TreeNode(5);

    a1->left = a2;
    a1->right = a3;
    a2->left = a4;
    a2->right = a5;

    Solution *test = new Solution();
    std::cout << test->diameterOfBinaryTree(a1) << std::endl;

    return 0;
}