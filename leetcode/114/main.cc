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
    void flatten(TreeNode* root) {
        vector<TreeNode*> handle_queue;
        helper(root, handle_queue);

        if (handle_queue.size() <= 1) 
            return;

        for (size_t i = 0; i < handle_queue.size()-1; ++i) {
            handle_queue[i]->left = nullptr;
            handle_queue[i]->right = handle_queue[i+1];
        }
        handle_queue[handle_queue.size()-1]->left = nullptr;
        handle_queue[handle_queue.size()-1]->right = nullptr;

        return;
    }
private:
    void helper(TreeNode* root, vector<TreeNode*> & handle_queue) {
        if (root == nullptr)
            return;
        
        handle_queue.push_back(root);
        helper(root->left, handle_queue);
        helper(root->right, handle_queue);
    }
};

int main() {
    struct  TreeNode *a1 = new TreeNode(1);
    struct  TreeNode *a2 = new TreeNode(2);
    struct  TreeNode *a3 = new TreeNode(3);
    struct  TreeNode *a4 = new TreeNode(4);
    struct  TreeNode *a5 = new TreeNode(5);
    struct  TreeNode *a6 = new TreeNode(6);

    a1->left = a2;
    a1->right = a5;
    a5->right = a6;
    a2->left = a3;
    a2->right = a4;

    Solution *test = new Solution();
    test->flatten(a1);
    
    return 0;
}